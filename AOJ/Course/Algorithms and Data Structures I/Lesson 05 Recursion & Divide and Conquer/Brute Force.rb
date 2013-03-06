#!/usr/bin/env ruby

ok = Array.new(21*2001, false)
ok[0] = true
n = gets.to_i
sum = 0
x = gets.split.collect!{ |i| i.to_i }
for ee in x
	sum += ee
end
for ee in x
	sum.downto(0) do |i|
		ok[i+ee] = true if ok[i] && i + ee <= sum
	end
end
m = gets.to_i
y = gets.split.collect!{ |i| i.to_i }
for ee in y
	if ok[ee]
		puts "yes"
	else
		puts "no"
	end
end
