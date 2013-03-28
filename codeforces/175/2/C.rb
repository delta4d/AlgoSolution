#!/usr/bin/env ruby

gets
tot = 0
gets.split.collect{ |i| i.to_i }.sort.each_with_index { |x, i| tot += (i + 1 - x).abs }
puts tot

# 3411935	 Mar 27, 2013 5:01:54 PM	delta_4d	 285C - Building Permutation	 Ruby	Accepted	1015 ms	23700 KB
