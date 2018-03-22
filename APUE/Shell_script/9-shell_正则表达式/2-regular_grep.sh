#!/bin/bash

echo -n 'Input a name of file'

read name

if [ -f $name ]
then
	echo "----concidient pattern-----"
	(grep root $name ; exit)
	echo ">> The line number is :"
	(grep -c root $name; exit)
else
	echo "No such file...."
fi

echo

exit 0
