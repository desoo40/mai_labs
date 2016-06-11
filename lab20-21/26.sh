#!/bin/bash

find ./* > tmp

max=`wc -l < tmp`
i=1
sum=0
prev="May"

while [[ $i -lt $((max+1)) ]]; do
	file=`cat tmp | head -$i | tail -1`

	b=`ls -l $file | head -1 | awk '{print $6}'`

	if [[ "$b" == "$prev" ]]; then
		#echo google
		echo $file
		i=$(($i+1))
		continue
	fi

	i=$(($i+1))
done

echo $sum

rm -rf tmp