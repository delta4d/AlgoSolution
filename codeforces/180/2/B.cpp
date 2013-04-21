#include <cmath>
#include <cstdio>
using namespace std;

const int MAXN = 100000 + 86;

char s[MAXN];
int mp[128];

inline bool ok(int c[]) {
	for (int i=0; i<4; ++i) if (c[i]>0) return false;
	return true;
}

int main() {
	int t, sx, sy, ex, ey;
	int c[4]={0};
	mp['E'] = 0, mp['S'] = 1, mp['W'] = 2, mp['N'] = 3;

	scanf("%d%d%d%d%d%s", &t, &sx, &sy, &ex, &ey, s);
	if (ex >= sx) c[mp['E']] = ex - sx;
	else c[mp['W']] = sx - ex;
	if (ey >= sy) c[mp['N']] = ey - sy;
	else c[mp['S']] = sy - ey;
//	for (int i=0; i<4; ++i) printf("%d ", c[i]); puts("");
	for (int i=0; i<t; ++i) {
		if (ok(c)) { printf("%d\n", i); return 0; }
		--c[mp[s[i]]];
	}
	if (ok(c)) printf("%d\n", t);
	else puts("-1");

	return 0;
}

// 3583477	 Apr 21, 2013 9:04:21 AM	delta_4d	 B - Sail	 GNU C++	Accepted	 31 ms	 100 KB
