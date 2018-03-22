#!/bin/bash

read -n 1 -s -p $'Control-M leaves first line .\x0d'
echo >&2

read -n 1 -s -p $'Control-J leaves next line.\x0a'
echo >&2

read -n 1 -s -p $'And Control-K \x0bgoes straight down.'
echo >&2

echo $var | col

exit 0
