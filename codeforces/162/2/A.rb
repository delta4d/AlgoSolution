#!/usr/bin/env ruby

s, t, p = gets.strip, gets.strip, 0
t.each_char { |i| p = p + 1 if s[p] == i }
puts p + 1

# 3702705	 May 11, 2013 6:29:41 PM	delta_4d	 A - Colorful Stones (Simplified Edition)	 Ruby	Accepted	31 ms	8 KB
