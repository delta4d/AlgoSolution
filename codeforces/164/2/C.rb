#!/usr/bin/env ruby

n = gets.split.collect{|i| i.to_i}.min

puts n + 1

0.upto(n) { |i| puts "#{i} #{n-i}" }

# 3481829	 Apr 7, 2013 4:38:38 PM	delta_4d	 268C - Beautiful Sets of Points	 Ruby	Accepted	62 ms	0 KB
