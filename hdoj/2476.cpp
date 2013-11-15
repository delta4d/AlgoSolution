#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 128;

char s1[MAXN], s2[MAXN];
int f[MAXN][MAXN];
int out[MAXN];

int main() {
	int i, j, k;
	int m, n;
	int L;
	
//	freopen("in.txt", "r", stdin);
	while (2 == scanf("%s %s", s1, s2)) {
		n = strlen(s1);
		memset(f, 0, sizeof(f));
		for (i=0; i<n; ++i) for (j=i; j<n; ++j) f[i][j] = INF;
		for (i=0; i<n; ++i) f[i][i] = 1;
		for (L=1; L<n; ++L) {
			for (i=0; i+L<n; ++i) {
				j = i + L;
				if (s2[i] == s2[j]) f[i][j] = f[i+1][j];
				for (k=i+1; k<j; ++k) {
					if (s2[k] == s2[i]) f[i][j] = min(f[i][j], f[i][k]+f[k+1][j]);
				}
				f[i][j] = min(f[i][j], f[i+1][j]+1);
			}
		}
		for (i=0; i<n; ++i) out[i] = f[0][i];
		for (i=0; i<n; ++i) {
			if (s1[i] == s2[i]) out[i] = i ? out[i-1] : 0;
			for (j=0; j<i; ++j) out[i] = min(out[i], out[j]+f[j+1][i]);
		}
		printf("%d\n", out[n-1]);
	}
	return 0;
}