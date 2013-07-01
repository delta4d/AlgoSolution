#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 128;
const int INF = 0x3f3f3f3f;

char s[MAXN];
long long x[MAXN], y[MAXN];
long long sx, sy;

int main() {
	int a, b;
	int n;
		
	cin >> a >> b;
	scanf("%s", s+1);
	
	n = strlen(s+1);
	for (int i=1; i<=n; ++i) {
		x[i] = x[i-1], y[i] = y[i-1];
		if (s[i] == 'U') {
			y[i] = y[i-1] + 1;
		} else if (s[i] == 'D') {
			y[i] = y[i-1] - 1;
		} else if (s[i] == 'L') {
			x[i] = x[i-1] - 1;
		} else {
			x[i] = x[i-1] + 1;
		}
	}
	sx = x[n], sy = y[n];
//	for (int i=0; i<=n; ++i) printf("%d %d\n", x[i], y[i]);
	for (int i=0; i<=n; ++i) {
		if (sx == 0 && a != x[i]) continue;
		if (sy == 0 && b != y[i]) continue;
		if (sx != 0 && (a - x[i]) % sx != 0) continue;
		if (sy != 0 && (b - y[i]) % sy != 0) continue;
		int kx = -INF, ky = -INF;
		if (sx != 0) kx = (a - x[i]) / sx;
		if (sy != 0) ky = (b - y[i]) / sy;
		if (kx >= 0 && ky >= 0 && kx == ky) return puts("Yes"), 0;
		if (kx == -INF && ky >= 0) return puts("Yes"), 0;
		if (ky == -INF && kx >= 0) return puts("Yes"), 0;
		if (kx == -INF && ky == -INF) return puts("Yes"), 0;
	}
	puts("No");
	
	return 0;
}

// 3975019	 Jun 28, 2013 7:50:09 PM	delta_4d	 A - Ciel and Robot	 GNU C++	Accepted	 15 ms	 0 KB
