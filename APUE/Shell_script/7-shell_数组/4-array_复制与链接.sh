#!/bin/bash

CpArray()
{
	echo -n 'eval '
	echo -n "$2"
	echo -n '=( ${'
	echo -n "$1"
	echo -n '[@]} )'
}

CopyArray=CpArray

Hype()
{
	local -a TEMP
	local -a hype=(Really Rocks)
	$($CopyArray $1 TEMP)
	TEMP=( ${TEMP[@]} ${hype[@]} )
	$($CopyArray TEMP $2)
}

declare -a before=(Advanced Bash Scripting)
echo "Array before = ${before[@]}"
Hype before after
echo "Array after = ${after[@]}"

echo "What ${after[@]:3:2}?"
declare -a modest=(${after[@]:2:3})
echo "Array modest=${modest[@]}"
echo "Array before=${before[@]}"

echo

exit 0
