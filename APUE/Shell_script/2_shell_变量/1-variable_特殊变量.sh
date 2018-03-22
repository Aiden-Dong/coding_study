#!/bin/bash

num=1

echo "The name of this script is \" $0 \" ."
echo 

if [ -n $1 ]
then 
	echo "The first parameter is $1"
fi

if [ -n $2 ]
then 
	echo "The secound parameter is $2"
fi

if [ -n $3 ]
then 
	echo "The third parameter is $3"
fi

echo

for var in $@
do
	echo "The $num parameter is $var"
	let num=num+1 
done

echo 
echo "all the command_line parameters arg is: \" $* \" ."
echo "the \$\# paramter is \" $# \" ."
exit 0
