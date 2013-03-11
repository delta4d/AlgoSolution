#!/usr/bin/env ruby

n, m = gets.split.collect{ |i| i.to_i }
dp = Array.new(n+1){ Array.new(m, 0) }

dp[0][0] = 1

n.times do |i|
	dp[i+1][1] += dp[i][0]
	dp[i+1][0] += dp[i][m-1]
	1.upto(m-2) do |j|
		dp[i+1][j+1] += dp[i][j]
		dp[i+1][0] += dp[i][j]
	end
end

#n.times { |i| puts dp[i].join(' ') }

tot = 0
dp[n-1].each { |i| tot += i }
puts tot
