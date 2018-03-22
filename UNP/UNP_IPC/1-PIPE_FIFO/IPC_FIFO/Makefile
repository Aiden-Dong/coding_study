CC=gcc
SERV=Fifo_Thread.out
OBJE=Fifo_Thread.o

$(SERV):$(OBJE)
	$(CC) $< -o $@ -lpthread

clean:
	rm -rf $(SERV)
	rm -rf $(OBJE)
