#include <cstdio>
#include <cstring>
using namespace std;

int main() {
	int tc, cn = 0;
	for (scanf("%d", &tc); tc--; ) {
		char s[61];
		long long f[61][61]={0};
		scanf("%s", s);
		int n = strlen(s);
		for (int i=0; i<n; ++i) f[i][i] = 1;
		for (int k=1; k<n; ++k) for (int i=0; i+k<n; ++i) {
			int j = i + k;
			f[i][j] = f[i+1][j] + f[i][j-1];
			if (s[i] == s[j]) ++f[i][j];
			else f[i][j] -= f[i+1][j-1];
		}
		printf("Case %d: %lld\n", ++cn, f[0][n-1]);
	}
	return 0;
}

// 289757	2013-11-21 21:57:21	 1025 - The Specials Menu	 C++	 0.000	 1088	Accepted
