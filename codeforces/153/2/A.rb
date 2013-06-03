n = gets.to_i
x = gets.split.map(&:to_i).unshift(0)
n.times { |i| x[i+1] ^= x[i] }
mx = 0
1.upto(n) do |i|
	i.upto(n) do |j|
		mx = [mx, x[j] ^ x[i-1]].max
	end
end
puts mx

# 3818370	 Jun 3, 2013 2:49:11 PM	delta_4d	 A - Little Xor	 Ruby	Accepted	46 ms	0 KB
