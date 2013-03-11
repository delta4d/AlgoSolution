#!/usr/bin/env ruby

class DNA
	attr_accessor :name, :dna
	def initialize(name, dna)
		@name = name
		@dna = dna
	end
	def linked?(x)
		@dna[-3..-1] == x.dna[0..2]
	end
end

x = []

name = gets.chomp
while true
	begin
		s = gets.chomp
		dna = ""
		while s[0] != '>'
			dna += s
			s = gets.chomp
		end
		x << DNA.new(name[1..-1], dna)
		name = s
	rescue
		x << DNA.new(name[1..-1], dna)
		break
	end
end

n = x.size
n.times do |i|
	n.times do |j|
		next if i == j
		if x[i].linked?(x[j])
			puts "#{x[i].name} #{x[j].name}"
		end
	end
end
