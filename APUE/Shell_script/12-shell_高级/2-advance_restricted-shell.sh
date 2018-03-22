#!/bin/bash

echo "changing directory"
cd /etc/httpd
echo "Now in `pwd`"
echo; sleep 1

echo "Coming back home"
cd
echo "Now in `pwd`"
echo

set -r

echo "running restricted mode"
echo "changing directory"

cd /etc/httpd

echo "The directory is `pwd`"
echo

exit 0
