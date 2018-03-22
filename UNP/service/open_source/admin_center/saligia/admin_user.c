#include "admin_user.h"
#include "myservice.h"
#include <dirent.h>
#include <netdb.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/stat.h>
#include "public_source.h"
#include "client_to_service.h"

int add_admin_user(const char *username)
{
	if(chdir(ADMIN_CENTER) == -1)
		err_sys("chdir error");

	if(mkdir(username, S_IRWXU) == -1)
		err_sys("mkdir error");
	if(chdir(username) == -1)
		err_sys("chdir error");

	if(mkdir("文档", S_IRWXU) == -1)
		err_sys("mkdir error");
	if(mkdir("视频", S_IRWXU) == -1)
                err_sys("mkdir error");
	if(mkdir("音乐", S_IRWXU) == -1)
                err_sys("mkdir error");
	if(mkdir("图片", S_IRWXU) == -1)
                err_sys("mkdir error");

	if(chdir(SERVICE_DIR) == -1)
		err_sys("chdir error");

	return 0;
}

int retu_direc(int sock_fd, const char *cent_dir)
{
	DIR 		*dir;
	struct dirent 	*file_msg;
	struct tm	file_time;
	struct stat	file_stat;
	SERV_TO_CLI	serecv_mess;

	if((dir = opendir(cent_dir)) == NULL)
		err_sys("opendir error");

	while((file_msg = readdir(dir)))
	{
		if(!strcmp(file_msg->d_name, ".") || !strcmp(file_msg->d_name, ".."))
			continue;
		memset(&serecv_mess, 0, sizeof(serecv_mess));

		// 数据记录
		serecv_mess.stc_events = (SE_DONOW);
		strcpy(serecv_mess.stc_fname, file_msg->d_name);

		if(file_msg->d_type == DT_DIR)  //目录文件
                        serecv_mess.stc_ftype = (FILE_DIR);
		else				// 非目录
		{
			serecv_mess.stc_ftype = (FILE_NOR);
			if(stat(file_msg->d_name, &file_stat) == -1)
                        	err_sys("stat error");

                	localtime_r(&file_stat.st_mtime, &file_time);

                	serecv_mess.stc_fsize = htonl(file_stat.st_size);
                	sprintf(serecv_mess.stc_text, "%04d-%02d-%02d(%02d:%02d:%02d)", 1900+file_time.tm_year, file_time.tm_mon,file_time.tm_mday,
                                                                         file_time.tm_hour, file_time.tm_min, file_time.tm_sec);
		}

		strcpy(serecv_mess.stc_mdir, cent_dir);
		// 发送到客户端

		if(send(sock_fd, &serecv_mess, sizeof(SERV_TO_CLI), 0) == -1)
		{
			closedir(dir);
			if(chdir(SERVICE_DIR) == -1)
               		 	err_sys("chdir error");
			return -1;
		}
	
	}

	if(chdir(SERVICE_DIR) == -1)
                err_sys("chdir error");
	closedir(dir);

	return 0;
	 	
}
int admin_checkdir(const char *prentsdir, const char *usernam)
{
	char		namepath[70];

	sprintf(namepath, "%s/%s", ADMIN_CENTER, usernam);

	if(!strncmp(prentsdir, namepath, strlen(namepath)))
		return -1;

	if(!chdir(prentsdir))
		return -1;

	 if(chdir(SERVICE_DIR) == -1)
                err_sys("chdir error");

	return 0;
}

int client_to_dir(char *clientdir, char *servicedir)
{
	if(servicedir == NULL || clientdir == NULL)
		return 0;
	sprintf(servicedir, "%s/%s", ADMIN_CENTER, clientdir);

	return 1;
}
