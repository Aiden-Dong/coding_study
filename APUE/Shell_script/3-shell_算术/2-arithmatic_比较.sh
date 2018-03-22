#!bin/bash

for((i=1;i<10;i++))
do
	if [ $i -eq 5 ]
	then
		echo "$i == 5"
	fi
	
	if [ $i -gt 5 ] 
	then
		echo "$i > 5"
	fi

	if [ $i -ge 5 ] 		
	then
		echo "$i => 5"
	fi

	if [ $i -lt 5 ]
	then
		echo "$i < 5"
	fi

	if [ $i -le 5 ]
	then
		echo "$i <= 5"
	fi

done
