#!/usr/bin/env sh
# split the files to different dir

for i in $(ls); do
	x=${i%.*}
	x=${x%%\'*}
	if [[ $x =~ ^[0-9]{4}$ ]]; then
		d=$((x/100-9))
		d=`printf "%02d" $d`
		[[ ! -d $d ]] && mkdir $d
		git mv $i $d
	fi
done

# vim:ts=4
