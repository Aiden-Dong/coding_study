#!/bin/bash

week=(Monday Tuesday Wednessday Thursday Friday)

echo "${week[0]}"
echo "${week[2]:0}"
echo "${week[3]:1}"

echo "<.........>"

echo "${#week}"
echo "${#week[0]}"
echo "${#week[1]}"

echo "<.........>"

echo "${#week[@]}"
echo "${#week[*]}"

exit 0
