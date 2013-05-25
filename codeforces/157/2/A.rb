#!/usr/bin/env ruby

8.times do
	s = gets
	7.times do |i|
		if s[i] == s[i+1]	
			puts "NO"
			exit
		end
	end
end
puts "YES"

# 3765613	 May 24, 2013 7:08:52 PM	delta_4d	 A - Little Elephant and Chess	 Ruby	Accepted	62 ms	8 KB
