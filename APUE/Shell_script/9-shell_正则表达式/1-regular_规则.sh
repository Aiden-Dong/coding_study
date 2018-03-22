#!/bin/bash

sed -e 's/.*/[&]/g'<<EOF
First_line
Secound_line
EOF

echo

awk '{$0=$1 "\n" $2; if (/.line/) {print}}' << EOF
Third_line
Fourth_line
EOF

exit 0
