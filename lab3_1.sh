file="courses.txt"
if [ "$1" == "nobook" ] && [ $# -eq 1 ]
then
	sed -e '/!R/d' courses.txt
	exit
fi

if [ "$1" == "-num" ]; then
	course_number=$2
	while read line; do
       		IFS="!" read -a course_info <<< "$line"
        	course_code=${course_info[0]}
        	if [ "$course_number" == "$course_code" ]; then
            		ISBN=$(echo $line | cut -d'!' -f3)
            		book=$(grep "^.*!$ISBN!" books.txt)
            		title=$(echo $book | cut -d'!' -f1)
            		authors=$(echo $book | cut -d'!' -f3-)
            		authors=$(echo $authors | tr '!' ' ')
            		echo "$title: $authors"
        	fi
    	done < $file
fi

if [ "$1" == "-toomuch" ]
then
	file="courses.txt"
	declare -A sumArr

	while read line; do
    		IFS="!" read -a course_info <<< "$line"
    		course=${course_info[0]}
    		if [ -z "${sumArr[$course]}" ]; then
        		sumArr[$course]=1
    		else
        		let sumArr[$course]=sumArr[$course]+1
    		fi
	done < $file

	for i in "${!sumArr[@]}"; do
    		echo "$i requires ${sumArr[$i]} textbooks"
	done
fi
