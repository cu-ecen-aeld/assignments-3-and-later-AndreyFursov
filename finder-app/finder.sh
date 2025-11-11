#!/bin/sh
filesdir=$1
searchstr=$2
if [ $# -eq 0 ]
then
	echo "Parameters are absent"
	exit 1
fi
if [ -d $filesdir ]
then
	#echo "str $searchstr"
	#echo "dir $filesdir"
	# num of all files in $filesdir
	X=$(ls -l -R $filesdir |grep "^-" | wc -l)
	#echo "files: $X"
	#find files with $searchstr
	Y=$(grep -r $searchstr $filesdir | wc -l) 
	#echo "findes: $Y"
	echo "The number of files are $X and the number of matching lines are $Y"
	exit 0
else 
	echo "\"$filesdir\" isn't a directory"
	exit 1
fi
exit 0

 

