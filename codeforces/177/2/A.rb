#!/usr/bin/env ruby

n, k = gets.split.collect{|i| i.to_i}
tot = 0
n.times do
	x, y = gets.split.collect{|i| i.to_i}
	tot = (tot + y - x + 1) % k
end

puts (tot == 0 ? 0 : k - tot)

# 3467113	 Apr 3, 2013 9:33:32 AM	delta_4d	 289A - Polo the Penguin and Segments	 Ruby	Accepted	 546 ms	 0 KB
