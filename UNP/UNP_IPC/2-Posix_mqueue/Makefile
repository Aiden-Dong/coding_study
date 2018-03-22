CC=gcc
SERV=Posix_mqueue.out
OBJE=Posix_mqueue.o

$(SERV):$(OBJE)
	$(CC) $< -o $@ -lrt

clean:
	rm -rf $(SERV)
	rm -rf $(OBJE)
