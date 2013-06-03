#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 128;

int x[MAXN], t[MAXN];
int m1[MAXN][MAXN], m2[MAXN][MAXN];
int q[MAXN], s[MAXN];
int n, m;

void init() {
	for (int k=2; k<=m; ++k) {
		for (int i=0; i<n; ++i) {
			m1[k][i] = m1[k-1][m1[1][i]];	
			m2[k][i] = m2[k-1][m2[1][i]];
		}
	}
}

bool ok() {
	int i, j, k;
	int pa, pb;
	for (pa=0; pa<=m; ++pa) {
		for (i=0; i<n; ++i) if (m1[pa][i] != s[i]) break;
		if (i >= n) break;
	}
	for (pb=0; pb<=m; ++pb) {
		for (i=0; i<n; ++i) if (m2[pb][i] != s[i]) break;
		if (i >= n) break;
	}
	if (pa > m && pb > m) return false;
	if (pa == 0 || pb == 0) return false;
	if (pa == 1 && pb == 1) return m <= 1;
	if ((pa + m) % 2 == 0) return true;
	if ((pb + m) % 2 == 0) return true;
	return false;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i=0; i<n; ++i) scanf("%d", q+i), --q[i];
	for (int i=0; i<n; ++i) scanf("%d", s+i), --s[i];
	for (int i=0; i<n; ++i) m1[0][i] = i, m2[0][i] = i;
	for (int i=0; i<n; ++i) m1[1][i] = q[i], m2[1][q[i]] = i;
	init();
	printf("%s\n", ok()?"YES":"NO");

	return 0;
}

// 3817923	 Jun 3, 2013 11:49:49 AM	delta_4d#	 B - Playing with Permutations	 GNU C++	Accepted	 15 ms	 100 KB
