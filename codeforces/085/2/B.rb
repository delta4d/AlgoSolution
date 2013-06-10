n, x, y = gets.split.map(&:to_i)
puts ["YES", "NO"][(x == n / 2 || x == n / 2 + 1) && (y == n / 2 || y == n / 2 + 1) ? 1 : 0]

# 3854391	 Jun 10, 2013 6:59:43 PM	delta_4d	 B - Petya and Square	 Ruby	Accepted	46 ms	0 KB
