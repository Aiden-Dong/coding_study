CC=gcc
CLIE_EXEC=client.out
SERV_EXEC=service.out

all:$(SERV_EXEC) $(CLIE_EXEC)
	@echo "Debug Sucess"

$(SERV_EXEC):%.out:%.o
	$(CC) $< -o $@
$(CLIE_EXEC):%.out:%.o
	$(CC) $< -o $@


clean:
	rm -rf *.o
	rm -rf *.out
	@echo "Clean Sucess"
