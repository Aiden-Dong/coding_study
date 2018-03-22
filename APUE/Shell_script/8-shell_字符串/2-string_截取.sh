#!/bin/bash

hostname="cat.host_name is cat.super.com"

string=${hostname:3}
echo $string

string1=${hostname%.*}
string2=${hostname%%.*}
string3=${hostname#*.*}

echo $string1
echo $string2
echo $string3

exit 0
