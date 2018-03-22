CC=gcc
OBJE=service.o
EXEC=service.out

CXXFLAGS= -lpthread

all:$(EXEC)
$(EXEC):$(OBJE)
	$(CC) $< $(CXXFLAGS) -o $@
	echo "Debug Sucess"
clean:
	rm -rf $(OBJE)
	rm -rf $(EXEC)
	echo "Clean Sucess"
