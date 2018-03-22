#!/bin/bash

FUNC ()
{
	if [ $# -ne 0 ] ; then
		echo "The Parameter num is : $#"
		
		for param in $@
		do
			echo "$param"
		done
	fi
}

FUNC one two three 

FUNC $@

FUNC hello world

exit 0
