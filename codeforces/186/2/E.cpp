#include <set>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef multiset<int>::iterator MII;

multiset <int> x, y;
vector <int> z;

int main() {
	int n, m;

	scanf("%d%d", &n, &m);
	for (int i=0,a; i<n; ++i) scanf("%d", &a), x.insert(-a);
	for (int i=0,a; i<n; ++i) scanf("%d", &a), y.insert(a);
	for (MII ix=x.begin(); ix!=x.end(); ) {
		MII iy = y.upper_bound(m - 1 + *ix);
		if (iy == y.begin()) { ++ix; continue; }
		--iy;
		z.push_back(*iy - *ix);
		x.erase(ix++), y.erase(iy);
	}
	for (MII ix=x.begin(); ix!=x.end(); ++ix) {
		MII iy = y.end(); --iy;
		z.push_back(*iy - *ix - m);
		y.erase(iy);
	}
	sort(z.begin(), z.end());
	for (int i=n-1; i>=0; --i) printf("%d%s", z[i], i?" ":"\n");

	return 0;
}

// 3813508	 Jun 2, 2013 11:47:34 AM	delta_4d	 E - Ilya and Two Numbers	 GNU C++	Accepted	 218 ms	 7400 KB
