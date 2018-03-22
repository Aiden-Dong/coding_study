CC=gcc
OBJE=arp_recv.o
EXEC=arp_recv.out

$(EXEC):$(OBJE)
	$(CC) $< -o $@ -lpcap
	@echo -----------OK------------
clean:
	rm -rf $(OBJE)
	rm -rf $(EXEC)
	@echo +++++OK+++++