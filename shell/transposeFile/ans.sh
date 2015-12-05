# Only awk
awk '
{
    for (i = 1; i <= NF; i++) {
        if (NR == 1) {
            s[i] = $i
        } else {
            s[i] = s[i] " " $i
        }
    }
}
END {
    for (i = 1; s[i] != ""; i++) {
        print s[i];
    }
}'  file.txt

echo -e "\n"
# Shell script forloop
length=`head -n 1 file.txt| wc -w`

for (( i = 1; i <= $length; i++))
do
    awk '{print $'"$i"'}' file.txt | tr -s '\n' ' ' 
#    echo `cut -d' ' -f$i file.txt`
    echo ""
done

## Use file
#echo "name" > tmp
#cat file.txt  | tail -n +2 | awk '{print $1}' >> tmp
#cat tmp | tr -s '\n' ' '
#
#echo -e ""
#echo "age" > tmp
#cat file.txt  | tail -n +2 | awk '{print $2}' >> tmp
#cat tmp | tr -s '\n' ' '
#
