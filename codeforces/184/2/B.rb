p, q = gets.split.map(&:to_i)
d = p.gcd(q)
p, q = p / d, q / d
n = gets.to_i
a = gets.split.map(&:to_i)
x, y = a[n-1], 1
(n-2).downto(0) do |i|
	x, y = y, x
	x = x + a[i] * y
end
if x == p && y == q
	puts "YES"
else
	puts "NO"
end

# 3738444	 May 19, 2013 5:24:18 PM	* delta_4d	 B - Continued Fractions	 Ruby	Accepted	 46 ms	 0 KB
