#!/usr/bin/env ruby

s, t, cp = gets.chomp, gets.chomp, 0
x = []

while !(cp = s.index(t, cp)).nil?
	cp = cp + 1
	x << cp
end

puts x.join(' ')
