#!/bin/bash

RESET="\x1b[0m"
BLACK="\x1b[30m"
RED="\x1b[31m"
GREEN="\x1b[32m"
YELLOW="\x1b[33m"
BLUE="\x1b[34m"
MAGENTA="\x1b[35m"
CYAN="\x1b[36m"
WHITE="\x1b[37m"
BOLDBLACK="\x1b[1m\x1b[30m"
BOLDRED="\x1b[1m\x1b[31m"
BOLDGREEN="\x1b[1m\x1b[32m"
BOLDYELLOW="\x1b[1m\x1b[33m"
BOLDBLUE="\x1b[1m\x1b[34m"
BOLDMAGENTA="\x1b[1m\x1b[35m"
BOLDCYAN="\x1b[1m\x1b[36m"
BOLDWHITE="\x1b[1m\x1b[37m"

COUNT=100
INDEX=0
MAX3=0
MAX5=0
MAX100=0
MAX500=0
FILE3="test/max_arg3.txt"
FILE5="test/max_arg5.txt"
FILE100="test/max_arg100.txt"
FILE500="test/max_arg500.txt"
FILEKO="test/result_ko.txt"
FILEERR="test/result_err.txt"

printf "[ARGS 3]   \t  [ARGS 5]   \t  [ARGS 100]   \t  [ARGS 500]\n"
while [ "$INDEX" -lt "$COUNT" ]
do

ARG=`jot -r -s " " 3 -2147483648 2147483647`
RESULT=`./push_swap $ARG | ./checker $ARG | xargs echo -n`
if [ $RESULT = "OK" ] ; then
	printf "$GREEN%s$RESET " "[OK]"
elif [ $RESULT = "KO" ] ; then
	printf "$RED%s$RESET " "[KO]"
    echo $ARG >> $FILEKO
else
	printf "$YELLOW%s$RESET " "[ER]"
    echo $ARG >> $FILEERR
fi
TMP=`./push_swap $ARG | wc -l | tr -d ' '`
if [ $TMP -gt $MAX3 ] ; then
    MAX3=$TMP
    echo $ARG > $FILE3
fi
printf "cnt: $TMP\t| "

ARG=`jot -r -s " " 5 -2147483648 2147483647`
RESULT=`./push_swap $ARG | ./checker $ARG | xargs echo -n`
if [ $RESULT = "OK" ] ; then
	printf "$GREEN%s$RESET " "[OK]"
elif [ $RESULT = "KO" ] ; then
	printf "$RED%s$RESET " "[KO]"
    printf "$ARG\n\n" >> $FILEKO
else
	printf "$YELLOW%s$RESET " "[ER]"
    printf "$ARG\n\n" >> $FILEKO
fi
TMP=`./push_swap $ARG | wc -l | tr -d ' '`
if [ $TMP -gt $MAX5 ] ; then
    MAX5=$TMP
    echo $ARG > $FILE5
fi
printf "cnt: $TMP\t| "

ARG=`jot -r -s " " 100 -2147483648 2147483647`
RESULT=`./push_swap $ARG | ./checker $ARG | xargs echo -n`
if [ $RESULT = "OK" ] ; then
	printf "$GREEN%s$RESET " "[OK]"
elif [ $RESULT = "KO" ] ; then
	printf "$RED%s$RESET " "[KO]"
    printf "$ARG\n\n" >> $FILEKO
else
	printf "$YELLOW%s$RESET " "[ER]"
    printf "$ARG\n\n" >> $FILEKO
fi
TMP=`./push_swap $ARG | wc -l | tr -d ' '`
if [ $TMP -gt $MAX100 ] ; then
    MAX100=$TMP
    echo $ARG > $FILE100
fi
printf "cnt: $TMP\t| "

ARG=`jot -r -s " " 500 -2147483648 2147483647`
RESULT=`./push_swap $ARG | ./checker $ARG | xargs echo -n`
if [ $RESULT = "OK" ] ; then
	printf "$GREEN%s$RESET " "[OK]"
elif [ $RESULT = "KO" ] ; then
	printf "$RED%s$RESET " "[KO]"
    printf "$ARG\n\n" >> $FILEKO
else
	printf "$YELLOW%s$RESET " "[ER]"
    printf "$ARG\n\n" >> $FILEKO
fi
TMP=`./push_swap $ARG | wc -l | tr -d ' '`
if [ $TMP -gt $MAX500 ] ; then
    MAX500=$TMP
    echo $ARG > $FILE500
fi
echo "cnt: $TMP"

let INDEX++
done
echo
printf "MAX = $MAX3   \t|  MAX = $MAX5   \t|  MAX = $MAX100   \t|  MAX = $MAX500\n"
echo
