c=Array.new(6,0)
$<.to_a[1].split.map(&:to_i).each{|i|c[i]+=1}
a,b=c[0],c[5]-c[5]%9
puts a==0?-1:(b==0?0:"5"*b+"0"*a)

# 7351590	2014-08-05 14:35:25	delta_4d	A - Jeff and Digits	Ruby	Accepted	124 ms	0 KB
