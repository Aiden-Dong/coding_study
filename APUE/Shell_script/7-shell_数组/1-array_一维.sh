#!/bin/bash

value[a]=36
declare -a province[b]=hainanshneng
city[c]=danzhoushi
MES=(This is the first script)

echo "${value[a]}"
echo "${province[b]}"
echo "${city[c]}"

echo "My hometown is ${province[b]} ${city[c]}"

echo "explain : ${MES[@]}"
#echo "explain : ${MES[*]}"

exit 0
