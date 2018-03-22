#ifdef 	PTHREAD_TRANSP_H_
#define	PTHREAD_TRANSP_H_

typedef struct{
	pthread_t 	pth_tid; 	// 线程ID
	char		pth_option;	// 读写软件
	pthread_mutex_t pth_mutex;	// 互斥量
	pthread_cond_t	pth_cond;	// 条件变量
	
}
#endif
