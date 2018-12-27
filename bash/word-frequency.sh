#https://leetcode-cn.com/problems/word-frequency/
awk '{for(i=1; i<=NF; i++){if ($i != ""){print $i}}}' words.txt | sort | uniq -c | sort -rk2 -n | awk '{print $2" "$1}'
