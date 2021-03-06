echo -e "Use sed \n============\n"
cat file.txt | sed  -n -r '/^(\([0-9]{3}\) |[0-9]{3}-)[0-9]{3}-[0-9]{4}$/p'

echo -e "\n\nUse grep\n============\n"
cat file.txt  |grep '^([0-9]*) [0-9]\{3\}-[0-9]\{4\}$\|^([0-9]*) [0-9]\{3\}-[0-9]\{3\}-[0-9]\{4\}$\|^[0-9]\{3\}-[0-9]\{4\}$\|^[0-9]\{3\}-[0-9]\{3\}-[0-9]\{4\}$'
