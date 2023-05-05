#!/bin/bash
if [ "$(uname)" != "Linux" ]
then
	echo This script will only run only Linux operating system
	exit 4
fi

if [ "$2" = "" ]
then
	echo Please provide the path to the project directory as the first argument
	echo Please provide the path to the name of the maps directory as the second argument
	exit 3
fi

check_leaks()
{
	#I don't fully understand anonymous pipes atm
	#error="$(valgrind $2/so_long $1 2> >(grep ERROR) | awk -F " " '{print $4}')"
	error="$(valgrind --leak-check\=full $2/so_long $1 2>&1 | grep ERROR | awk -F " " '{print $4}')"
	if [ "$error" != "0" ]
	then
		echo "The file $1 raised a valgrind error"
		echo "The number of errors is $error"
		exit 3
	else
		echo "The file $1 raised no leak"
	fi
}

make debug CC=gcc -C $1

find $1/$2 -type f -name \*.ber | while read file; do check_leaks $file $1; done
