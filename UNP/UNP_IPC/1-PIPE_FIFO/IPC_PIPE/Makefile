CC=gcc
SERV=PIPE_Thread.out
OBJE=PIPE_Thread.o

$(SERV):$(OBJE)
	$(CC) $< -o $@ -lpthread

clean:
	rm -rf $(SERV)
	rm -rf $(OBJE)
