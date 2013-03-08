#!/usr/bin/env ruby

DNA="ACGT"
s=gets
DNA.each_char do |i|
	print s.count(i), i == 'T' ? "\n" : " "
end
