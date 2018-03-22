CC=gcc
SOCKOBJE=sockopt.o
SOCKEXEC=sockopt.out

all:$(SOCKEXEC)

$(SOCKEXEC):$(SOCKOBJE)
	$(CC) $< -o $@
	echo "Debug Sucess"

clean:
	rm -rf *.o
	rm -rf *.out
	echo "Clean Sucess"
