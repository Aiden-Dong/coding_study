#!/bin/bash

if [ ! -z $1 ] && echo "variable#1 = $1" && [ ! -z $2 ] && echo "variable#2 = $2"
then
	echo "At least two arguments passed to script"
else
	echo "Less than two arguments passed to script"
fi

if [ ! -z $1 ]
then
	echo "variable#1 = $1"
fi

if [ ! -z $2 ]
then
	echo "variable#2 = $2"
else
	echo "Less than two arguments passed to scripto"
fi

exit 0
