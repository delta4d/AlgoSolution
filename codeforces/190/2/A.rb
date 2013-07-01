n, m = gets.split.map(&:to_i)
puts n + m - 1
puts [*1..n].map{|i| i.to_s+" 1"}
puts [*2..m].map{|i| "1 "+i.to_s}

# 3991634	 Jun 29, 2013 4:56:25 PM	delta_4d	 A - Ciel and Dancing	 Ruby	Accepted	 46 ms	 0 KB
