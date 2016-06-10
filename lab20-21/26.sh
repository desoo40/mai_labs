#!/bin/bash

find ./* > tmp

max=`wc -l < tmp`
i=1
sum=0

while [[ $i -lt $((max+1)) ]]; do
	file=`cat tmp | head -$i | tail -1`

	b=`ls -l $file | head -1 | awk '{print substr($0,0,2)}'`

	if [[ "$b" == "t" ]]; then
		#echo google
		i=$(($i+1))
		continue
	fi

	a=`ls -l $file | awk ' {print $1} ' | grep x`

	if [[ "$a" ]]; then
		sum=$((sum+1))
		echo $file EXECUTED
	fi

	i=$(($i+1))
done

echo $sum

rm -rf tmp