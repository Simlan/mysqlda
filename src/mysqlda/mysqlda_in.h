#ifndef _H_MYSQLDA_IN_
#define _H_MYSQLDA_IN_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <sys/epoll.h>
#include <sys/wait.h>
#include <dirent.h>

#include "LOGC.h"
#include "lk_list.h"
#include "rbtree.h"
#include "network.h"
#include "ctl_epoll.h"

#include "my_global.h"
#include "mysql.h"

#include "openssl/evp.h"
#include "openssl/sha.h"

#include "IDL_mysqlda_conf.dsc.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifndef LIKELY
#if __GNUC__ >= 3
#define LIKELY(x) __builtin_expect(!!(x), 1)
#define UNLIKELY(x) __builtin_expect(!!(x), 0)
#else
#define LIKELY(x) (x)
#define UNLIKELY(x) (x)
#endif
#endif

/* ͨѶ������Ϣ�ṹ */
struct NetAddress
{
	char			ip[ sizeof(((mysqlda_conf*)0)->forwards[0].forward[0].ip) + 1 ] ;
	int			port ;
	int			sock ;
	struct sockaddr_in	addr ;
} ;

/* �����Ự�ṹ */
struct ListenSession
{
	struct NetAddress	netaddr ;
} ;

#define SESSIONTYPE_ACCEPTEDSESSION	1 /* �ͻ������ӻỰ���� */
#define SESSIONTYPE_FORWARDSESSION	2 /* �����ת���Ự���� */

#define SESSIONSTATUS_BEFORE_SENDING_HANDSHAKE						1 /* ת������ͻ��˷���������Ϣǰ */
#define SESSIONSTATUS_AFTER_SENDING_HANDSHAKE_AND_BEFORE_RECEIVING_AUTHENTICATION	2 /* ת������ͻ��˷���������Ϣ�󣬽��տͻ�����֤��Ϣǰ */
#define SESSIONSTATUS_AFTER_SENDING_AUTH_FAIL_AND_BEFORE_FORWARDING			3 /* ת���˷��Ϳͻ�����֤ʧ����Ϣ�� */
#define SESSIONSTATUS_AFTER_SENDING_AUTH_OK_AND_BEFORE_RECEIVING_SELECT_LIBRARY		4 /* ת���˷��Ϳͻ�����֤�ɹ���Ϣ�󣬽���ѡ���ǰ */
#define SESSIONSTATUS_AFTER_SENDING_SELECT_LIBRARY_AND_BEFORE_FORDWARD			5 /* ����ѡ����ȫ˫����ת��ǰ */
#define SESSIONSTATUS_FORWARDING							7 /* ȫ˫����ת�� */

#define MYSQL_COMMLEN(_cl_)	(((unsigned char)((_cl_)[0])+(unsigned char)((_cl_)[1])*256+(unsigned char)((_cl_)[2])*256*256))
#define MYSQL_OPTIONS_2(_cl_)	(((unsigned char)((_cl_)[0])+(unsigned char)((_cl_)[1])*256))

/* ���ܵ��Ự �ṹ */
struct AlivePipeSession
{
	int			alive_pipe[ 2 ] ; /* �ܵ������� */
} ;

/* �ͻ������ӻỰ �ṹ */
#define MAXLEN_ACCEPTED_SESSION_COMM_BUFFER	(3+1+(2<<24)) /* ͨѶ���ݻ�������С�����Ż��� */

struct ForwardSession ;
struct AcceptedSession
{
	unsigned char		type ; /* �Ự���� */
	int			status ; /* �Ự����״̬ */
	
	struct NetAddress	netaddr ; /* �����ַ */
	
	char			*comm_buffer ; /* ͨѶ����������ַ */
	int			fill_len ; /* ������䳤�� */
	int			process_len ; /* ���ݴ����� */
	int			comm_body_len ; /* mysqlЭ���峤�� */
	
	char			random_data[ 20 ] ; /* mysql��֤����� */
	
	struct ForwardSession	*p_pair_forward_session ; /* ��Ӧ �����ת���Ự */
} ;

/* �����ת���Ự �ṹ */
struct ForwardInstance ;
struct ForwardSession
{
	char			type ; /* �Ự���� */
	
	struct AcceptedSession	*p_pair_accepted_session ; /* ��Ӧ �ͻ������ӻỰ */
	struct ForwardInstance	*p_forward_instance ; /* ��Ӧ �����ת���� */
	struct ForwardServer	*p_forward_server ; /* ��Ӧ �����ת�������� */
	
	MYSQL			*mysql_connection ; /* mysql���Ӿ�� */
	
	struct lk_list_head	forward_session_listnode ; /* �����ת���Ự �����Ự ����ڵ� */
	time_t			close_unused_forward_session_timestamp ; /* �����ת���Ự ����Ự δ������ʱ�� */
	struct lk_list_head	unused_forward_session_listnode ; /* �����ת���Ự ����Ự ����ڵ� */
} ;

/* �����ת����������Ϣ �ṹ */
struct ForwardServer
{
	struct NetAddress	netaddr ; /* �����ַ */
	
	struct lk_list_head	forward_session_list ; /* �����ת���Ự �����Ự ���� */
	struct lk_list_head	unused_forward_session_list ; /* �����ת���Ự ����Ự ���� */
	
	struct lk_list_head	forward_server_listnode ; /* ����ڵ� */
} ;

/* �����ת���� �ṹ */
struct ForwardInstance
{
	char			instance[ sizeof(((mysqlda_conf*)0)->forwards[0].instance) ] ; /* ʵ���� */
	struct rb_node		forward_instance_rbnode ; /* ʵ���� ���ڵ� */
	
	struct lk_list_head	forward_server_list ; /* �����ת����������Ϣ ���� */
	
	unsigned long		power ; /* Ȩ�� */
	
	unsigned long		serial_range_begin ; /* ��ʼ��� */
	struct rb_node		forward_serial_range_rbnode ; /* ��ʼ��� ���ڵ� */
} ;

/* �����ת������ �ṹ */
#define MAXLEN_LIBRARY		64

struct ForwardLibrary
{
	char			library[ MAXLEN_LIBRARY + 1 ] ; /* ����ҵ����� ֵ */
	struct ForwardInstance	*p_forward_instance ; /* ��Ӧ �����ת���� */
	
	struct rb_node		forward_library_rbnode ; /* ���ڵ� */
} ;

/* �����ת���������� �ṹ */
#define MAXLEN_CORRELOBJECT	64

struct ForwardCorrelObject
{
	char			correl_object[ MAXLEN_CORRELOBJECT + 1 ] ; /* ����ҵ����������� */
	struct ForwardLibrary	*p_forward_library ; /* �����ת������ */
	
	struct rb_node		forward_correl_object_rbnode ; /* ���ڵ� */
} ;

#define MAXLEN_CORRELOBJECT_CLASS	64

/* �����ת������������ �ṹ */
struct ForwardCorrelObjectClass
{
	char			correl_object_class[ MAXLEN_CORRELOBJECT_CLASS + 1 ] ; /* ����ҵ����������� */
	
	struct rb_root		forward_correl_object_rbtree ; /* �����ת���������� ��-���� ��ϵ�� */
	
	struct rb_node		forward_correl_object_class_rbnode ; /* ���ڵ� */
} ;

/* MySQL�ֲ�ʽ���� �����ṹ */
struct MysqldaEnvironment
{
	char			*config_filename ; /* ����·���ļ� */
	char			*save_filename ; /* ת��������ʷ �־û� ·���ļ� */
	int			no_daemon_flag ; /* �Ƿ����ػ�����ģʽ���� */
	char			*action ; /* ��Ϊ��ʽ */
	
	char			user[ sizeof(((mysqlda_conf*)0)->auth.user) ] ; /* ���ݿ������û��� */
	char			pass[ sizeof(((mysqlda_conf*)0)->auth.pass) ] ; /* ���ݿ������û����� */
	char			db[ sizeof(((mysqlda_conf*)0)->auth.db) ] ; /* ���ݿ��� */
	time_t			unused_forward_session_timeout ; /* �����ת���Ự����Ự�س�ʱʱ�� */
	
	int			handshake_request_message_length ; /* ģ��������Ϣ�峤 */
	char			*handshake_request_message ; /* ģ��������Ϣ�� */
	
	int			select_version_comment_response_message_length ; /* ģ���ѯ�汾����Ϣ�峤 */
	char			*select_version_comment_response_message ; /* ģ���ѯ�汾����Ϣ�� */
	int			select_version_comment_response_message2_length ; /* ģ���ѯ�汾����Ϣ2�峤 */
	char			*select_version_comment_response_message2 ; /* ģ���ѯ�汾����Ϣ2�� */
	int			select_version_comment_response_message3_length ; /* ģ���ѯ�汾����Ϣ3�峤 */
	char			*select_version_comment_response_message3 ; /* ģ���ѯ�汾����Ϣ3�� */
	int			select_version_comment_response_message4_length ; /* ģ���ѯ�汾����Ϣ4�峤 */
	char			*select_version_comment_response_message4 ; /* ģ���ѯ�汾����Ϣ4�� */
	int			select_version_comment_response_message5_length ; /* ģ���ѯ�汾����Ϣ5�峤 */
	char			*select_version_comment_response_message5 ; /* ģ���ѯ�汾����Ϣ5�� */
	
	struct rb_root		forward_instance_rbtree ; /* �����ת���� ����ʵ����Ϊ���������� */
	struct rb_root		forward_serial_range_rbtree ; /* �����ת���� ������ʼ���Ϊ���������� */
	unsigned long		total_power ; /* ��Ȩ�� */
	
	struct AlivePipeSession	alive_pipe_session ; /* ���ܵ��Ự */
	struct ListenSession	listen_session ; /* �����Ự */
	
	int			epoll_fd ; /* epoll������ */
	
	struct rb_root		forward_library_rbtree ; /* �����ת������ ��ʷ�� */
	struct rb_root		forward_correl_object_class_rbtree ; /* �����ת������������ ��ʷ�� */
} ;

/*
 * util
 */

int WriteEntireFile( char *pathfilename , char *file_content , int file_len );
char *StrdupEntireFile( char *pathfilename , int *p_file_len );

int BindDaemonServer( int (* ServerMain)( void *pv ) , void *pv , int close_flag );

void GenerateRandomDataWithoutNull( char *data , int data_len );

unsigned long CalcHash( char *str , int str_len );

char *wordncasecmp( char *s1 , char *s2 , size_t n );

/*
 * config
 */

int InitConfigFile( struct MysqldaEnvironment *p_env );

void IncreaseForwardInstanceTreeNodePower( struct MysqldaEnvironment *p_env , struct ForwardInstance *p_this_forward_instance );

int LoadConfig( struct MysqldaEnvironment *p_env );
int ReloadConfig( struct MysqldaEnvironment *p_env );
void UnloadConfig( struct MysqldaEnvironment *p_env );

/*
 * monitor
 */

int monitor( void *pv );

/*
 * worker
 */

int worker( void *pv );

/*
 * comm
 */

int OnAcceptingSocket( struct MysqldaEnvironment *p_env , struct ListenSession *p_listen_session );
int OnReceivingAcceptedSocket( struct MysqldaEnvironment *p_env , struct AcceptedSession *p_accepted_session );
int OnSendingAcceptedSocket( struct MysqldaEnvironment *p_env , struct AcceptedSession *p_accepted_session );
int OnClosingAcceptedSocket( struct MysqldaEnvironment *p_env , struct AcceptedSession *p_accepted_session );

int OnReceivingForwardSocket( struct MysqldaEnvironment *p_env , struct ForwardSession *p_forward_session );
int OnSendingForwardSocket( struct MysqldaEnvironment *p_env , struct ForwardSession *p_forward_session );
int OnClosingForwardSocket( struct MysqldaEnvironment *p_env , struct ForwardSession *p_forward_session );

/*
 * app
 */

int FormatHandshakeMessage( struct MysqldaEnvironment *p_env , struct AcceptedSession *p_accepted_session );
int CheckAuthenticationMessage( struct MysqldaEnvironment *p_env , struct AcceptedSession *p_accepted_session );
int FormatAuthResultFail( struct MysqldaEnvironment *p_env , struct AcceptedSession *p_accepted_session );
int FormatAuthResultOk( struct MysqldaEnvironment *p_env , struct AcceptedSession *p_accepted_session );
int FormatSelectVersionCommentResponse( struct MysqldaEnvironment *p_env , struct AcceptedSession *p_accepted_session );

int SelectDatabaseLibrary( struct MysqldaEnvironment *p_env , struct AcceptedSession *p_accepted_session , char *library , int library_len );
int SetDatabaseCorrelObject( struct MysqldaEnvironment *p_env , struct AcceptedSession *p_accepted_session , char *correl_object_class , int correl_object_class_len , char *correl_object_name , int correl_object_name_len , char *library , int library_len );
int SelectDatabaseLibraryByCorrelObject( struct MysqldaEnvironment *p_env , struct AcceptedSession *p_accepted_session , char *correl_object_class , int correl_object_class_len , char *correl_object_name , int correl_object_name_len );

/*
 * rbtree
 */

int LinkForwardInstanceTreeNode( struct MysqldaEnvironment *p_env , struct ForwardInstance *p_forward_instance );
struct ForwardInstance *QueryForwardInstanceTreeNode( struct MysqldaEnvironment *p_env , struct ForwardInstance *p_forward_instance );
struct ForwardInstance *TravelForwardInstanceTreeNode( struct MysqldaEnvironment *p_env , struct ForwardInstance *p_forward_instance );
void UnlinkForwardInstanceTreeNode( struct MysqldaEnvironment *p_env , struct ForwardInstance *p_forward_instance );
void DestroyForwardInstanceTree( struct MysqldaEnvironment *p_env );

int LinkForwardSerialRangeTreeNode( struct MysqldaEnvironment *p_env , struct ForwardInstance *p_forward_instance );
struct ForwardInstance *QueryForwardSerialRangeTreeNode( struct MysqldaEnvironment *p_env , unsigned long serial_no );
struct ForwardInstance *TravelForwardSerialRangeTreeNode( struct MysqldaEnvironment *p_env , struct ForwardInstance *p_forward_instance );
void UnlinkForwardSerialRangeTreeNode( struct MysqldaEnvironment *p_env , struct ForwardInstance *p_forward_instance );
void DestroyForwardSerialRangeTree( struct MysqldaEnvironment *p_env );

int LinkForwardLibraryTreeNode( struct MysqldaEnvironment *p_env , struct ForwardLibrary *p_forward_library );
struct ForwardLibrary *QueryForwardLibraryTreeNode( struct MysqldaEnvironment *p_env , struct ForwardLibrary *p_forward_library );
void UnlinkForwardLibraryTreeNode( struct MysqldaEnvironment *p_env , struct ForwardLibrary *p_forward_library );
void DestroyForwardLibraryTree( struct MysqldaEnvironment *p_env );

int LinkForwardCorrelObjectClassTreeNode( struct MysqldaEnvironment *p_env , struct ForwardCorrelObjectClass *p_forward_correl_object_class );
struct ForwardCorrelObjectClass *QueryForwardCorrelObjectClassTreeNode( struct MysqldaEnvironment *p_env , struct ForwardCorrelObjectClass *p_forward_correl_object_class );
void UnlinkForwardCorrelObjectClassTreeNode( struct MysqldaEnvironment *p_env , struct ForwardCorrelObjectClass *p_forward_correl_object_class );
void DestroyForwardCorrelObjectClassTree( struct MysqldaEnvironment *p_env );

int LinkForwardCorrelObjectTreeNode( struct ForwardCorrelObjectClass *p_forward_correl_object_class , struct ForwardCorrelObject *p_forward_correl_object );
struct ForwardCorrelObject *QueryForwardCorrelObjectTreeNode( struct ForwardCorrelObjectClass *p_forward_correl_object_class , struct ForwardCorrelObject *p_forward_correl_object );
void UnlinkForwardCorrelObjectTreeNode( struct ForwardCorrelObjectClass *p_forward_correl_object_class , struct ForwardCorrelObject *p_forward_correl_object );
void DestroyForwardCorrelObjectTree( struct ForwardCorrelObjectClass *p_forward_correl_object_class );

#ifdef __cplusplus
}
#endif

#endif

