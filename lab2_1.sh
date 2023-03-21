if [ $# -eq 0 ]
then
	echo "No numbers to add"
else
	for i in $@; do
		sum=$((sum+i))
	done
	echo $sum
fi
exit
