#include <cstdio>

int const N = 1e5 + 86;
int x[N], y[N], sx[N];

int main() {
	int n;
	scanf("%d", &n);
	for (int i=0; i<n; ++i) scanf("%d%d", x+i, y+i), ++sx[x[i]];
	for (int i=0; i<n; ++i) printf("%d %d\n", n+sx[y[i]]-1, n-sx[y[i]]-1);
	return 0;
}

// 6720909	 May 27, 2014 3:26:49 PM	delta_4d	 B - Football Kit	 GNU C++0x	Accepted	77 ms	1152 KB
