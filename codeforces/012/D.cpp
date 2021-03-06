#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 500000 + 86;

struct triple {
	int x, y, z;

	triple(int _x=0, int _y=0, int _z=0):x(_x), y(_y), z(_z) {}
} g[MAXN];

int mx[MAXN];

inline bool cmpx(const triple &a, const triple &b) {
	return a.x < b.x;
}

inline bool cmpy(const triple &a, const triple &b) {
	return a.y == b.y ? a.x > b.x : a.y < b.y;
}

int main() {
	int n;

	scanf("%d", &n);
	for (int i=0; i<n; ++i) scanf("%d", &g[i].x);
	for (int i=0; i<n; ++i) scanf("%d", &g[i].y);
	for (int i=0; i<n; ++i) scanf("%d", &g[i].z);

	sort(g, g+n, cmpx);
	for (int i=0,j=-1; i<n; ++i) {
		if (g[i].x != j) j = g[i].x, g[i].x = i + 1;
		else g[i].x = g[i-1].x;
	}

	sort(g, g+n, cmpy);
	memset(mx, -1, sizeof(mx));
	int tot = 0;
	for (int i=n-1; i>=0; --i) {
		int cc = -1;
		for (int k=g[i].x+1; k<=n; k+=k&-k) cc = max(cc, mx[k]);
		tot += cc > g[i].z;
		for (int k=g[i].x; k>0; k-=k&-k) mx[k] = max(mx[k], g[i].z);
	}
	printf("%d\n", tot);

	return 0;
}

// 3790074	 May 29, 2013 11:25:32 AM	delta_4d	 D - Ball	 GNU C++	Accepted	 781 ms	 7800 KB
