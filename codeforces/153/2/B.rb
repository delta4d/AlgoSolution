n = gets.to_i
x = gets.split.map(&:to_i)

if n == 2
	puts "-1"
	exit 0
end

mn = x.min
k = x.index(mn)
lmx = x[0..k-1].max
rmx = x[k+1..-1].max
if 0 < k && k + 1 < n && lmx > mn && rmx > mn
	if lmx != rmx
		puts "#{x[0..k-1].index(lmx)+1} #{x[k+1..-1].index(rmx)+k+2}"
	else
		1.upto(k-1) do |i|
			if x[i] != mn
				puts "#{i+1} #{k+1}"
				exit 0
			end
		end
		(k+1).upto(n-2) do |i|
			if x[i] != mn
				puts "#{k+1} #{i+1}"
				exit 0
			end
		end
		if n == 3
			puts -1
			exit 0
		end
		puts "1 2"
	end
	exit 0
end

mx = x.max
k = x.index(mx)
lmn = x[0..k-1].min
rmn = x[k+1..-1].min
if 0 < k && k + 1 < n && lmn < mx && rmn < mx
	if lmn != rmn
		puts "#{x[0..k-1].index(lmn)+1} #{x[k+1..-1].index(rmn)+k+2}"
	else
		1.upto(k-1) do |i|
			if x[i] != mx
				puts "#{i+1} #{k+1}"
				exit 0
			end
		end
		(k+1).upto(n-2) do |i|
			if x[i] != mx
				puts "#{k+1} #{i+1}"
				exit 0
			end
		end
		if n == 3
			puts -1
			exit 0
		end
		puts "1 2"
	end
	exit 0
end

if mn == mx
	puts -1
	exit 0
end

x[1..-2].each_with_index do |v, i|
	if v != x[0]
		puts "1 #{i+2}"
		exit 0
	end
	if v != x[-1]
		puts "#{i+2} #{n}"
		exit 0
	end
end

puts -1

# 3818866	 Jun 3, 2013 5:18:06 PM	delta_4d	 B - Unsorting Array	 Ruby	Accepted	359 ms	6356 KB
