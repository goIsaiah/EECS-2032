while read -a list
do
    len=${#list[@]}
    check=$((${list[1]}+${list[2]}))
    if [ ${list[0]} -gt $check ]
    then
        for (( i=0; i<$len; i++ ))
        do
            echo -n "${list[i]} "
        done
        echo ""
    fi
done < "p2a.txt"
exit


