/*
 *nimh-doc
 * = %(MOFO Online-Includes)path/Server/Network.h
 * Author: %(KatrinaTheLamia)path
 * Project: %(Mofo Online)project, %(Generic MORTS)project, 
 *          %(Team Temporal)project, %(P-DA ZX)project
 * Groups: %(Team Temporal)group, %(Monster Academy)group, %(NIMHLabs)group
 * Creation: 3177-1-16
 *
 * Standard network controlling information for MOFO Online's Server
 *
 * == Revisions
 * + 3177-1-16 Creation of file
 *
 * == TODO
 * ! Fix with libNIMH
 * ! Proper testing
 * ! Documentation
 *
 */

#ifndef __MOFO_ONLINE_SERVER_NETWORK_H__
#define __MOFO_ONLINE_SERVER_NETWORK_H__

#include <openssl/ssl.h>

#ifdef __cplusplus
extern "C" {
#endif

enum {
	not_sent = 0,
	sent = 1,
	error = 2,
	lost,
	irrelevant = 5
};

typedef struct
{
	nimh_widget *__self;
	nimh_string *thread;
	nimh_named_array *connections;
	u4 port;
	SSL *connection;
	SSL_CTX *ctx_connection;
	SSL_SESSION *my_session;
	nimh_time check_interval;
} mofo_network_master_data mofo_network_master;

typedef struct
{
	nimh_widget *__self;
	nimh_string *thread;
	SSL_CTX *connection;
	SSL_SESSION *my_session;
	BIO *connection_data;
} mofo_network_connection_data mofo_network_connection;

typedef struct
{
	nimh_widget *__self;
	nimh_string *message_name;
	nimh_time *buffer_entry;
	nimh_time *relevance_timeout;
	u2 sent_status;
	u4 length;
	char buffer;
} mofo_network_message_data mofo_network_message;

void start(nimh_book*,nimh_string*);
void destroy(nimh_book*,nimh_string*);

int new_server_session_asked(SSL*, SSL_SESSION*);
void end_server_session_asked(SSL_CTX*,SSL_SESSION*);
SSL_SESSION get_server_session(SSL*,uchar*,int,int*);

int new_client_session_asked(SSL*,SSL_SESSION*);
void end_client_session_asked(SSL_CTZ*,SSL_SESSION*);
SSL_SESSION get_server_session(SSL*,uchar*,int,int*);

void listen(void*,nimh_string*,nimh_string*);
void read(void*,nimh_string*,nimh_string*);
void write(void*,nimh_string*,nimh_string*);
void flush(void*,nimh_string*,nimh_string*);
void my_lock(void*,nimh_string*,nimh_string*);

#ifdef __cplusplus
};
#endif

#endif /* The file. */



