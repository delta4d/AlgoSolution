#!/usr/bin/env ruby

n, m = gets.split.map(&:to_i)
x = gets.split.map(&:to_i)
a, b = x.count(-1), x.count(1)
m.times do
	l, r = gets.split.map(&:to_i)
	l = r - l + 1
	if l % 2 == 1
		puts 0
	else
		l = l / 2
		puts a >= l && b >= l ? 1 : 0
	end
end

# 3684774	 May 6, 2013 10:08:07 AM	delta_4d	 A - Eugeny and Array	 Ruby	Accepted	1500 ms	10900 KB
