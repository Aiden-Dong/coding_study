#include <stdio.h>
#include "public_source.h"
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/msg.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include "myservice.h"
#include "client_to_service.h"

pthread_rwlock_t admin_lock = PTHREAD_RWLOCK_INITIALIZER;


// 用户注册
int admin_register(const char *recv_admin_buf, PADMIN_USR admin_msg)
{

        int             admin_fd;
        char            admin_buf[FILE_MSG_LEN];
	char            file_usr_msg[FILE_MSG_LEN+1];
	ADMIN_USR	file_msg;
	int 		read_len;

        memset(admin_buf, 0, sizeof(admin_buf));

        if(set_recv_admin(recv_admin_buf, admin_msg) == -1)
                err_sys("set_recv_admin");

	// 首先检测是否有已有命名

	pthread_rwlock_rdlock(&admin_lock);

	if((admin_fd = open(ADMIN_NAME, O_RDONLY)) == -1)
                err_sys("open error");

	while(read_len = read(admin_fd, file_usr_msg, FILE_MSG_LEN))
        {

                if(read_len == -1)
                        err_sys("read error");

                if(set_file_admin(file_usr_msg, &file_msg) == -1)
                        err_sys("set_file_admin error");

                if(strcmp(admin_msg->au_name, file_msg.au_name) == 0) // 找到一个匹配项
		{
			close(admin_fd);
			pthread_rwlock_unlock(&admin_lock);

                	return 0;
		}
        }

	
	close(admin_fd);
	pthread_rwlock_unlock(&admin_lock);

        sprintf(admin_buf, "%-20s  :  %-25s  :  %c\n", admin_msg->au_name, admin_msg->au_passwd, admin_msg->au_confirm);

	// 将新的用户信息写入数据

	pthread_rwlock_wrlock(&admin_lock);
       
	if((admin_fd = open(ADMIN_NAME, O_WRONLY| O_APPEND)) == -1)
	     err_sys("open error");

        if(write(admin_fd, admin_buf, sizeof(admin_buf)) == -1)
             err_sys("write error");

        close(admin_fd);
	pthread_rwlock_unlock(&admin_lock);

        return 1;
}

// 用户注销
int admin_del(const char *admin_name, unsigned int off)
{
	int 		admin_fd;
	char            file_usr_msg[FILE_MSG_LEN+1];
        ADMIN_USR       file_msg;
	int 		read_len;

	memset(file_usr_msg, 0, sizeof(file_usr_msg));

	pthread_rwlock_rdlock(&admin_lock);

	if((admin_fd = open(ADMIN_NAME, O_RDONLY)) == -1)
		err_sys("open error");

	if((read_len = pread(admin_fd, file_usr_msg, FILE_MSG_LEN, off)) == -1)
		err_sys("pread error");

	close(admin_fd);
        pthread_rwlock_unlock(&admin_lock);

	if(set_file_admin(file_usr_msg, &file_msg) == -1)
                err_sys("set_file_admin error");
		
	if(!strcmp(admin_name, file_msg.au_name))
	{
		if(file_msg.au_confirm == '1')
			file_msg.au_confirm = '0';
		else
			return -1;
	}
	else
		return -1;

	sprintf(file_usr_msg, "%-20s  :  %-25s  :  %c\n", file_msg.au_name, file_msg.au_passwd, file_msg.au_confirm);

	pthread_rwlock_wrlock(&admin_lock);
	if((admin_fd = open(ADMIN_NAME, O_WRONLY)) == -1)
		err_sys("open error");
	if(pwrite(admin_fd, file_usr_msg, FILE_MSG_LEN, off) == -1)
		err_sys("pwrite error");

	close(admin_fd);
	pthread_rwlock_unlock(&admin_lock);

	return 0;
}
// 用户登录检测

unsigned int admin_login(const char *login_buf, PADMIN_USR usr_msg)
{
	char		file_usr_msg[FILE_MSG_LEN+1];
	int		admin_fd;
	int 		read_len;
	ADMIN_USR	file_msg;
	unsigned int 	file_len = 0;

	memset(file_usr_msg, 0, sizeof(file_usr_msg));

	if(set_recv_admin(login_buf, usr_msg) == -1)
		err_sys("set_recv_admin error");

	// 检测用户信息是否存在
	pthread_rwlock_rdlock(&admin_lock);

	if((admin_fd = open(ADMIN_NAME, O_RDONLY)) == -1)
                err_sys("open error");

	while(read_len = read(admin_fd, file_usr_msg, FILE_MSG_LEN))
	{

		if(read_len == -1)
			err_sys("read error");

		if(set_file_admin(file_usr_msg, &file_msg) == -1)
			err_sys("set_file_admin error");

		if(strcmp(usr_msg->au_name, file_msg.au_name) == 0)
		{
			close(admin_fd);
			pthread_rwlock_unlock(&admin_lock);

			if(strcmp(usr_msg->au_passwd, file_msg.au_passwd) == 0)
			{
				if(file_msg.au_confirm == '0')		// 表示用户状态信息正确
					file_msg.au_confirm = '1';
				else
					return -3;			// 表示用户已经在线
			}
			else
				return -2;				// 密码错误
		
			sprintf(file_usr_msg, "%-20s  :  %-25s  :  %c\n", file_msg.au_name, file_msg.au_passwd, file_msg.au_confirm);

			pthread_rwlock_wrlock(&admin_lock);
			if((admin_fd = open(ADMIN_NAME, O_WRONLY)) == -1)
                		err_sys("open error");
			pwrite(admin_fd, file_usr_msg, FILE_MSG_LEN, file_len);
			close(admin_fd);
			pthread_rwlock_unlock(&admin_lock);

			return file_len;

		}

		file_len += FILE_MSG_LEN;
	}

	close(admin_fd);
	pthread_rwlock_unlock(&admin_lock);

	return -2;
		
}

// 将客户端发送过来的用户信息转化为标准用户信息
static int set_recv_admin(const char *admin_buf, PADMIN_USR admin_user)
{
	int		 name_len;
	int 		 pass_len;

	memset(admin_user, 0, sizeof(ADMIN_USR));

	if(admin_buf == NULL)
		return -1;

	// 获取数据
	sscanf(admin_buf, "%[^:]:%[^:]", admin_user->au_name, admin_user->au_passwd);

	name_len = strlen(admin_user->au_name);
	pass_len = strlen(admin_user->au_passwd);
	
	if(name_len == 0 || name_len > NAME_LEN)
		return -1;
	if(pass_len == 0 || pass_len > PASS_LEN)
		return -1;
	admin_user->au_confirm = '0';			// 设置标志位

	return 0;

}

//将文件中的用户信息转化为标准用户信息
static int set_file_admin(const char *file_admin, PADMIN_USR admin_user)
{
	int              name_len;
        int              pass_len;
	char 		 ch;

	memset(admin_user, 0, sizeof(ADMIN_USR));

	if(file_admin == NULL || admin_user == NULL)
		return -1;

	sscanf(file_admin, "%[^ :]%*[ :]%[^ :]%*[ :]%c"
		,admin_user->au_name, admin_user->au_passwd, &admin_user->au_confirm);

	name_len = strlen(admin_user->au_name);
	pass_len = strlen(admin_user->au_passwd);
	ch	 = admin_user->au_confirm;

	if(ch != '0' && ch != '1')
		return -1;
	if(name_len == 0 || name_len > NAME_LEN)
                return -1;
        if(pass_len == 0 || pass_len > PASS_LEN)
                return -1;

	return 0;
}
