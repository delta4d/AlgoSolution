#!/usr/bin/env ruby

rr = 0
cc = ""
c = gets

while true
	begin
		s = gets
		ss = ""
		while s[0] != '>'
			ss += s
			s = gets
		end
		ss.gsub!("\n", "")
		r = (ss.count('C') + ss.count('G')) * 1.0 / ss.length 
		cc, rr = c, r if r > rr
		c = s
	rescue
		ss.gsub!("\n", "")
		r = (ss.count('C') + ss.count('G')) * 1.0 / ss.length 
		cc, rr = c, r if r > rr
		break
	end
end

puts cc[1..-1]
puts rr*100
