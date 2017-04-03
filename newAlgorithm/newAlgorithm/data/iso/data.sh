# /bin/bash
# @author: hengzi
# @date: 2017-01-26

#ls -l | grep "^d" | awk '{print $9}'

ls $1 > $1".txt"
cat $1".txt" | grep A | sort -n > $1"A.txt"
cat $1".txt" | grep B | sort -n > $1"B.txt"
