CC=gcc

CENTER=service.o ser_source.o client_to_service.o daemon.o admin_user.o public_source.o myservice.o sig_dispose.o
SERVICE_LINK=service.o ser_source.o client_to_service.o admin_user.o public_source.o myservice.o sig_dispose.o
DAEMON_LINK=daemon.o public_source.o
OBject=service.out daemon.out
DIR=myself

all:$(OBject)
$(OBject):$(CENTER)
	#$(CC) $< -o $@ -lpthread
	$(CC) $(SERVICE_LINK) -o service.out -lpthread
	$(CC) $(DAEMON_LINK) -o daemon.out -lpthread
	@echo "已经完成链接"

$(CENTER):%.o:%.c *.h
	$(CC) -c $< -o $@
	@echo "已经完成编译"
clean:
	rm -rf $(CENTER)
	rm -rf $(OBject)
	@echo "++++++OK++++++"

cleanfile:

	rm -rf ./admin_center
	rm -rf ./myself/daemon.fifo
	rm -rf ./myself/service.daemon
	rm -rf ./myself/user.admin
	rm -rf ./myself
	@echo "----------OK---------"
