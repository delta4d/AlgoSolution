#!/usr/bin/env ruby

n, k = gets.split.collect{ |i| i.to_i }

x1, x2 = 0, 1
n.times { x1, x2 = x2, x2+k*x1 }
puts x1
