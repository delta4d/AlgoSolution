#!/usr/bin/env ruby

n = (gets.to_i + 1) >> 1
x = gets.split.collect{ |i| i.to_i }
x.each do |i|
	if x.count(i) > n
		puts "NO"
		exit
	end
end

puts "YES"

# 3516228	 Apr 12, 2013 10:55:02 AM	delta_4d	 296A - Yaroslav and Permutations	 Ruby	Accepted	 62 ms	 0 KB
