list=("$@")
ELEMENTS=${#list[@]}

if [ $# -ne 3 ]
then
	echo "Just three numbers please"
else
	if [ ${list[0]} -eq ${list[1]} ] || [ ${list[0]} -eq ${list[2]} ] || [ ${list[1]} -eq ${list[2]} ]
	then
		echo "Sorry median here does not mean anything"
	elif ([ ${list[0]} -lt ${list[1]} ] && [ ${list[0]} -gt ${list[2]} ]) || ([ ${list[0]} -gt ${list[1]} ] && [ ${list[0]} -lt ${list[2]} ]); then
		echo ${list[0]}
	elif ([ ${list[1]} -lt ${list[0]} ] && [ ${list[1]} -gt ${list[2]} ]) || ([ ${list[1]} -gt ${list[0]} ] && [ ${list[1]} -lt ${list[2]} ]); then
		echo ${list[1]}
	elif ([ ${list[2]} -lt ${list[0]} ] && [ ${list[2]} -gt ${list[1]} ]) || ([ ${list[2]} -gt ${list[0]} ] && [ ${list[2]} -lt ${list[1]} ]); then
		echo ${list[2]}
	fi
fi
exit
