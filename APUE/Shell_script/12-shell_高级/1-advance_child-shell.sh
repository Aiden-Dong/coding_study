#!/bin/bash

outer_variable=inner
(
	inner_variable=inner
	echo "subshell ,\"inner_variable\" = $inner_variable"
	echo "subshell, \"outer_variable\" = $outer_variable"
	echo
)

if [ -z "$inner_variable" ]
then
	echo "inner_variable undefind in main body of shell"
else
	echo "inner_variable define in main body of shell"
fi

echo "Main body of shell ,\" inner_variable\" = $inner_variable"

echo

exit 0
