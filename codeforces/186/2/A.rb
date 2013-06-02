s = gets.chomp
n = s.to_i
if n >= 0
	puts n
elsif n > -10
	puts 0
else
	puts [s[0..-2].to_i, (s[0..-3]+s[-1..-1]).to_i].max
end

# 3795236	 May 30, 2013 7:35:28 PM	* delta_4d	 A - Ilya and Bank Account	 Ruby	Accepted	 78 ms	 0 KB
