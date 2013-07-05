#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 30;

char s[N][N];
int f[N][N];

int main() {
	int n, m;

	scanf("%d%d", &n, &m);
	for (int i=1; i<=n; ++i) scanf("%s", s[i]+1);
	for (int i=1; i<=n; ++i) for (int j=1; j<=m; ++j) {
		f[i][j] = f[i-1][j] + f[i][j-1] - f[i-1][j-1] + (s[i][j] == '0');
	}
	int mx = 0;
	for (int x1=1; x1<=n; ++x1) for (int x2=x1; x2<=n; ++x2) {
		for (int y1=1; y1<=m; ++y1) for (int y2=y1; y2<=m; ++y2) {
			if (f[x2][y2] + f[x1-1][y1-1] - f[x1-1][y2] - f[x2][y1-1] == (x2 - x1 + 1) * (y2 - y1 + 1)) {
				mx = max(mx, 2*(x2-x1+y2-y1+2));
			}
		}
	}
	printf("%d\n", mx);

	return 0;
}

// 4025507	 Jul 5, 2013 11:45:57 AM	delta_4d	 B - Bargaining Table	 GNU C++0x	Accepted	 15 ms	 0 KB
