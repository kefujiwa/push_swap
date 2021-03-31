#!/bin/bash

COUNT=200

INDEX=0
MAX3=0
MAX5=0
MAX100=0
MAX500=0
TMP=0
FILE1="test/max_arg3.txt"
FILE2="test/max_arg5.txt"
FILE3="test/max_arg100.txt"
FILE4="test/max_arg500.txt"

while [ "$INDEX" -lt "$COUNT" ]
do

ARG=`jot -r -s " " 3 -2147483648 2147483647`
./push_swap $ARG | ./checker $ARG | xargs echo -n
TMP=`./push_swap $ARG | wc -l`
if [ $TMP -gt $MAX3 ] ; then
    MAX3=$TMP
    echo $ARG > $FILE1
fi
echo -n " $TMP  "

ARG=`jot -r -s " " 5 -2147483648 2147483647`
./push_swap $ARG | ./checker $ARG | xargs echo -n
TMP=`./push_swap $ARG | wc -l`
if [ $TMP -gt $MAX5 ] ; then
    MAX5=$TMP
    echo $ARG > $FILE2
fi
echo -n " $TMP  "

ARG=`jot -r -s " " 100 -2147483648 2147483647`
./push_swap $ARG | ./checker $ARG | xargs echo -n
TMP=`./push_swap $ARG | wc -l`
if [ $TMP -gt $MAX100 ] ; then
    MAX100=$TMP
    echo $ARG > $FILE3
fi
echo -n " $TMP  "

ARG=`jot -r -s " " 500 -2147483648 2147483647`
./push_swap $ARG | ./checker $ARG | xargs echo -n
TMP=`./push_swap $ARG | wc -l`
if [ $TMP -gt $MAX500 ] ; then
    MAX500=$TMP
    echo $ARG > $FILE4
fi
echo " $TMP"

let INDEX++
done
echo
echo "[ARG 3]    MAX = " $MAX3
echo "[ARG 5]    MAX = " $MAX5
echo "[ARG 100]  MAX = " $MAX100
echo "[ARG 500]  MAX = " $MAX500
echo
echo "cat $FILE1"
echo "cat $FILE2"
echo "cat $FILE3"
echo "cat $FILE4"
echo
echo "./push_swap \`cat $FILE1\` | wc -l"
echo "./push_swap \`cat $FILE2\` | wc -l"
echo "./push_swap \`cat $FILE3\` | wc -l"
echo "./push_swap \`cat $FILE4\` | wc -l"
echo
