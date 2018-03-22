#!/bin/bash

for input in a b c d e
do
	echo "group in $input"

	for output in 1 2 3 4 5 6 7
	do
		if [ $output -eq 3 ]
		then
			continue 2
		fi
			echo $output
	done
done

exit 0
