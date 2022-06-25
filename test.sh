#!/bin/bash

MAX=1000
ITERATIONS=10
LIMIT=5500
FILE=problem_100
SUM=0

for i in {1..3}
do
 export ARG=`ruby -e "puts (0..100).to_a.shuffle.join(' ')"`
# echo $ARG
 if ./push_swap $ARG | ./checker $ARG | grep -q OK
 then
  echo "Error!"
  echo $ARG
  break
 fi
 NUMBER="$(./push_swap $ARG | wc -l | sed 's/ //g')"
 if [ "$NUMBER" -gt "$LIMIT" ]
  then
  echo $NUMBER >> $FILE
  echo $ARG >> $FILE
 fi
 if [ "$NUMBER" -gt "$MAX" ]
  then
  MAX=$NUMBER;
 fi
 echo $i ":" $NUMBER
 let SUM+=$NUMBER;
 let ITERATIONS+=1

done

echo "AVG: $(($SUM / $ITERATIONS))"
echo "MAX: " $MAX