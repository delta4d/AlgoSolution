#!/usr/bin/env ruby

n, s, t = gets.split.collect{ |i| i.to_i }
p = gets.split.collect{ |i| i.to_i - 1 }

s = s - 1
t = t - 1
n.times do |i|
	if s == t
		puts i
		exit
	end
	s = p[s]
end

puts -1

# 3411872	 Mar 27, 2013 4:47:39 PM	delta_4d	 285B - Find Marble	 Ruby	Accepted	203 ms	5500 KB
