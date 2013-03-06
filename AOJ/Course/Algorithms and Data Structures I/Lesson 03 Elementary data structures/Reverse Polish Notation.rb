#!/usr/bin/env ruby

class String
	def is_i?
		begin
			!!Integer(self)
		rescue ArgumentError, TypeError
			false
		end
	end
end

s = gets.split
q = []

for i in s do
	if !i.is_i?
		y = q.pop
		x = q.pop
		case i
		when "+"
			q.push(x+y)
		when "-"
			q.push(x-y)
		when "*"
			q.push(x*y)
		end
	else
		q.push(i.to_i)
	end
end
puts q.last
