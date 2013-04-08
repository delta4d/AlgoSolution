#!/usr/bin/env ruby

n = gets.to_i
x = []
y = []

n.times do
	a, b = gets.split.collect{|i| i.to_i}
	x << a
	y << b
end

tot = 0
n.times do |i|
	n.times do |j|
		next if i == j
		tot = tot + 1 if x[i] == y[j]
	end
end

puts tot

# 3481355	 Apr 7, 2013 2:30:11 PM	delta_4d	 268A - Games	 Ruby	Accepted	46 ms	0 KB
