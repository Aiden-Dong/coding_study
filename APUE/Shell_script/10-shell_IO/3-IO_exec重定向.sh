#!/bin/bash

read -p "Input a name of file : " file_name

if [ -a $file_name ]
then
	exec 8<&0
	exec < $file_name
	read line1
	read line2
else
	echo "No such file"
	echo ; exit 0
fi

echo "The file of $file_name line is :"
echo $line1 ; echo $line2
echo

exec 0<&8 8 8<&-

echo "This is stdin, input anything"
read stdin

echo "-- Read from stdin --"
echo "-- And the stdin is --"
echo ; echo $stdin
echo

exit 0
