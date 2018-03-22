#!/bin/bash

value=$@

for val in $value 
do
	echo "val = $val"
	sleep 1
done
exit 0
