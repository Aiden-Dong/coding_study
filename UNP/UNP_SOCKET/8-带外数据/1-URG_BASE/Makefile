CC=gcc
SERV=service.out
CLIE=client.out
WALL= -lpthread -lrt
all:$(SERV) $(CLIE)

$(SERV):%.out:%.o
	$(CC) $< $(WALL) -o $@
	echo "Debug Service Sucess"
$(CLIE):%.out:%.o
	$(CC) $<  -o $@
	echo "Debug Client Sucess"

.PHONY :clean
clean:
	rm -rf *.out
	rm -rf *.o
	echo "Clean Sucess"
