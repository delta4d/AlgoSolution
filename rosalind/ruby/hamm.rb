#!/usr/bin/env ruby

a, b = gets, gets
tot = 0
a.length.times { |i| tot = tot + 1 if a[i] != b[i] }
puts tot
