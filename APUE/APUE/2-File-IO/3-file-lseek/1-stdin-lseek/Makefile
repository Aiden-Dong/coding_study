one=1-stdin-lseek\
	one

main:
	gcc -c $(one).c -o $(one).o
	gcc ${one}.o -o ${one}.out
	@echo "=========OK======="
clean:
	rm -rf ${one}.o
	@echo "++++++OK+++++++++"
echo:
	@echo ${one}
	@echo ${one}.c
