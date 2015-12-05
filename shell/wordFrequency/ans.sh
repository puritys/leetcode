echo -e "Use grep \n==============\n"
cat words.txt | grep -o '[a-z]*' | sort | uniq -c | sort -r | awk '{printf "%s %d\n", $2,$1}'

echo -e "\n\nUse tr \n==============\n"
cat words.txt  | tr -s ' ' '\n' | sort | uniq -c | sort -r | awk '{print $2, $1}'

#cat words.txt  | sed -e  's/[[:blank:]]\{1,\}/\n/g'  | sort | uniq -c | sort -r | awk '{print $2, $1}'
