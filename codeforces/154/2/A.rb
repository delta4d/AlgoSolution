n, m = File.open("input.txt").gets.split.map(&:to_i)
output = File.open("output.txt", "w")
while n > 0 || m > 0
	if (n >= m)
		output.print 'B'
		output.print 'G' if m > 0
	else
		output.print 'G'
		output.print 'B' if n > 0
	end
	n, m = n - 1, m - 1
end

# 3823614	 Jun 5, 2013 8:43:02 AM	delta_4d	 A - Boys and Girls	 Ruby	Accepted	 46 ms	 0 KB
