#!/usr/bin/env ruby

n, x0 = gets.split.map(&:to_i)
x, y = -1000, 1000
n.times do
	a, b = gets.split.map(&:to_i)
	a, b = b, a if a > b
	x, y = [x, a].max, [y, b].min
end
puts x > y ? -1 : (x <= x0 && x0 <= y ? 0 : [x - x0, x0 - y].max)

# 3792875	 May 30, 2013 7:40:34 AM	delta_4d	 B - Young Photographer	 Ruby	Accepted	46 ms	52 KB
