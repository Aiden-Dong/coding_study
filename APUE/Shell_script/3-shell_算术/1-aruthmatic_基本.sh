#!/bin/bash

declare -i x
declare -i y=4

echo $((x+y))
echo

declare -i a
declare -i b=4

echo $((${a:-3}+6))
echo $((${b:-3}+6))

echo

exit 0
