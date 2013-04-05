#!/usr/bin/env ruby

y = gets.to_i + 1
y.upto(10234) do |i|
	if i.to_s.chars.sort.uniq.size == i.size
		puts i
		break
	end
end

# 3475371	 Apr 5, 2013 9:10:12 AM	delta_4d	 271A - Beautiful Year	 Ruby	Accepted	46 ms	0 KB
