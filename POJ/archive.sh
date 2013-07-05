#!/usr/bin/env bash
# deal with POJ archive
# split it into probnumber.lang
# multiple AC solutions follows pattern probnumber-version.lang

dst=$(pwd)/ac_solutions
mkdir $dst

for dire in $(ls); do
	cd $dire
	num=0
	for file in $(ls); do
		if [[ "$file" =~ .*AC.* ]]; then
			ofile=$dire
			((num>0)) && ofile=$ofile-$num
			ofile=$ofile.${file##*.}
			#echo $ofile
			cp $file $dst/$ofile
			((num=num+1))
		fi
	done
	cd ..
done
