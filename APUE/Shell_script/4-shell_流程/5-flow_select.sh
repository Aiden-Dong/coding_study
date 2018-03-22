#!/bin/bash

PS3="input number :"

echo

select f in *
do 
	echo "the number is $REPLY , the file_name is $f"
done

exit 0
