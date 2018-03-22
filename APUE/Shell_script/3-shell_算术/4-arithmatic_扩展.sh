#!/bin/bash

i=`expr 3 + 6`

echo "6+3=$i"
echo

j=`expr $j + 1`

echo "j+1=$j"
echo

x=3
y=6
var=`expr $x = $y`
echo "var=$var"
exit 0
