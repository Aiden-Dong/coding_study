#!/bin/bash

echo "please input file name"
read f_name

if [ -z $f_name ]
then
	echo "you don't input any file name"
fi

if [ -f $f_name ]
then
	echo "The file. exits $f_name"
else
	echo "No such. file"
fi

exit 0
