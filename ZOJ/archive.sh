#!/usr/bin/env sh

for i in $(ls); do
	x=${i%.*}
	x=${x%%\'*}
	if [[ $x =~ ^[0-9]+$ ]]; then
		d=$((x/100-9))
		d=`printf "%02d" $d`
		[[ ! -d $d ]] && mkdir $d
		mv $i $d
	fi
done
