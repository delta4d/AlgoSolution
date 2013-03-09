#!/usr/bin/env ruby

class String
	def cc(a, b)
		self.gsub(a, '*').gsub(b, a).gsub('*', b)
	end
end

puts gets.reverse.cc('A', 'T').cc('C', 'G')
