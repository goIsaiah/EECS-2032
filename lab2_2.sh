wordFound=0

if [ -e $2 ]; then
	while read line; do
		if [[ $line == *$1* ]]; then
			wordFound=1; fi
	done < "$2"
	if [ $wordFound -eq 1 ]; then
		echo "$1 does exist in $2"
	else
		echo "$1 does not exist $2"; fi
else
	echo "$2 does not exist"
fi
