#!/usr/bin/env ruby

include Math

def rotate(x, a)
	[x[0]*Math.cos(a)-x[1]*Math.sin(a), x[0]*Math.sin(a)+x[1]*Math.cos(a)]
end

def koch_curve(a, b, n)
	if n == 0
		puts a.join(" ")
	else
		m1 = b.zip(a).map { |x| x.reduce(:-) / 3.0 }.zip(a).map { |x| x.reduce(:+) }
		m2 = b.zip(a).map { |x| x.reduce(:-) * 2.0 / 3.0 }.zip(a).map { |x| x.reduce(:+) }
		x = rotate(m2.zip(m1).map { |x| x.reduce(:-) }, Math::PI/3).zip(m1).map { |x| x.reduce(:+) }
		koch_curve(a, m1, n-1)
		koch_curve(m1, x, n-1)
		koch_curve(x, m2, n-1)
		koch_curve(m2, b, n-1)
	end
end

n = gets.to_i
st = [0, 0]
ed = [100, 0]
koch_curve(st, ed, n)
puts ed.join(" ")
