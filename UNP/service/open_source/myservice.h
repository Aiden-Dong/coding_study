#ifndef MYSERVICE_H_
#define MYSERVICE_H_

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

//============================================================================

// 自定义常量
#define NAME_LEN 	50				// 用户名的长度
#define DNAM_LEN	175				// 相对路径的长度
#define PASS_LEN	25				// 密码长度
#define FIFO_FILE 	"./myself/daemon.fifo"		// 管道文件名
#define MSG_KEY   	2013201344			// 消息队列键常量
#define DAEMON_FILE 	"./myself/service.daemon"	// 日志文件名
#define SOCK_PORT	8068				// socket 端口
#define ADMIN_NAME	"./myself/user.admin"		// 用户信息文件
//============================================================================

/*
 *	epoll 监听的结构
 */
typedef struct EPOLL_EVENT{
	int 			st_fd;			// 关联的 socket 文件描述符
	char			st_name[NAME_LEN+1];	// 用户名
	char			st_dnam[DNAM_LEN+1];	// 用户当前所在的路径名
	unsigned int 		st_off;			// 用户的在文件信息中的位置
	time_t			st_time;		// 关联的时间
	unsigned int		st_addr;		// 客户端的IP地址
	unsigned int 		st_pass;		// 服务与客户端交流的凭据
	struct EPOLL_EVENT	*st_next;		// 下一个链表信息结构
}LISTEN_EVENT, *PLISTEN_EVENT;

/*
 * 	传送日志消息
 */

typedef struct{
	long msg_level;
	char msg_text[100];
}MSG, *PMSG;
/*
 *	服务端文件描述符
 */

typedef struct{
	int 	fifo_fd;	// 管道文件描述符
	int 	msg_fd;		// 队列消息文件描述符
	int 	sock_fd;	// socket 文件描述符
	int 	epoll_fd;	// 等待的 epoll 描述符
}SERVICE_FD, *PSERVICE_FD;


//==============================================================================


/*
 * 内部函数
*/
/*
 *  service 端调用函数
 */

// 服务器准备事件
int 	service_arranged(PSERVICE_FD pser_fd);
// 用户登出
int 	event_del(PSERVICE_FD pser_fd, PLISTEN_EVENT cur_event);
// 用户登入
int 	event_add(PSERVICE_FD pser_fd, int listen_fd, const char *name, const char *dname, unsigned int off);
// 显示当前所有用户在线信息
void 	show_listen_events(void);
// 日志记录
void 	log_msg(PSERVICE_FD pser_fd, PLISTEN_EVENT listen_event, const char *msg);
// 接收登录消息
void 	*accept_listen_event(void *arg);
// 接收登录用户发来的请求
void	recv_client_event(const PSERVICE_FD pser_fd, PLISTEN_EVENT listen_event);
#endif
