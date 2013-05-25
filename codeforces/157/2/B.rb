#!/usr/bin/env ruby

x, a, b = gets.split.map(&:to_i)
c, y, d = gets.split.map(&:to_i)
e, f, z = gets.split.map(&:to_i)
x = e + (f - a) / 2
z = b - (f - a) / 2
y = e + f - c - d + z
puts "#{x} #{a} #{b}"
puts "#{c} #{y} #{d}"
puts "#{e} #{f} #{z}"

# 3765629	 May 24, 2013 7:14:39 PM	delta_4d	 B - Little Elephant and Magic Square	 Ruby	Accepted	46 ms	24 KB
