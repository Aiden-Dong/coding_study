#!/bin/bash

read -p "Input a name of file ：" file_name

datafile=$file_name

exec 4<>$file_name

while read <&4
do
	echo $REPLY
done

exec 4<&-

echo

exit 0
