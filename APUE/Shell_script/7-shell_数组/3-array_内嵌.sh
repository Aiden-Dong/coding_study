#!/bin/bash

ARRAY1=(
	var_a=element2
	var_b=element3
	var_c=element4
)

ARRAY2=(
	"${ARRAY1[*]}"
	var_d=element5
	var_e=element6
	var_f=element7
)

echo "message : embedded array"

PRINT()
{
	IFS=$'\n'
	echo
	echo "${ARRAY2[*]}"
}

PRINT

echo
exit 0
