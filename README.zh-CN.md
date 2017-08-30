mysqlda - MySQL���ݿ��м��
==========================

<!-- TOC -->

- [1. ����](#1-����)
    - [1.1. ���ݷֲ�ʽ�зַ�ʽ](#11-���ݷֲ�ʽ�зַ�ʽ)
    - [1.2. mysqlda](#12-mysqlda)
- [2. �ܹ���ԭ��](#2-�ܹ���ԭ��)
    - [2.1. ��ϵ�ܹ�](#21-��ϵ�ܹ�)
    - [2.2. ����ԭ��](#22-����ԭ��)
    - [2.3. �ڲ�����ʵ��͹�ϵ](#23-�ڲ�����ʵ��͹�ϵ)
- [3. ��װ����](#3-��װ����)
    - [3.1. �⿪mysqldaԴ��� �� ֱ�Ӵ�Դ���йܵ�ַ��¡���°�](#31-�⿪mysqldaԴ���-��-ֱ�Ӵ�Դ���йܵ�ַ��¡���°�)
    - [3.2. ����srcĿ¼�������м��ļ�](#32-����srcĿ¼�������м��ļ�)
    - [3.3. ����](#33-����)
    - [3.4. ��װĿ���ļ���ȱʡĿ��Ŀ¼](#34-��װĿ���ļ���ȱʡĿ��Ŀ¼)
- [4. ����ʹ��](#4-����ʹ��)
    - [4.1. �Զ�����ȱʡ�����ļ�](#41-�Զ�����ȱʡ�����ļ�)
    - [4.2. ����mysqlda](#42-����mysqlda)
    - [4.3. ֹͣmysqlda](#43-ֹͣmysqlda)
    - [4.4. ����MySQL���ݿ⼯Ⱥ](#44-����mysql���ݿ⼯Ⱥ)
        - [4.4.1. ����MySQL������](#441-����mysql������)
        - [4.4.2. ����MySQL������������б�](#442-����mysql������������б�)
- [5. �����ļ������ʽ](#5-�����ļ������ʽ)
    - [5.1. ����ҵ�����-MySQL������ �����ļ���ʽ](#51-����ҵ�����-mysql������-�����ļ���ʽ)
    - [5.2. ���������ࡢ��������-����ҵ����� �����ļ���ʽ](#52-���������ࡢ��������-����ҵ�����-�����ļ���ʽ)
- [6. �����ӿ�](#6-�����ӿ�)
    - [6.1. �ú���ҵ�����ѡ��MySQL������](#61-�ú���ҵ�����ѡ��mysql������)
    - [6.2. �ù��������ࡢ��������󶨵�����ҵ�����](#62-�ù��������ࡢ��������󶨵�����ҵ�����)
    - [6.3. �ù��������ࡢ��������ѡ��MySQL������](#63-�ù��������ࡢ��������ѡ��mysql������)
- [7. ����ע������](#7-����ע������)
- [8. ���](#8-���)
    - [8.1. �����з�](#81-�����з�)
    - [8.2. Դ���й�](#82-Դ���й�)
    - [8.3. ��������](#83-��������)

<!-- /TOC -->

# 1. ����

## 1.1. ���ݷֲ�ʽ�зַ�ʽ

�ֲ�ʽ�ܹ������ѽ���������ݷֲ�ʽ���⣬�󲿷����ݿ��м����**�Էֿ�ֱ���Ϊ�зַ�ʽ**���ô���ͨ�ã���Ҳ�����������⣺

1. ���ݹ�����Ҫ����ƬΪ��λ�ڿ���ƶ����ݡ����ݹ�ģ�ܵ���Ƭ�������ƣ����ҵ��չ������ģ��󳬳�����Ԥ���ᵼ����Ƭ���������ã���������ӲǨ�Ƶ�������
2. ͬһҵ���������ݷ�ɢ�ڲ�ͬ���У��޷����ۺϡ����ӵȸ��Ӵ���
3. �����ζ�ŷֲ�ʽ������Ȼ���������׶��ύ�Ƚ���������������ϲ���������ô�ɿ����������ڽ�����ҵ��������ǿһ���ԡ�

**�Ժ���ҵ������зַ�ʽ**���Բ�Ʒ�����ҵ�������Ϊ�з�Ŀ�꣨���绥����ҵ��ϵͳ�еĿͻ����󣩣���������;�����ݿ��м�������ֻ��Ż���������ֶ���Ϊ�����ֶ�������Ȩ�صĿ�Ⱥ�з֣����������ݿ⼯Ⱥ�е�ĳ�����У���������������Ժ�ÿͻ������н��׶��ᱻ����������⴦������Ҫ��洢����ʱ��ֻ��򵥵����ӿ⵽���ݿ⼯Ⱥ�У������ݿ��м��ϵͳ�������¿�������Ϣ���������¿ⱻ����Ȩ�أ��¿ͻ�����������¿�ĸ��ʱ�󣬵��¿�洢������һ���̶�ʱ��ƽ����Ȩ�أ��¿ͻ�������������п�ĸ��ʾ��ȣ�ֱ����һ�����ݡ�

�Ժ���ҵ������зַ�ʽ�ĺô��ǣ�

1. ����Ԥ����Ƭ�������ݹ��������ƶ��κ����ݡ�
2. ����ͬһҵ���������ݼ�������������У����Կ��Խ�������ۺϡ����ӵȸ��Ӵ���
3. ÿ���ⶼ��ȫҵ��⣬ͬһҵ����������ģ�鴦����һ��������ɣ������ڿ��ֲ�ʽ��������ǿһ���Զ��������ݿⵥ������֤��

��Ҳ��������Ӳ�ˣ�

1. ��Ʒ����Ƴ���������ѡ����ҵ�������Ϊ�з����ݣ����ں��ѱ����
2. ��Щҵ��ϵͳ���ڶ������ҵ����󣬲��ʺ�ʹ�������зַ�ʽ�������������������Ϻ��ġ�

**�Էֿ�ֱ��з�**��**�Ժ���ҵ������з�**���������������ݷֲ�ʽ��Ʒ�ʽ��������ȱ�㣬Ӧ�ڲ�ͬ������ѡ���ʵķ�ʽ��

## 1.2. mysqlda

mysqlda��һ����ں���ҵ������зֵ�Proxyģʽ��MySQL���ݿ��м����

mysqlda���ƣ�

* �Ժ���ҵ������зַ�ʽ�����кô���
* ����ϵͳ�����ݷֲ�ʽ������̾����޸�
* ֧���Ժ���ҵ������ѯMySQL�����⣨�翪�����ֻ��Ż����䣩��Ҳ֧�ֺ���ҵ�����Ĺ��������翪������û�ID���û������˺ţ���ѯMySQL�����⡣
* ���������Ȩ���Զ����������ݺ��¿����Ͽ�ķ���Ȩ��Ҳ�Զ������������˹����룬ʹ�����п�������������Զ�����������
* ����ҵ������зֵĿ�֧��MySQL�����������б����ϵͳ�����ԡ�
* ��MySQL������֮�����ӳػ���ʵ�����Ӹ��ú���������������Ӻ��л�Ч�ʡ�
* ͨ���������������ļ������ݵ���MySQL�����������б�����MySQL��������ȫ�޸С�

# 2. �ܹ���ԭ��

## 2.1. ��ϵ�ܹ�

![images/architecture.png](images/architecture.png)

mysqlda���ݿ��м����ȫ��ѭMySQLͨѶЭ���Ž�Ӧ�÷�������Ⱥ��MySQL���ݿ⼯Ⱥ��

mysqlda�ڲ����̽ṹΪ����-���ӽ��̡���

## 2.2. ����ԭ��

MySQL���ݿ⼯ȺԤ������ͬ�������û��������룬��ͬ�����ݿ�����Ӧ�ñ�ṹ��mysqldaԤ������ͬ�������û��������롣

����mysqlda��Ⱥ���������ļ���etc/mysqlda.conf����װ�������û��������룬�ӱ����ļ���etc/mysqlda.save��etc/mysqlda.����������.save����װ���Ѵ��ڵĺ���ҵ����󡢹������� �� MySQL���ݿ⼯Ⱥ�� �������ϵ��Ϣ��

Ӧ�÷��������ñ�׼MySQL���Ӻ���/��������mysqlda��mysqlda����ѭMySQLͨѶЭ�鴦��MySQL�û���¼������У�顣

��¼�ɹ�������DML����ǰ��Ӧ�÷���������mysqlda��չSQLѡ��**����ҵ�����**��"select library ����ҵ�����"����**����������**��**��������**��"select library_by_correl_object ���������� ��������"��������MySQL�����⣬mysqlda���ѯ���ѷ����MySQL��**����ҵ�����**��**����������**��**��������**�����û�з��������ݼ�Ȩһ���Թ�ϣ�㷨����һ�������Ⲣ�־û��������ļ��У����Ӹ�MySQL�������Ӧ���ݿ�����������б���ѡ��һ���������������ӳ���ѡȡ�������ӣ���û�л����������½�һ�����ӣ���Ȼ���ŽӶ���Ͷ������ӽ�ԣ���ʼ�����������DML������

����DML�����п���Ҳ����mysqlda��չSQL��ѡ��**����ҵ�����**��**���������ࡢ��������**�Ե���MySQL��������������ӡ�

MySQL�������Ӧһ�����ݿ�������б�����MySQL���ݿ�1A(MASTER)��1B(SLAVE)��1C(SLAVE)��1D(SLAVE)��ɣ�1Aͬ���������ݸ�1B��1C��1D�����1A���ֹ��ϲ��ܱ�mysqlda���ӣ�mysqlda�����γ�������1B��1C��1D��ʵ��ϵͳ�����ԡ�

Ӧ�÷���������mysqlda��չSQL��**����������**��**��������**��**����ҵ�����**��"set correl_object ���������� �������� ����ҵ�����"����mysqlda�ᱣ��ù�ϵ���־û��������ļ��У����Ժ�ֱ����**����������**��**��������**��λMySQL�����⡣

## 2.3. �ڲ�����ʵ��͹�ϵ

![images/data_entity_and_relation.png](images/data_entity_and_relation.png)

һ��**MySQL������**��forward\_instance����Ӧһ��**MySQL���ݿ�����������б�**��forward\_servers list����

һ��**MySQL���ݿ�����������б�**��forward\_servers list����Ͻһ��**�������ӳ�**��unused\_forward\_session list����һ��**�������ӳ�**��forward\_session list����

һ��**����ҵ�����**���Զ�Ӧһ������**����������**��forward\_correl\_object\_class����**��������**��forward\_correl\_object����

һ��**����ҵ�����**��һ��**���������ࡢ��������** �� **MySQL������** ����һ��**������ϵ**��forward\_library����

accepted\_session��**Ӧ�÷�������mysqlda֮���ͨѶ�Ự**��forward\_session��**mysqlda��MySQL���ݿ������֮���ͨѶ�Ự**��һ��һ�������ϵ�MySQL�����ⱻѡ�����л����������Ự�ᱻ�Ž�������

# 3. ��װ����

mysqldaֻ������mysql��mariadb�������Ȱ�װ�ÿ�����*-devel-*��

## 3.1. �⿪mysqldaԴ��� �� ֱ�Ӵ�Դ���йܵ�ַ��¡���°�

```Shell
$ git clone http://git.oschina.net/calvinwilliams/mysqlda
Cloning into 'mysqlda'...
remote: Counting objects: 355, done.
remote: Compressing objects: 100% (345/345), done.
remote: Total 355 (delta 221), reused 0 (delta 0)
Receiving objects: 100% (355/355), 586.04 KiB | 0 bytes/s, done.
Resolving deltas: 100% (221/221), done.
```

## 3.2. ����srcĿ¼�������м��ļ�

```Shell
$ cd mysqlda/src
$ make -f makefile.Linux clean
make[1]: Entering directory `/home/calvin/src/tmp/mysqlda/src/mysqlda'
rm -f lk_list.o
rm -f rbtree.o
rm -f LOGC.o
rm -f fasterjson.o
rm -f util.o
rm -f rbtree_ins.o
rm -f IDL_mysqlda_conf.dsc.o
rm -f main.o
rm -f config.o
rm -f monitor.o
rm -f worker.o
rm -f comm.o
rm -f app.o
rm -f mysqlda
make[1]: Leaving directory `/home/calvin/src/tmp/mysqlda/src/mysqlda'
```

## 3.3. ����

```Shell
$ make -f makefile.Linux 
make[1]: Entering directory `/home/calvin/src/tmp/mysqlda/src/mysqlda'
gcc -g -fPIC -O2 -Wall -Werror -fno-strict-aliasing -I. -I/home/calvin/include -std=gnu99 -I/usr/include/mysql  -c lk_list.c
gcc -g -fPIC -O2 -Wall -Werror -fno-strict-aliasing -I. -I/home/calvin/include -std=gnu99 -I/usr/include/mysql  -c rbtree.c
gcc -g -fPIC -O2 -Wall -Werror -fno-strict-aliasing -I. -I/home/calvin/include -std=gnu99 -I/usr/include/mysql  -c LOGC.c
gcc -g -fPIC -O2 -Wall -Werror -fno-strict-aliasing -I. -I/home/calvin/include -std=gnu99 -I/usr/include/mysql  -c fasterjson.c
gcc -g -fPIC -O2 -Wall -Werror -fno-strict-aliasing -I. -I/home/calvin/include -std=gnu99 -I/usr/include/mysql  -c util.c
gcc -g -fPIC -O2 -Wall -Werror -fno-strict-aliasing -I. -I/home/calvin/include -std=gnu99 -I/usr/include/mysql  -c rbtree_ins.c
gcc -g -fPIC -O2 -Wall -Werror -fno-strict-aliasing -I. -I/home/calvin/include -std=gnu99 -I/usr/include/mysql  -c IDL_mysqlda_conf.dsc.c
gcc -g -fPIC -O2 -Wall -Werror -fno-strict-aliasing -I. -I/home/calvin/include -std=gnu99 -I/usr/include/mysql  -c main.c
gcc -g -fPIC -O2 -Wall -Werror -fno-strict-aliasing -I. -I/home/calvin/include -std=gnu99 -I/usr/include/mysql  -c config.c
gcc -g -fPIC -O2 -Wall -Werror -fno-strict-aliasing -I. -I/home/calvin/include -std=gnu99 -I/usr/include/mysql  -c monitor.c
gcc -g -fPIC -O2 -Wall -Werror -fno-strict-aliasing -I. -I/home/calvin/include -std=gnu99 -I/usr/include/mysql  -c worker.c
gcc -g -fPIC -O2 -Wall -Werror -fno-strict-aliasing -I. -I/home/calvin/include -std=gnu99 -I/usr/include/mysql  -c comm.c
gcc -g -fPIC -O2 -Wall -Werror -fno-strict-aliasing -I. -I/home/calvin/include -std=gnu99 -I/usr/include/mysql  -c app.c
gcc -g -fPIC -O2 -Wall -Werror -fno-strict-aliasing -o mysqlda lk_list.o rbtree.o LOGC.o fasterjson.o util.o rbtree_ins.o IDL_mysqlda_conf.dsc.o main.o config.o monitor.o worker.o comm.o app.o -L. -L/home/calvin/lib -L/usr/lib64/mysql -lmysqlclient -lcrypto 
make[1]: Leaving directory `/home/calvin/src/tmp/mysqlda/src/mysqlda'
```

## 3.4. ��װĿ���ļ���ȱʡĿ��Ŀ¼

```
��ִ���ļ� mysqlda $HOME/bin
```

Ŀ��Ŀ¼������makeinstall��ģ��������Ҫ�ɵ�����װĿ��Ŀ¼

```
_BINBASE        =       $(HOME)/bin
```

```Shell
$ make -f makefile.Linux install
make[1]: Entering directory `/home/calvin/src/tmp/mysqlda/src/mysqlda'
cp -rf mysqlda /home/calvin/bin/
make[1]: Leaving directory `/home/calvin/src/tmp/mysqlda/src/mysqlda'
```

��ѯ�汾�ţ�Ҳȷ�Ͽ�ִ���ļ�OK

```Shell
$ mysqlda -v
mysqlda v0.0.6.0
```

# 4. ����ʹ��

## 4.1. �Զ�����ȱʡ�����ļ�

```Shell
$ mysqlda -a init
$ cat ~/etc/mysqlda.conf
{
        "server" : 
        {
                "listen_ip" : "127.0.0.1" ,
                "listen_port" : 3306
        } ,
        "auth" : 
        {
                "user" : "calvin" ,
                "pass" : "calvin" ,
                "db" : "calvindb"
        } ,
        "session_pool" : 
        {
                "unused_forward_session_timeout" : 60
        } ,
        "forwards" : 
        [
        {
                "instance" : "mysqlda1" ,
                "forward" : 
                [
                {
                        "ip" : "127.0.0.1" ,
                        "port" : 13306
                }
                ]
        }
        ]
}
```

��������˵�����£�

```
server.listen_ip : mysqlda����Ӧ�÷�����������IP
server.listen_port : mysqlda����Ӧ�÷�����������PORT
auth.user : mysqlda����Ӧ�÷������ĵ�¼��֤�û�����Ҳ��mysqlda����MySQL���ݿ�������б�Ⱥ�ĵ�¼��֤�û���
auth.pass : mysqlda����Ӧ�÷������ĵ�¼��֤�û����룬Ҳ��mysqlda����MySQL���ݿ�������б�Ⱥ�ĵ�¼��֤�û�����
auth.db : mysqlda����Ӧ�÷������ĵ�¼���ݿ⣬Ҳ��mysqlda����MySQL���ݿ�������б�Ⱥ�ĵ�¼���ݿ�
session_pool.unused_forward_session_timeout : mysqlda����MySQL���ݿ�������б�Ⱥ�Ŀ������ӳس�ʱ����ʱ��
forwards[].instance : MySQL������ID
forwards[].forward[].ip : MySQL�����������IP
forwards[].forward[].port : MySQL�����������PORT
```

## 4.2. ����mysqlda

���������в���ֱ��ִ��mysqlda��õ����������б�

```Shell
$ mysqlda
USAGE : mysqlda -f (config_filename) --no-daemon -a [ init | start ]
                -v
```

����ʵ�ʻ����޸��������ļ�������

```Shell
$ mysqlda -a start
```

��ѯ������־
```Shell
$ view ~/log/mysqlda.log
2017-08-28 00:14:00.006735 | INFO  | 53148:config.c:349 | Load /home/calvin/etc/mysqlda.save ok
2017-08-28 00:14:00.006742 | INFO  | 53148:config.c:359 | instance[0xb36180][mysql_data_1] serial_range_begin[0] power[3]
2017-08-28 00:14:00.006752 | INFO  | 53148:config.c:363 |       ip[192.168.6.22] port[13306]
2017-08-28 00:14:00.006756 | INFO  | 53148:config.c:359 | instance[0xb36260][mysql_data_2] serial_range_begin[3] power[9]
2017-08-28 00:14:00.006759 | INFO  | 53148:config.c:363 |       ip[192.168.6.23] port[13306]
2017-08-28 00:14:00.006761 | INFO  | 53148:config.c:367 | total_power[12]
2017-08-28 00:14:00.006771 | INFO  | 53148:worker.c:38 | epoll_create ok , #1#
2017-08-28 00:14:00.006777 | INFO  | 53148:worker.c:53 | epoll_ctl #1# add alive_pipe_session #0# ok
2017-08-28 00:14:00.006787 | INFO  | 53148:worker.c:65 | socket ok , #2#
2017-08-28 00:14:00.006797 | INFO  | 53148:worker.c:82 | bind[:3306] #2# ok
2017-08-28 00:14:00.006804 | INFO  | 53148:worker.c:94 | listen[:3306] #2# ok
2017-08-28 00:14:00.006807 | INFO  | 53148:worker.c:109 | epoll_ctl #1# add listen_session #2# ok
2017-08-28 00:14:00.007439 | INFO  | 53148:worker.c:127 | [mysql_data_1]mysql_real_connect[192.168.6.22][13306][calvin][calvin][calvindb] connecting ...
2017-08-28 00:14:00.009794 | INFO  | 53148:worker.c:136 | [mysql_data_1]mysql_real_connect[192.168.6.22][13306][calvin][calvin][calvindb] connecting ok
2017-08-28 00:14:00.009815 | INFO  | 53148:worker.c:139 | [mysql_data_1]mysql_close[192.168.6.22][13306] ok
2017-08-28 00:14:00.009885 | INFO  | 53148:worker.c:127 | [mysql_data_2]mysql_real_connect[192.168.6.23][13306][calvin][calvin][calvindb] connecting ...
2017-08-28 00:14:00.011142 | INFO  | 53148:worker.c:136 | [mysql_data_2]mysql_real_connect[192.168.6.23][13306][calvin][calvin][calvindb] connecting ok
2017-08-28 00:14:00.011159 | INFO  | 53148:worker.c:139 | [mysql_data_2]mysql_close[192.168.6.23][13306] ok
2017-08-28 00:14:00.011731 | DEBUG | 53148:worker.c:177 | handshake_head
             0  1  2  3  4  5  6  7  8  9  A  B  C  D  E  F    0123456789ABCDEF
0x00000000   52 00 00 00                                       R...
2017-08-28 00:14:00.011770 | DEBUG | 53148:worker.c:205 | handshake_message
             0  1  2  3  4  5  6  7  8  9  A  B  C  D  E  F    0123456789ABCDEF
0x00000000   52 00 00 00 0A 35 2E 35 2E 35 32 2D 4D 61 72 69   R....5.5.52-Mari
0x00000010   61 44 42 00 C9 00 00 00 5C 7A 70 42 3B 3E 66 67   aDB.....\zpB;>fg
0x00000020   00 FF F7 08 02 00 0F A0 15 00 00 00 00 00 00 00   ................
0x00000030   00 00 00 52 44 3D 44 7B 64 62 3D 4B 3F 3A 45 00   ...RD=D{db=K?:E.
0x00000040   6D 79 73 71 6C 5F 6E 61 74 69 76 65 5F 70 61 73   mysql_native_pas
0x00000050   73 77 6F 72 64 00                                 sword.
2017-08-28 00:14:00.011789 | INFO  | 53148:worker.c:212 | epoll_wait #1# ...
2017-08-28 00:14:01.012977 | INFO  | 53148:worker.c:230 | epoll_wait #1# return[0]events
2017-08-28 00:14:01.013061 | INFO  | 53148:worker.c:212 | epoll_wait #1# ...
2017-08-28 00:14:02.027336 | INFO  | 53148:worker.c:230 | epoll_wait #1# return[0]events
2017-08-28 00:14:02.027458 | INFO  | 53148:worker.c:212 | epoll_wait #1# ...
2017-08-28 00:14:03.042497 | INFO  | 53148:worker.c:230 | epoll_wait #1# return[0]events
2017-08-28 00:14:03.042621 | INFO  | 53148:worker.c:212 | epoll_wait #1# ...
2017-08-28 00:14:04.046261 | INFO  | 53148:worker.c:230 | epoll_wait #1# return[0]events
2017-08-28 00:14:04.046377 | INFO  | 53148:worker.c:212 | epoll_wait #1# ...
```

���ʾ�����ɹ�

���mysqlda����MySQL���ݿ⼯Ⱥ�����⣬������ʼ���׶λ�������

```Shell
2017-08-28 00:12:07.998008 | INFO  | 53069:monitor.c:69 | [53069]fork[53070] ok
2017-08-28 00:12:07.997928 | INFO  | 53069:monitor.c:75 | [53069]fork[53070] ok
2017-08-28 00:12:07.998430 | INFO  | 53070:config.c:349 | Load /home/calvin/etc/mysqlda.save ok
2017-08-28 00:12:07.998438 | INFO  | 53070:config.c:359 | instance[0x20f1180][mysql_data_1] serial_range_begin[0] power[3]
2017-08-28 00:12:07.998441 | INFO  | 53070:config.c:363 |       ip[192.168.6.22] port[13306]
2017-08-28 00:12:07.998444 | INFO  | 53070:config.c:359 | instance[0x20f1260][mysql_data_2] serial_range_begin[3] power[9]
2017-08-28 00:12:07.998447 | INFO  | 53070:config.c:363 |       ip[192.168.6.23] port[13306]
2017-08-28 00:12:07.998450 | INFO  | 53070:config.c:367 | total_power[12]
2017-08-28 00:12:07.998460 | INFO  | 53070:worker.c:38 | epoll_create ok , #1#
2017-08-28 00:12:07.998466 | INFO  | 53070:worker.c:53 | epoll_ctl #1# add alive_pipe_session #0# ok
2017-08-28 00:12:07.998476 | INFO  | 53070:worker.c:65 | socket ok , #2#
2017-08-28 00:12:07.998487 | INFO  | 53070:worker.c:82 | bind[:3306] #2# ok
2017-08-28 00:12:07.998517 | INFO  | 53070:worker.c:94 | listen[:3306] #2# ok
2017-08-28 00:12:07.998522 | INFO  | 53070:worker.c:109 | epoll_ctl #1# add listen_session #2# ok
2017-08-28 00:12:07.999329 | INFO  | 53070:worker.c:127 | [mysql_data_1]mysql_real_connect[192.168.6.22][13306][calvin][calvin][calvindb] connecting ...
2017-08-28 00:12:11.044823 | ERROR | 53070:worker.c:130 | [mysql_data_1]mysql_real_connect[192.168.6.22][13306][calvin][calvin][calvindb] failed , mysql_errno[2003][Can't connect to MySQL server on '192.168.6.22' (113)]
2017-08-28 00:12:11.044946 | INFO  | 53070:worker.c:482 | worker exit ...
```

## 4.3. ֹͣmysqlda

ֱ��ps��������TERM�źż��ɣ����ͣ�����ͷ���KILL�ź�

```Shell
$ ps -ef | grep mysqlda
calvin   53069     1  0 00:12 pts/1    00:00:00 mysqlda -a start
calvin   53097 53072  0 00:12 pts/2    00:00:00 view mysqlda.log
calvin   53111 52899  0 00:12 pts/1    00:00:00 grep --color=auto mysqlda
$ kill 53069
```

## 4.4. ����MySQL���ݿ⼯Ⱥ

### 4.4.1. ����MySQL������

�������ļ�mysqlda.conf������һ��forwards[]������һ��MySQL������forward��������������MySQL������mysql\_data\_3��

```Shell
        "forwards" : 
        [
                {
                        "instance" : "mysql_data_1" ,
                        "forward" : 
                        [
                        { "ip" : "192.168.6.11" , "port" : 13306 } ,
                        { "ip" : "192.168.6.12" , "port" : 13306 } ,
                        { "ip" : "192.168.6.13" , "port" : 13306 }
                        ]
                } ,
                {
                        "instance" : "mysql_data_2" ,
                        "forward" : 
                        [
                        { "ip" : "192.168.6.21" , "port" : 13306 } ,
                        { "ip" : "192.168.6.22" , "port" : 13306 } ,
                        { "ip" : "192.168.6.23" , "port" : 13306 }
                        ]
                } ,
                {
                        "instance" : "mysql_data_3" ,
                        "forward" : 
                        [
                        { "ip" : "192.168.6.31" , "port" : 13306 } ,
                        { "ip" : "192.168.6.32" , "port" : 13306 } ,
                        { "ip" : "192.168.6.33" , "port" : 13306 }
                        ]
                }
        ]
```

����USR1�źŵ�mysqlda�����̡�

> ע�⣺��������������Ϣ��һ�㲻���޸Ļ�ɾ��MySQL�����⡣

### 4.4.2. ����MySQL������������б�

�������ļ�mysqlda.conf������һ��forwards[]������һ��MySQL������forward��������ÿ��MySQL�����ⶼ������һ̨MySQL��������

```Shell
        "forwards" : 
        [
                {
                        "instance" : "mysql_data_1" ,
                        "forward" : 
                        [
                        { "ip" : "192.168.6.11" , "port" : 13306 } ,
                        { "ip" : "192.168.6.12" , "port" : 13306 } ,
                        { "ip" : "192.168.6.13" , "port" : 13306 } ,
                        { "ip" : "192.168.6.14" , "port" : 13306 }
                        ]
                } ,
                {
                        "instance" : "mysql_data_2" ,
                        "forward" : 
                        [
                        { "ip" : "192.168.6.21" , "port" : 13306 } ,
                        { "ip" : "192.168.6.22" , "port" : 13306 } ,
                        { "ip" : "192.168.6.23" , "port" : 13306 } ,
                        { "ip" : "192.168.6.24" , "port" : 13306 }
                        ]
                }
        ]
```

����USR1�źŵ�mysqlda�����̡�

> ע�⣺������֧����һ��MySQL���������޸ĺ�ɾ��һ̨MySQL�����������������Ͽ���̨MySQL���������������ӡ�

# 5. �����ļ������ʽ

## 5.1. ����ҵ�����-MySQL������ �����ļ���ʽ

ÿ������ҵ�������������ϵ�󶼻�������ϵ�������ļ�

�ļ����������£�

```
$HOME/etc/mysqlda.save
```

�ļ���ʽ���£�

```
���������� ������ʱ�� ����ҵ����� MySQL������
```

ʾ�����£�

```
2017-08-24 22:17:11 1 mysql_data_2
2017-08-26 16:34:31 2 mysql_data_1
2017-08-26 16:34:31 3 mysql_data_1
2017-08-26 16:34:31 4 mysql_data_1
2017-08-26 16:34:31 5 mysql_data_2
2017-08-26 16:34:31 6 mysql_data_1
2017-08-26 16:34:31 7 mysql_data_1
2017-08-26 16:34:31 8 mysql_data_1
2017-08-26 16:34:31 9 mysql_data_1
2017-08-26 16:34:31 10 mysql_data_1
```

## 5.2. ���������ࡢ��������-����ҵ����� �����ļ���ʽ

ÿ�����������ࡢ��������ͺ���ҵ���������ϵ�󶼻�������ϵ�������ļ�

�ļ����������£�

```
$HOME/etc/mysqlda.(����������).save
```

�ļ���ʽ���£�

```
���������� ������ʱ�� �������� ����ҵ�����
```

ʾ�����£�

```
2017-08-26 18:11:42 330001 2
2017-08-26 18:12:41 330002 3
```

# 6. �����ӿ�

��Ŀ��Ŀ¼��testĿ¼���ǲ���ʵ��

## 6.1. �ú���ҵ�����ѡ��MySQL������

�ò��Գ������ڸ���һ��������䣬�����Ľ�����ѡ��MySQL�����⡣

> ע�⣺Ҳ����ֱ���ÿͻ���mysql���ӷ�����ִ��SQL"select library (����ҵ�����);"�õ��ȼ�Ч����

���Գ���ʾ�����£�

```C
$ cat test/mysqlda_test_select_library.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "my_global.h"
#include "mysql.h"

static void usage()
{
	printf( "USAGE : mysqlda_test_select_library begin_seqno end_seqno\n" );
	return;
}

int main( int argc , char *argv[] )
{
	MYSQL		*conn = NULL ;
	int		begin_seqno ;
	int		end_seqno ;
	int		seqno ;
	char		seqno_buffer[ 20 + 1 ] ;
	char		sql[ 4096 + 1 ] ;
	
	int		nret = 0 ;
	
	if( argc != 1 + 2 )
	{
		usage();
		exit(7);
	}
	
	printf( "mysql_get_client_info[%s]\n" , mysql_get_client_info() );
	
	conn = mysql_init(NULL) ;
	if( conn == NULL )
	{
		printf( "mysql_init failed\n" );
		return 1;
	}
	
	if( mysql_real_connect( conn , "192.168.6.21" , "calvin" , "calvin" , "calvindb" , 3306 , NULL , 0 ) == NULL )
	{
		printf( "mysql_real_connect failed , mysql_errno[%d][%s]\n" , mysql_errno(conn) , mysql_error(conn) );
		return 1;
	}
	else
	{
		printf( "mysql_real_connect ok\n" );
	}
	
	memset( seqno_buffer , 0x00 , sizeof(seqno_buffer) );
	begin_seqno = atoi(argv[1]) ;
	end_seqno = atoi(argv[2]) ;
	for( seqno = begin_seqno ; seqno <= end_seqno ; seqno++ )
	{
		memset( sql , 0x00 , sizeof(sql) );
		snprintf( sql , sizeof(sql) , "select library %d" , seqno );
		nret = mysql_query( conn , sql ) ;
		if( nret )
		{
			printf( "mysql_query failed , mysql_errno[%d][%s]\n" , mysql_errno(conn) , mysql_error(conn) );
			mysql_close( conn );
			return 1;
		}
		else
		{
			printf( "mysql_query ok\n" );
		}
	}
	
	mysql_close( conn );
	printf( "mysql_close\n" );
	
	return 0;
}
```

## 6.2. �ù��������ࡢ��������󶨵�����ҵ�����

�ò��Գ������ڸ������������ࡢ�������󡢺���ҵ����󣬽������ϵ

> ע�⣺Ҳ����ֱ���ÿͻ���mysql���ӷ�����ִ��SQL"set correl\_object ���������� �������� ����ҵ�����;"�õ��ȼ�Ч����

���Գ���ʾ�����£�

```C
$ cat test/mysqlda_test_set_correl_object.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "my_global.h"
#include "mysql.h"

static void usage()
{
	printf( "USAGE : mysqlda_test_set_correl_object correl_object_class correl_object library\n" );
	return;
}

int main( int argc , char *argv[] )
{
	MYSQL		*conn = NULL ;
	char		*correl_object_class = NULL ;
	char		*correl_object = NULL ;
	char		*library = NULL ;
	char		sql[ 4096 + 1 ] ;
	
	int		nret = 0 ;
	
	if( argc != 1 + 3 )
	{
		usage();
		exit(7);
	}
	
	printf( "mysql_get_client_info[%s]\n" , mysql_get_client_info() );
	
	conn = mysql_init(NULL) ;
	if( conn == NULL )
	{
		printf( "mysql_init failed\n" );
		return 1;
	}
	
	if( mysql_real_connect( conn , "192.168.6.21" , "calvin" , "calvin" , "calvindb" , 3306 , NULL , 0 ) == NULL )
	{
		printf( "mysql_real_connect failed , mysql_errno[%d][%s]\n" , mysql_errno(conn) , mysql_error(conn) );
		return 1;
	}
	else
	{
		printf( "mysql_real_connect ok\n" );
	}
	
	correl_object_class = argv[1] ;
	correl_object = argv[2] ;
	library = argv[3] ;
	
	memset( sql , 0x00 , sizeof(sql) );
	snprintf( sql , sizeof(sql) , "set correl_object %s %s %s" , correl_object_class , correl_object , library );
	nret = mysql_query( conn , sql ) ;
	if( nret )
	{
		printf( "mysql_query failed , mysql_errno[%d][%s]\n" , mysql_errno(conn) , mysql_error(conn) );
		mysql_close( conn );
		return 1;
	}
	else
	{
		printf( "mysql_query ok\n" );
	}
	
	mysql_close( conn );
	printf( "mysql_close\n" );
	
	return 0;
}
```

## 6.3. �ù��������ࡢ��������ѡ��MySQL������

�ò��Գ������ڸ���һ��������䣬�����Ľ�����ѡ��MySQL������

> ע�⣺Ҳ����ֱ���ÿͻ���mysql���ӷ�����ִ��SQL"select library\_by\_correl_object ���������� ��������;"�õ��ȼ�Ч����

���Գ���ʾ�����£�

```C
$ cat test/mysqlda_test_select_library_by_correl_object.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "my_global.h"
#include "mysql.h"

static void usage()
{
	printf( "USAGE : mysqlda_test_select_library_by_correl_object correl_object_class correl_object\n" );
	return;
}

int main( int argc , char *argv[] )
{
	MYSQL		*conn = NULL ;
	char		*correl_object_class = NULL ;
	char		*correl_object = NULL ;
	char		sql[ 4096 + 1 ] ;
	
	int		nret = 0 ;
	
	if( argc != 1 + 2 )
	{
		usage();
		exit(7);
	}
	
	printf( "mysql_get_client_info[%s]\n" , mysql_get_client_info() );
	
	conn = mysql_init(NULL) ;
	if( conn == NULL )
	{
		printf( "mysql_init failed\n" );
		return 1;
	}
	
	if( mysql_real_connect( conn , "192.168.6.21" , "calvin" , "calvin" , "calvindb" , 3306 , NULL , 0 ) == NULL )
	{
		printf( "mysql_real_connect failed , mysql_errno[%d][%s]\n" , mysql_errno(conn) , mysql_error(conn) );
		return 1;
	}
	else
	{
		printf( "mysql_real_connect ok\n" );
	}
	
	correl_object_class = argv[1] ;
	correl_object = argv[2] ;
	
	memset( sql , 0x00 , sizeof(sql) );
	snprintf( sql , sizeof(sql) , "select library_by_correl_object %s %s" , correl_object_class , correl_object );
	nret = mysql_query( conn , sql ) ;
	if( nret )
	{
		printf( "mysql_query failed , mysql_errno[%d][%s]\n" , mysql_errno(conn) , mysql_error(conn) );
		mysql_close( conn );
		return 1;
	}
	else
	{
		printf( "mysql_query ok\n" );
	}
	
	mysql_close( conn );
	printf( "mysql_close\n" );
	
	return 0;
}
```

# 7. ����ע������

> �����ÿͻ���mysqlֱ������mysqlda����"mysql --host 192.168.6.21 --port 3306 -u calvin -p"������ʱ��֧����������ֱ��ָ�����ݿ⡣��¼�ɹ���ĵ�һ�����������ѡ����MySQL�����⣬����ָ�����ݿ⣬mysqlda�Ѿ��������ļ��еĲ���use���ݿ��ˡ�

# 8. ���

## 8.1. �����з�

* ʵ��mysqlda��������Ⱥ������ֻ֧��mysqlda��������
* ���๦�ܡ���������˥��

## 8.2. Դ���й�

* [��Դ�й�](http://git.oschina.net/calvinwilliams/mysqlda)
* [github](https://github.com/calvinwilliams/mysqlda/)

## 8.3. ��������

* [����](mailto:calvinwilliams@163.com)
