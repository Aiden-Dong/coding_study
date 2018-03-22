#!/bin/bash

ARGS=1

if [ $# -ne $ARGS ]
then 
	echo "`basename $0` filename"
	exit 0
fi

if [ ! -f $1 ]
then
	echo "No such file"
	exit 0
fi

sed -e 's/\.//g' -e 's/\.//g' -e 's//\
/g' "$1" | tr 'A-Z' 'a-z' | sort | uniq -c | sort -nr

exit 0
