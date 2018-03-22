#!/bin/bash

OPEN()
{
	echo "Opening the file...."
	exec 4<>$file_name
	echo
}

file_descriptor=4
read -p "Input a name of file : " file_name

if [ -a $file_name ]
then
	echo "The file already exit."
	echo
	exit
else
	OPEN
	echo "The file \"$file_name\" already open...."
	echo "And the file descriptor is $file_descriptor"
fi

echo
exit 0
