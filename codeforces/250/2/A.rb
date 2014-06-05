c,r=$<.map{|x| x.size-3},[]
c.each_with_index do |v,i|
	cc=c[i+1..-1]+(i>0?c[0..i-1]:[])
	r<<(i+'A'.ord).chr if c[i]>=2*cc.max || 2*c[i]<=cc.min
end
puts r.size!=1?'C':r[0]

# 6775379	 2014-06-01 20:45:44	delta_4d	 A - The Child and Homework	 Ruby	Accepted	 108 ms	 0 KB
