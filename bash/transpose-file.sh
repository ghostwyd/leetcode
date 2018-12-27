#https://leetcode-cn.com/problems/transpose-file/
column=`head -n 1 file.txt | awk '{print NF}'`
line=`wc -l file.txt`
i=1
while [ $i -le $column ];do
    awk -v k=$i '{if (NR == 1){printf $k}else{printf " "$k}}END{printf "\n"}' file.txt
    ((i++))
done
