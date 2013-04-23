#!/usr/bin/env ruby

n = gets.to_i
s = gets
tot = 0
0.upto(n-2) { |i| tot += 1 if s[i] == s[i+1] }	
puts tot

# 3600254	 Apr 22, 2013 2:01:36 PM	delta_4d	 266A - Stones on the Table	 Ruby	Accepted	 62 ms	 0 KB
