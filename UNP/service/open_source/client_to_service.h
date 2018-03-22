#ifndef CLIENT_TO_SERVICE_H_
#define CLIENT_TO_SERVICE_H_


//===================================================================

/*
 *	文件格式
 */
#define FILE_NOR 1		// 普通文件
#define FILE_DIR 2		// 目录文件

/*
 * 服务端标志
 */
#define SE_SUCESS 0		// 操作成功
#define SE_OK	  1		// 请求通过
#define SE_REFUSE 2		// 请求拒绝
#define SE_FAILE  3		// 操作失败
#define SE_ERROR  4		// 服务异常（服务端关闭）
#define SE_DONOW  5		// 正载执行服务操作
#define SE_FINISH 6		// 请求操作完成
/*
 * 客户端标志
*/
#define CL_LOGIN  1		// 用户登录
#define CL_ENROLL 2		// 用户注册
#define CL_EXIT	  3		// 用户退出
#define CL_CDDIR  4		// 进入目录
#define CL_EXDIR  5		// 退出目录
#define CL_CRDIR  6		// 创建目录
#define CL_RMFIL  7		// 删除文件
#define CL_CPFIL  8		// 复制文件
#define	CL_MVFIL  9 		// 移动文件
#define CL_SNDFL  10		// 上传文件
#define CL_RCVFL  11		// 下载文件
#define CL_ERROR  0		// 意外错误

/*
 * 文件常量区
*/

#define FILE_MSG_LEN 	57	// 文件中每条用户信息的长度
#define USER_MSG_LEN    47	// 发送的用户登录信息的长度

//====================================================================

/*
 * 用户请求结构
 */

typedef struct{
char	cts_events;			// 用户请求事件
char    cts_fname[NAME_LEN+1];		// 文件名
char 	cts_ftype;			// 文件格式
int 	cts_fsize;			// 文件大小
char	cts_main[DNAM_LEN+1];		// 主目录
char    cts_minor[DNAM_LEN+1];		// 辅助目录
char    cts_text[USER_MSG_LEN];		// 请求内容
}CLI_TO_SERV, *PCLI_TO_SERV;

/*
 *      用户帐号结构
 */

typedef struct{
        char au_name[NAME_LEN+1];               // 用户名
        char au_passwd[PASS_LEN+1];	        // 用户密码
        char au_confirm;                        // 用户在线信息
}ADMIN_USR, *PADMIN_USR;

/*
  * 客户端返回结果
*/

typedef struct{
	char 	stc_events;	   		// 服务器回应事件
	char 	stc_fname[NAME_LEN+1];		// 文件名
	char 	stc_ftype;			// 文件格式
	int 	stc_fsize;			// 文件大小
	char 	stc_mdir[DNAM_LEN+1];		// 操作目录
	char 	stc_text[USER_MSG_LEN];		// 回馈内容
}SERV_TO_CLI, *PSERV_TO_CLI;

//====================================================================
/*
 *静态内部函数结构
*/
static int set_recv_admin(const char *admin_buf, PADMIN_USR admin_user);				// 将传来的接受信息转化为用户的登录信息
static int set_file_admin(const char *file_admin, PADMIN_USR admin_user);				// 将文件记录转化为用户登录信息

/*
*	外部函数接口
*/

int 	  	admin_register(const char *recv_admin_buf, PADMIN_USR admin_msg);			// 用户注册
int 		admin_del(const char *admin_name, unsigned int off);					// 用户注销
unsigned int 	admin_login(const char *login_buf, PADMIN_USR usr_msg);					// 用户登录检测
int 		retu_direc(int sock_fd, const char *cent_dir);						// 返回制定路径下的文件详情列表

#endif	
