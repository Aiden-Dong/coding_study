#!/bin/bash

echo -e "decimal hex character"

for (( i=0x41 ; i<0x51 ; i++))
do
	echo $i | awk '{printf("%3d   %2x   %c\n",$1,$1,$1)}'
done

exit 0
