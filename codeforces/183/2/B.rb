#!/usr/bin/env ruby

require 'date'
puts (Date.parse(gets.gsub(':','-')).ld - Date.parse(gets.gsub(':','-')).ld).abs

# 3720703	 May 14, 2013 7:17:32 PM	delta_4d	 B - Calendar	 Ruby	Accepted	46 ms	248 KB
