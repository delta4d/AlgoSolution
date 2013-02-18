## [Codeforces Beta Round #3](http://www.codeforces.com/contest/3)

### A. [Shortest path of the king](http://www.codeforces.com/contest/3/problem/A)
Greedy

### B. [Lorry](http://www.codeforces.com/contest/3/problem/B)
Greedy. Sort by averge capacities. There is one situtation to be taken good care of, see the code for more details.

### C. [Tic-tac-toe](http://www.codeforces.com/contest/3/problem/C)
Implementation

### D. [Least cost bracket sequence](http://www.codeforces.com/contest/3/problem/D)
Greedy. A bracket seq is legal, iff for any prefix string s[0..i], #'('>=#')' (i<len-1) && #'('=#')' (i=len-1). Assume '?' as ')', if is results illegal, change one '?' before as '(', in order to minimize cost, choose the largest b-a. (#'x' denotes the number of x)