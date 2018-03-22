one=1-open_FILE
main:
	gcc -E ${one}.c -o ${one}.i
	gcc -S ${one}.i -o ${one}.s
	gcc -c ${one}.s -o ${one}.o
	gcc  ${one}.o -o ${one}.out
	@echo "===========OK==============="
clean:
	rm -rf ${one}.i
	rm -rf ${one}.s
	rm -rf ${one}.o
	@echo "++++++++++OK++++++++++++" 
