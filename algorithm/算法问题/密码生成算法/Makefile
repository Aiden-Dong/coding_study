CC=gcc
OBJE=keyvsion.o
EXEC=keyvsion.out
WALL=-pthread
all:$(EXEC)

$(EXEC):$(OBJE)
	$(CC) $(WALL) $< -o $@
	echo "Sucess Debug"
clean:
	rm -rf $(OBJE)
	rm -rf $(EXEC)
	echo "Sucess Clean"
run:
	./$(EXEC)
