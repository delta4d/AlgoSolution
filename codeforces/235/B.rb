i=->(x){x.split.map(&:to_i)}
n,_=i[gets]
a=$<.drop(0).collect{|x|i[x][1..-1]}.push([0,n]).flatten.sort
x,y=0,0
(a.size-1).times do |k|
	z=a[k+1]-a[k]-1
	x,y=x+(z+1)/2,y+z
end
puts "#{x} #{y}"

# 6558606	2014-05-05 21:32:11	delta_4d	B - Sereja and Contests	Ruby	Accepted	62 ms	0 KB
