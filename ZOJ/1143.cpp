#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 10000;
const int MAXN = 20;

int a[MAXN], b[MAXN], m[MAXN], y[MAXN];

inline bool OK(const int n) {
	if (y[0] >= INF) return false;
	for (int i=1; i<n; ++i) {
		if (y[i] >= INF) return false;
		if (y[i] != y[i-1]) return true;
	}
	return false;
}

int main() {
	int i, j, k;
	int n;
	int cn(0);
	int minx, index;

	//freopen("f:\\in.txt", "r", stdin);
	scanf("%d", &n);
	while (true) {
		for (i=0; i<n; ++i) {
			scanf("%d %d %d", y+i, a+i, b+i);
			m[i] = b[i] - a[i];
		}
		
		while (OK(n)) {
			minx = INF;
			for (i=0; i<n; ++i) {
				if (minx > y[i]) {
					minx = y[i];
					index = i;
				}
			}
			y[index] += m[index];
		}
		
		printf("Case #%d:\n", ++cn);
		if (y[0] >= INF) puts("Unknown bugs detected.");
		else printf("The actual year is %d.\n", y[0]);
		
		scanf("%d", &n);
		puts("");
		if (n == 0) break;
	}
	return 0;
}