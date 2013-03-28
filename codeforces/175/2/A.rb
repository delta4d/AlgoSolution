#!/usr/bin/env ruby

n, k = gets.split.collect{ |i| i.to_i }

k.downto(0) { |i| print "#{i+1} " }
(k+2).upto(n) { |i| print "#{i} " }

# 3411815	 Mar 27, 2013 4:31:05 PM	delta_4d	 285A - Slightly Decreasing Permutations	 Ruby	Accepted	 140 ms	 0 KB
