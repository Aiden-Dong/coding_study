#include "admin_user.h"
#include "myservice.h"
#include <dirent.h>
#include <netdb.h>
#include <string.h>
#include <sys/fcntl.h>
#include <unistd.h>
#include <time.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/stat.h>
#include "public_source.h"
#include "client_to_service.h"

int add_admin_user(const char *username)
{

	char	file_path[175];
	char	dir_path[175];

	memset(file_path, 0, sizeof(file_path));

	sprintf(file_path, "%s/%s", ADMIN_CENTER, username);

	if(mkdir(file_path, S_IRWXU) == -1)
		err_sys("mkdir error");

	memset(dir_path, 0, sizeof(dir_path));
	sprintf(dir_path, "%s/%s", file_path, "文档");

	if(mkdir(dir_path, S_IRWXU) == -1)
		err_sys("mkdir error");

	memset(dir_path, 0, sizeof(dir_path));
        sprintf(dir_path, "%s/%s", file_path, "视频");
	if(mkdir(dir_path, S_IRWXU) == -1)
                err_sys("mkdir error");
	
	memset(dir_path, 0, sizeof(dir_path));
        sprintf(dir_path, "%s/%s", file_path, "音乐");
	if(mkdir(dir_path, S_IRWXU) == -1)
                err_sys("mkdir error");
	
	memset(dir_path, 0, sizeof(dir_path));
        sprintf(dir_path, "%s/%s", file_path, "图片");
	if(mkdir(dir_path, S_IRWXU) == -1)
                err_sys("mkdir error");

	return 0;
}

int retu_direc(int sock_fd, const char *cent_dir)
{
	DIR 		*dir;
	struct dirent 	*file_msg;
	struct tm	file_time;
	struct stat	file_stat;
	SERV_TO_CLI	serecv_mess;

	if(chdir(cent_dir) == -1)
		return -1;

	dir = opendir(cent_dir);
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
			serecv_mess.stc_ftype = (FILE_NOR);

		if(stat(file_msg->d_name, &file_stat) == -1)
                       	err_sys("stat error");
                localtime_r(&file_stat.st_mtime, &file_time);
		
                serecv_mess.stc_fsize = htonl(file_stat.st_size);	// 填充大小
                sprintf(serecv_mess.stc_text, "%04d-%02d-%02d(%02d:%02d:%02d)", 1900+file_time.tm_year, file_time.tm_mon,file_time.tm_mday,
                                                       file_time.tm_hour, file_time.tm_min, file_time.tm_sec);// 填充时间
		

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

	closedir(dir);
	if(chdir(SERVICE_DIR) == -1)
                err_sys("chdir error");

	return 0;
	 	
}
int admin_checkdir(char *prentsdir, const char *usernam)
{
	char		namepath[70];

	sprintf(namepath, "%s/%s/", ADMIN_CENTER, usernam);

	if(strncmp(prentsdir, namepath, strlen(namepath)))
		return -1;

	if(chdir(prentsdir) == -1)
	{
		printf("进入目录错误\n");
		return -1;
	}

	 if(chdir(SERVICE_DIR) == -1)
                err_sys("chdir error");

	return 0;
}

int client_to_dir(char *clientdir, char *servicedir)
{
	if(servicedir == NULL || clientdir == NULL)
		return 0;
	sprintf(servicedir, "%s/%s/", ADMIN_CENTER, clientdir);

	return 1;
}

int back_dir(const char *redir, const char *username)
{
	char *path_name[50];
	char *ptr;

	sprintf(path_name, "%s/%s/", ADMIN_CENTER, username);

	ptr = redir + strlen(redir)-2;

	while(*ptr != '/')
		ptr--;

	*++ptr = '\0';

	if(strncmp(path_name, redir, strlen(path_name)))
		return -1;

	else if(chdir(redir) == -1)
		return -1;

	chdir(SERVICE_DIR);

	return 0;
}
int admin_mkdir(const char *dir, const char *name, const char *fname)
{
	char	file_path[175];


	if(admin_checkdir(dir, name) == -1)
		return -1;

	chdir(dir);

	if(mkdir(fname, S_IRUSR|S_IWUSR|S_IXUSR) == -1)
		return -1;

	chdir(SERVICE_DIR);
	return 0;
}
