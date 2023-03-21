while IFS=$'\t' read -a line
do
    ltCheck=$(($1-1))
    gtCheck=$(($1+1))
    if [ $1 -eq ${line[3]} ] || [ $ltCheck -eq ${line[3]} ] || [ $gtCheck -eq ${line[3]} ]
    then
        echo "${line[0]} ${line[1]}"
    fi    
done < "inv.txt"