#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 4000 + 86;
const int INF = 0x3f3f3f3f;

int f[MAXN][811], t[MAXN][811];
int u[MAXN][MAXN], c[MAXN][MAXN];
char s[MAXN*10];

void read(const int i) {
	gets(s);
	for (int j=0,cc=0,k=1; ; ++j) {
		if (s[j] == ' ' || s[j] == '\0') u[i][k] = cc + u[i-1][k], cc = 0, ++k;
		else cc = cc * 10 + s[j] - '0';
		if (!s[j]) break;
	}
}

int main() {
	int n, m;

	scanf("%d%d", &n, &m); gets(s);
	for (int i=1; i<=n; ++i) read(i);
	for (int i=1; i<=n; ++i) for (int j=i+1; j<=n; ++j) c[i][j] = c[i][j-1] + u[j-1][j] - u[i-1][j];
	for (int i=1; i<=n; ++i) f[i][1] = c[1][i];
	for (int j=2; j<=m; ++j) {
		t[n+1][j] = n;
		for (int i=n; i>=1; --i) {
			f[i][j] = INF;
			for (int k=t[i][j-1]; k<=t[i+1][j]; ++k) if (f[k][j-1] + c[k+1][i] < f[i][j]) {
				t[i][j] = k;
				f[i][j] = f[k][j-1] + c[k+1][i];
			}
		}
	}
	int mn = INF;
	for (int i=1; i<=m; ++i) mn = min(mn, f[n][i]);
	printf("%d\n", mn);

	return 0;
}

// 3996711	 Jun 30, 2013 8:23:36 PM	delta_4d	 E - Ciel and Gondolas	 GNU C++	Accepted	 640 ms	 156600 KB
