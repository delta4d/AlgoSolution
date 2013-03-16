#!/usr/bin/env ruby

v = 0
n = gets.to_i
n.times{ gets.count('+') > 0 ? v += 1 : v -= 1 }
puts v

# 3316891	 Mar 14, 2013 7:15:26 PM	delta_4d	 282A - Bit++	 Ruby	Accepted	 62 ms	 0 KB
