#!/bin/bash
date
ruptime
rwho
whoami
tty
hostname
uname -a
finger 'desoo'
ls -a
echo "Hello, my darling!" > f1.txt
cat f1.txt
cp f1.txt f2.txt
cat f1.txt f2.txt >> f3.txt
rm f1.txt f2.txt
mkdir lab2
mv f3.txt /home/desoo/lab2
cd /home/desoo/lab2
pwd 
ls
cat f3.txt
cd ~
pwd
touch f1.sha f2.sha fhf3.sha fkkn.sha f5.sha f234.sha
mkdir many
ls
mv f*.sha many
# Move files with only one symbol after *, if I add *** let's see what's happened
mv f***.sha many
cd many
ls | wc -l
# wc -l counting amount of files in directory
cd
rm many
# we can't delete directory with rm, let's try rmdir
rmdir many 
# ops, this command delete only empty direcroty :( OK, last try - rm -r
rm -r many
# Yahoo, greate. OK, it's time for clean up
rm -r lab2
ls -1
# Excellent






# Способ №1
# Самое удобное для Вас решение -- сначала вывести все команды (текст скрипта), затем запустить скрипт и сохранить его результат.

# Чтобы поместить вывод скрипта в какой-то файл, сделайте так: ./имя_моего_скрипта.sh > файл_с_результатами.txt
# '>' -- это перенаправление вывода (например, вместо консоли открывается какой-то файл и всё записывается в него)
# '>>' -- это тоже перенаправление вывода, но по принципу "дописывания", а не перезаписи. То есть файл открывается,
# находится его конец, и запись ведётся именно за этот конец. В случае с '>' файл открывается и пишется с первого байта.

# Предположим, Вы оттестировали команды и записали их в скрипт my_little_lovely_script.sh. Что теперь?
# cat my_little_lovely_script.sh > protocol.txt
# ./my_little_lovely_script.sh >> protocol.txt
# Сначала Вы записали в файл protocol.txt все команды (по факту, просто вывели файл my_little_lovely_script.sh),
# а затем дописали в protocol.txt результат выполнения скрипта.


