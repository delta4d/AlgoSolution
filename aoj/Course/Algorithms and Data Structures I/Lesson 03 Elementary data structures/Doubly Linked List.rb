#!/usr/bin/env ruby

class DLL
	def initialize
		@list = []
		@mp = {}
	end
	
	def insert(x)
		@list.insert(0, x)
	end

	def delete(x)
		begin
			@list.delete_at(@list.index(x))
		rescue TypeError
		end
	end

	def deleteFirst
		@list.delete_at(0) if !@list.empty?
	end

	def deleteLast
		@list.pop
	end

	def output
		puts @list.join(" ")
	end
end

q = DLL.new
n = gets.to_i
n.downto(1) do
	op, elm = gets.split			
	case op
	when "insert"
		q.insert(elm)
	when "delete"
		q.delete(elm)
	when "deleteFirst"
		q.deleteFirst
	when "deleteLast"
		q.deleteLast
	end
end
q.output
