#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int f[10][90][90];
char s[11];
int A, B, K;
int r1[11], r2[11];

int g(int n) {
	if (n <= 0) return 0;
	memset(f, 0, sizeof(f));
	for (int i=1; i<10; ++i) ++f[0][i%K][i%K];
	for (int i=0; i+1<n; ++i) for (int a=0; a<K; ++a) for (int b=0; b<K; ++b) {
		int x = f[i][a][b];
		if (!x) continue;
		for (int d=0; d<10; ++d) f[i+1][(a*10+d)%K][(b+d)%K] += x;
	}
	int ret = 0;
	for (int i=0; i<n; ++i) ret += f[i][0][0];
	return ret;
}

int gao(int A) {
	sprintf(s, "%d", A);
	int n = strlen(s);
	if (K > n * 9) return 0;
	for (int i=0; i<n; ++i) s[i] -= '0';
	r1[0] = s[0] % K, r2[0] = r1[0];
	for (int i=1; i<n; ++i) {
		r1[i] = (10 * r1[i-1] + s[i]) % K;
		r2[i] = (r2[i-1] + s[i]) % K;
	}
	memset(f, 0, sizeof(f));
	for (int i=1; i<=s[0]; ++i) ++f[0][i%K][i%K];
	for (int i=0; i+1<n; ++i)  for (int a=0; a<K; ++a) for (int b=0; b<K; ++b) {
		int x = f[i][a][b];
		if (!x) continue;
		for (int d=0; d<10; ++d) {
			int aa = (10 * a + d) % K, bb = (b + d) % K;
			if (a != r1[i] || b != r2[i] || d <= s[i+1]) f[i+1][aa][bb] += x;
			else f[i+1][aa][bb] += x - 1;
		}
	}
	int ret = f[n-1][0][0];
	ret += g(n-1);
	return ret;
}

int main() {
	int tc, cn = 0; 
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d%d%d", &A, &B, &K);
		printf("Case %d: %d\n", ++cn, gao(B)-gao(A-1));
	}
	return 0;
}

// 293386	2013-11-30 18:54:47	 1068 - Investigation	 C++	 0.576	 1404	Accepted
