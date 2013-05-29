n, m = gets.split.map(&:to_i)
price = gets.split.map(&:to_i).sort
fruits = {}
m.times do
	fruit = gets.chomp
	fruits.has_key?(fruit) ? fruits[fruit] += 1 : fruits[fruit] = 1
end
count = fruits.values.sort.reverse
mn, mx = 0, 0
count.each_index{|i| mn, mx = mn + price[i] * count[i], mx + price[n-1-i] * count[i]}
puts "#{mn} #{mx}"

# 3788454	 May 28, 2013 7:23:08 PM	delta_4d	 C - Fruits	 Ruby	Accepted	46 ms	60 KB
