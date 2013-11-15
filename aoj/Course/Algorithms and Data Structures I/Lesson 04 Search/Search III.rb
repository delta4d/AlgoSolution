#!/usr/bin/env ruby

mp = {}
n = gets.to_i
n.downto(1) do
	op, str = gets.split
	if op == "insert"
		mp[str] = 0
	else
		if mp.has_key?(str)
			puts "yes"
		else
			puts "no"
		end
	end
end
