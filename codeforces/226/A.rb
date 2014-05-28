i=->{gets.split.map(&:to_i)}
n,c=i[]
x=i[]
mx=0
0.upto(n-2){|i|mx=[mx,x[i]-x[i+1]-c].max}
p mx

# 6578473	 May 9, 2014 7:18:37 PM	delta_4d	 A - Bear and Raspberry	 Ruby	Accepted	 62 ms	 100 K
