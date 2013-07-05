#include <map>
#include <cstdio>
#include <algorithm>
using namespace std;

map <int, int> x;

int main() {
	int n;

	scanf("%d", &n);
	for (int i=0,h,m; i<n; ++i) {
		scanf("%d%d", &h, &m);
		h = h * 100 + m;
		++x[h];
	}
	int mx = 0;
	for (map<int,int>::iterator it=x.begin(); it!=x.end(); ++it) mx = max(mx, it->second);
	printf("%d\n", mx);

	return 0;
}

// 4002788	 Jul 2, 2013 2:33:12 PM	delta_4d	 A - Free Cash	 GNU C++	Accepted	 46 ms	 100 KB
