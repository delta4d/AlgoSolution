mx, x = 0, gets.split.map(&:to_i)
[3, x.min + 1].min.times { |r| mx = [mx, x.map{ |i| (i - r) / 3 }.inject(:+) + r].max }
puts mx

# 3991578	 Jun 29, 2013 4:45:23 PM	delta_4d	 B - Ciel and Flowers	 Ruby	Accepted	 46 ms	 0 KB
