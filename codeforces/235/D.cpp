#include <cstdio>
#include <cstring>

long long f[1<<18][100], p[20], fac[20];
char s[20];
int n, m, c[20];

int main() {
	scanf("%s%d", s, &m);
	n = (int)strlen(s);
	p[0] = 1, fac[0] = 1;
	for (int i=1; i<20; ++i) p[i] = p[i-1] * 10 % m, fac[i] = i * fac[i-1];
	for (int i=0; i<n; ++i) ++c[s[i]-'0'];
	f[0][0] = 1;
	for (int i=1,n2=1<<n; i<n2; ++i) {
		int cc = __builtin_popcount(i) - 1;
		for (int j=0; j<n; ++j) if (i & 1 << j) {
			if (s[j] == '0' && cc == n - 1) continue;
			int ii = i ^ (1 << j);
			int r = (s[j] - '0') * p[cc] % m;
			for (int k=0; k<m; ++k) f[i][k] += f[ii][(k-r+m)%m];
		}
	}
	long long tot = f[(1<<n)-1][0];
	for (int i=0; i<10; ++i) tot /= fac[c[i]];
	printf("%I64d\n", tot);
	return 0;
}

// 6560323	2014-05-06 10:23:12	delta_4d	D - Roman and Numbers	GNU C++0x	Accepted	888 ms	205200 KB
