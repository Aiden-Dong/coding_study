#!/bin/bash

book="This is a script's book"

size=${#book}
size2=$(expr length "$book")

echo $size
echo $size2

exit 0
