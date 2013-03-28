#!/usr/bin/env ruby

n = gets.to_i + 1
tot, cc = 0, 0
gets.split.collect{ |i| i.to_i }.each{ |i| tot += i }
1.upto(5) { |i| cc += 1 if (tot + i) % n != 1 }
puts cc

# 3416357	 Mar 28, 2013 8:05:22 PM	delta_4d	 272A - Dima and Friends	 Ruby	Accepted	62 ms	0 KB
