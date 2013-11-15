$INF = 0xFFFFFFFFFFFFFFFFFFFFFFF

$p = []
$mn = $INF
$MAXN = 8000001

def init
	isp = Array.new(100, true)
	for i in 2..99
		if isp[i]
			$p << i
			j = 2 * i
			while j < 100
				isp[j] = false
				j += i
			end
		end
	end
end

def min x, y
	return x if x < y
	return y
end

def P b, e
	ret = 1
	for i in 1..e
		ret = ret * b
	end
	ret
end

def dfs d, cnt, v
#	puts "#{d} #{cnt} #{v}"
	return if v > $mn
	if cnt >= $MAXN
		$mn = min($mn, v)
		return
	end
	i = 1
	while true
		cv = P($p[d], i)
		return if cv * v > $mn
		dfs(d+1, cnt*(2*i+1), v*cv)
		i = i + 1
	end
end

def main
	init
	dfs(0, 1, 1)
	puts $mn
end

main