read -a list
ELEMENTS=${#list[@]}

if [${ELEMENTS}<3]
then
	echo
else
	for ((i=2;i<${ELEMENTS};i++)); do
		echo -n "${list[$i]} "
	done
fi
echo
exit
