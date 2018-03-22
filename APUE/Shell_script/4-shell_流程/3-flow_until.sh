#!/bin/bash

count=1
i=0

until [ $count -gt 10 ]
do
	let count++ ; let ++i
done

echo "count = $count"
echo "i=$i"
exit
