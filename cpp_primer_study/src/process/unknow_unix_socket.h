/**
 * <pre>
 * </pre>
 *
 * @user : aiden
 * @date : 2019-03-08
 */

#ifndef CPP_PRIMER_STUDY_UNKNOW_UNIX_SOCKET_H
#define CPP_PRIMER_STUDY_UNKNOW_UNIX_SOCKET_H

void unsock_start();

static void sys_error(const char * mesage);
static void client_process(int signo);

static void parent_ctrl(int fd);
static void client_ctrl(int fd);

#endif //CPP_PRIMER_STUDY_UNKNOW_UNIX_SOCKET_H
