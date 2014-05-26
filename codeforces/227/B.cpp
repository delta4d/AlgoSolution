#include <cstdio>

int a[3000], b[3000];

int main() {
	int m, n, tot = 0;
	scanf("%d%d", &n, &m);
	for (int i=0; i<n; ++i) scanf("%d", a+i);
	for (int i=0; i<m; ++i) scanf("%d", b+i);
	for (int i=n-1,j=m-1; i>=0; --i) {
		if (j < 0 || b[j] < a[i]) ++tot;
		else --j;
	}
	printf("%d\n", tot);
	return 0;
}

// 6571732	 May 8, 2014 3:01:25 PM	delta_4d	 B - George and Round	 GNU C++0x	Accepted	 31 ms	 0 KB
