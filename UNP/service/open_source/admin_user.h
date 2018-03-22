#ifndef	ADMIN_USER_H_
#define ADMIN_USER_H_

//===================================================

#define ADMIN_CENTER    "/home/saligia/service/open_source/admin_center"       	// 用户操作目录 
#define SERVICE_DIR	"/home/saligia/service/open_source"			// 服务器操作主目录	
//===================================================

//创建新的用户时初始化目录
int add_admin_user(const char *username);

// 返回用户指定目录下的所有文件
int retu_direc(int sock_fd, const char *cent_dir); 

// 检查用户请求的目录是否合法
int admin_checkdir(char *parentsdir, const char *usernam);

// 使用用户名生成用户初始目录
int client_to_dir(char *clientdir, char *servicedir);
// 后退一个目录
int back_dir(const char *redir, const char *username);
// 
int admin_mkdir(const char *dir, const char *name, const char *fname);
#endif
