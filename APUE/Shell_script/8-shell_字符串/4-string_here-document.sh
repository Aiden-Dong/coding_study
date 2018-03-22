#!/bin/bash

FROM='from:root@cat.super.com'
TO='to:cat@cat.super.com'
SUBJECT='subject:shell script'
MESSAGE='This is bash shell script'
F_NAME='linux_shell'

cat > $F_NAME << HERE
$FROM
$TO
$SUBJECT
$MESSAGE

HERE

exit 0
