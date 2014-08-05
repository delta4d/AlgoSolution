#include <bits/stdc++.h>
using namespace std;

int const N = 1e5 + 10;

char s[N];
int f[N][3];

bool _ok(int x, int y, int z) {
	if (x == z && z == y) return true;
	if (x == z && y == z - 1) return true;
	if (y == z && y == x - 1) return true;
	return false;
}

bool ok(int x, int y, int z) {
	if (x + y + z < 3) return true;
	return _ok(x, y, z) || _ok(z, x, y) || _ok(y, z, x);
}

int main() {
	scanf("%s", s);
	int n = (int)strlen(s);
	for (int i=0; i<n; ++i) {
		for (int j=0; j<3; ++j) f[i+1][j] = f[i][j];
		++f[i+1][s[i]-'x'];
	}
	int m, l, r;
	for (scanf("%d", &m); m--; ) {
		scanf("%d%d", &l, &r);
		int x = f[r][0] - f[l-1][0], y = f[r][1] - f[l-1][1], z = f[r][2] - f[l-1][2];
		if (ok(x, y, z)) puts("YES");
		else puts("NO");
	}
	return 0;
}

// 7345363	2014-08-04 17:45:00	delta_4d	A - Sereja and Algorithm	GNU C++0x	Accepted	46 ms	1280 KB
