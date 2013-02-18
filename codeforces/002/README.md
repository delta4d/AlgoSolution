## [Codeforces Beta Round #2](http://www.codeforces.com/contest/2)

### A. [Winner](http://www.codeforces.com/contest/2/problem/A)
Implementation

### B. [The least round way](http://www.codeforces.com/contest/2/problem/B)
[Daynmic Programming](http://en.wikipedia.org/wiki/Dynamic_programming). Pay attention to there is a slot with value 0.

### C. [Commentator problem](http://www.codeforces.com/contest/2/problem/C)
Find a point to 3 circles with same angle.
Assume 3 circles (O1, R1), (O2, R2), (O3, R3), target point X, then dis(X, O1) / R1 = dis(X, O2) / R2 = dis(X, O3) / R3. Thus we can use [Simulated Annealing](http://en.wikipedia.org/wiki/Simulated_annealing) with evaluation function sigma(Di/Ri).Another way: dis(X, O1) / R1 = dis(X, O2) / R2 = k, if k=1, then the orbit of X is a line; if k != 1, it's a circle. The same way we can find the orbit of O2&O3, then compute the intersection point.

