ri=->{gets.split.map(&:to_i)}
n,x=ri[]
p (ri[].inject(:+).abs+x-1)/x

# 6558463	2014-05-05 20:59:24	delta_4d	A - Vanya and Cards	Ruby	Accepted	62 ms	200 KB
