#!/usr/bin/env ruby

cnt = Array.new(4) { Array.new(1024, 0) }
mp = { 'A' => 0, 'C' => 1, 'G' => 2, 'T' => 3 }
rmp = ['A', 'C', 'G', 'T']

gets
while true
	begin
		s = ""
		ss = gets.chomp
		while ss[0] != '>'
			s += ss
			ss = gets.chomp
		end
		s.enum_for(:each_char).each_with_index { |x, i| cnt[mp[x]][i] = cnt[mp[x]][i] + 1 }
	rescue
		LEN = s.length
		s.enum_for(:each_char).each_with_index { |x, i| cnt[mp[x]][i] = cnt[mp[x]][i] + 1 }
		break
	end
end

s = []
LEN.times do |i|
	mx, idx = -1, -1
	4.times do |k|
		mx, idx = cnt[k][i], k if mx < cnt[k][i]
	end
	s << rmp[idx]
end

puts s.join

4.times do |i|
	puts "#{rmp[i]}: #{cnt[i][0..LEN-1].join(' ')}"
end
