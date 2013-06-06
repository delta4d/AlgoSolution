#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 410;

char a[MAXN][MAXN];
int p[MAXN][MAXN];
vector <int> c[26];

inline int sum(int x1, int y1, int x2, int y2) {
	return p[x2][y2] - p[x2][y1-1] - p[x1-1][y2] + p[x1-1][y1-1];	
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, m, t;
	long long tot = 0;

	scanf("%d%d%d", &n, &m, &t);
	for (int i=1; i<=n; ++i) scanf("%s", a[i]+1);
	for (int i=1; i<=n; ++i) for (int j=1; j<=m; ++j) {
		p[i][j] = p[i][j-1] + p[i-1][j] - p[i-1][j-1] + (a[i][j] == 'a');
	}
	for (int i=1; i<=n; ++i) for (int j=i+1; j<=n; ++j) {
		for (int k=0; k<26; ++k) c[k].clear();
		for (int k=1; k<=m; ++k) if (a[i][k] == a[j][k]) c[a[i][k]-'a'].push_back(k);
		for (int k=0; k<26; ++k) {
			int p1 = 0, p2 = 1, s = c[k].size();
			while (p1 < s && p2 < s) {
				while (p2 < s && sum(i, c[k][p1], j, c[k][p2]) <= t) ++p2;	
				--p2;
				if (p2 > p1) tot += p2 - p1;
//				printf("%d %d %d %d = %d %d\n", i, j, k, s, p1, p2);
				++p1;
			}
		}
	}
	printf("%I64d\n", tot);

	return 0;
}

// 3825176	 Jun 5, 2013 6:27:19 PM	delta_4d	 D - Table with Letters - 2	 GNU C++	Accepted	640 ms	1056 KB
