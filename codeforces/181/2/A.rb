#!/usr/bin/env ruby

n = gets.to_i
x = gets.split.collect{|i| i.to_i}
a, b, c = [], [], []
x.each do |i|
	if i < 0 && a.size == 0
		a << i
	elsif i > 0 && b.size == 0
		b << i
	else
		c << i
	end
end

if b.size == 0
	2.times do
		c.each do |i|
			if b.size < 2 && i < 0
				b << i
				c.delete(i)
				break
			end
		end
	end
end

puts "#{a.size} #{a.join(" ")}"
puts "#{b.size} #{b.join(" ")}"
puts "#{c.size} #{c.join(" ")}"

# 3643575 Apr 27, 2013 5:47:59 PMdelta_4d 300A - Array RubyAccepted 46 ms 0 KB
