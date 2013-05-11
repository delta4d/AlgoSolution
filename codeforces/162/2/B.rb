#!/usr/bin/env ruby

n, x, tot = gets.to_i, [], 0
n.times { x << gets.to_i }
x.each_index { |i| tot = tot + (x[i] - x[i+1]).abs if i + 1 < n }
puts tot + n + n - 1 + x[0]

# 3702744	 May 11, 2013 6:42:11 PM	delta_4d	 B - Roadside Trees (Simplified Edition)	 Ruby	Accepted	234 ms	804 KB
