#!/usr/bin/env ruby

k, m, n = gets.split.collect{ |i| i.to_i }
t = k + m + n
puts 1.0 - (n * (n - 1) + m * n + m * (m - 1) / 4.0) / (t * (t - 1))
