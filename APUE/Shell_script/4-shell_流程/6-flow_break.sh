#!/bin/bash

while ((x=1))
do 
	for((y=1;y<=10;y++))
	do
		count=$((x+y))
		if [ $count -eq 10 ]
		then 
			break 2 
		fi
			echo $count
	done
done

exit 0
