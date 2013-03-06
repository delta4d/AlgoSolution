#!/usr/bin/env ruby
# TLE version

$SENTINEL = 0x3f3f3f3f3f
$tot = 0
n = gets.to_i
$x = gets.split.collect!{ |i| i.to_i }

def merge(left, mid, right)
	n1 = mid - left
	n2 = right - mid
	ll = $x[left, mid - left]
	rr = $x[mid, right - mid]
	ll << $SENTINEL
	rr << $SENTINEL
	i = 0
	j = 0
	$tot += right - left
	left.upto(right-1) do |k|
		if ll[i] <= rr[j]
			$x[k] = ll[i]
			i = i + 1
		else
			$x[k] = rr[j]
			j = j + 1
		end
	end
end

def msort(left, right)
	if left + 1 < right
		mid = (left + right) / 2
		msort(left, mid)
		msort(mid, right)
		merge(left, mid, right)
	end
end

msort(0, n)
puts $x.join(" ")
puts $tot
