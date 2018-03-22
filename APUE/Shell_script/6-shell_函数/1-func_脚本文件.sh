#!/bin/bash

IS_A_FILE ()
{
	if [ -f $1 ] ; then
		echo "The file exits"
	else
		echo "No such file"
	fi
}
