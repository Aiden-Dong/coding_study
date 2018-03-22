CC=gcc
OBJ=arp.o
EXEC=arp.out

$(EXEC):$(OBJ)
	$(CC) $< -o $@ -lnet
	@echo =========OK=========
clean:
	rm -rf $(OBJ)
	rm -rf $(EXEC)
	@echo +++++++OK+++++