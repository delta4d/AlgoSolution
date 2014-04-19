#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1 << 5;

char s1[N], s2[N];
int f[N][N];
long long c[N][N];

void gao(int l1, int l2) {
	memset(f, 0, sizeof(f));
	memset(c, 0, sizeof(c));
	for (int i=0; i<l1; ++i) for (int j=0; j<l2; ++j) {
		if (s1[i] == s2[j]) f[i][j] = (i && j) * f[i-1][j-1] + 1;
		else f[i][j] = max(f[i][j], max((!!i) * f[i-1][j], (!!j) * f[i][j-1]));
	}
	for (int i=0,t=0; i<l1; ++i) c[i][0] = (t |= s1[i] == s2[0]) ? 1 : i + 2;
	for (int i=0,t=0; i<l2; ++i) c[0][i] = (t |= s1[0] == s2[i]) ? 1 : i + 2;
	for (int i=1; i<l1; ++i) for (int j=1; j<l2; ++j) {
		if (s1[i] == s2[j]) c[i][j] = c[i-1][j-1];
		else c[i][j] = (f[i][j] == f[i-1][j]) * c[i-1][j] + (f[i][j] == f[i][j-1]) * c[i][j-1];
	}
}

int main() {
	int tc, cn = 0;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%s%s", s1, s2);
		int l1 = strlen(s1), l2 = strlen(s2);
		gao(l1, l2);
		printf("Case %d: %d %lld\n", ++cn, l1+l2-f[l1-1][l2-1], c[l1-1][l2-1]);
	}
	return 0;
}

// 290286	2013-11-22 22:29:29	 1013 - Love Calculator	 C++	 0.000	 1100	Accepted
