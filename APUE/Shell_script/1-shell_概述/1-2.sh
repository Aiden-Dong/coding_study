#!/bin/bash

CAT()
{
	cat /etc/passwd | head -$line
}

limit=6
line=2

if [ "$line" -le "$limit" ]
then
	while [ -n "$line" ]
	do
		CAT
		break 
	done

	line=$(($line + 1))
	CAT
fi

exit 0
