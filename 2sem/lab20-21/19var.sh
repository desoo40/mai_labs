#!/bin/bash

# all *.h, *.c files in current dir and subdir
# lines counts

find . -regex ".*\.\(h\|cpp\|c\)" > tmp

max=`wc -l < tmp`
i=1
sum=0

while [[ $i -lt $((max+1)) ]]; do
	file=`cat tmp | head -$i | tail -1`
	lines=`wc -l < $file`
	echo $file '==' $lines
	sum=$(($sum+$lines))
	i=$(($i+1))
done

echo $sum

rm -rf tmp