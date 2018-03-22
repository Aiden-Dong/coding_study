#!/bin/bash

read name

case "$name" in
	mary|roland|"jack")
		echo "welcome back"
		echo "long time no to see"
		echo "how do you do"
	;;
	may|joe)
		echo "welcome ...."
		echo "what do you want to do"
	;;
esac

exit 0

