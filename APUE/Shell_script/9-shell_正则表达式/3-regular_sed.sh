#!/bin/bash

read -p 'Input a name of file : ' file_name

if [ -f $file_name ]
then
	(sed -e 's/:/  /g' $file_name >> $file_one)
	echo "operater already finish ....."
else
	echo "No such file....."
fi

echo

exit 0
