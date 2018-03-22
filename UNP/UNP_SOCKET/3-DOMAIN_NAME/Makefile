CC=gcc

EXEC_SERV=domain_service.out
EXEC_CLIE=domain_client.out

all:$(EXEC_SERV) $(EXEC_CLIE)
	echo "Debug Sucess"
$(EXEC_SERV):%.out:%.o
	$(CC) $< -o $@
$(EXEC_CLIE):%.out:%.o
	$(CC) $< -o $@
clean:
	rm -rf *.o
	rm -rf *.out
	echo "Clean Sucess"
