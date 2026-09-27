tr -s '[:space:]' '\n' < words.txt |
grep -v '^$' |
sort |
uniq -c |
sort -rn |
awk '{ print $2, $1 }'
