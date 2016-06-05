#!/bin/bash

# all *.h, *.c files in current dir and subdir
# lines counts

ls -R ./ | awk '
/:$/&&f{s=$0;f=0}
/:$/&&!f{sub(/:$/,"");s=$0;f=1;next}
NF&&f{ print s"/"$0 }' > t.mp 

cat t.mp | grep "\.h$\|\.cpp$\|\.c$" > t2.mp

max=`wc -l < t2.mp`
i=1
sum=0

while [[ $i -lt $((max+1)) ]]; do
	file=`cat t2.mp | head -$i | tail -1`
	lines=`wc -l < $file`
	echo $file '==' $lines
	sum=$(($sum+$lines))
	i=$(($i+1))
done

echo $sum

rm -rf *.mp