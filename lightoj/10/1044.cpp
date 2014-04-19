/*
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
const int N = 1011;

char ss[N];
int f[N][N];
vector <int> s[N];

void pa(int n) {
	memset(f, 0, sizeof(f));
	for (int i=0; i<n; ++i) s[i].clear();
	for (int i=0; i<n; ++i) {
		for (int k=0; i-k>=0&&i+k<n&&ss[i-k]==ss[i+k]; ++k)
			s[i-k].push_back(i+k), f[i-k][i+k] = 1;
		for (int k=0; i-k>=0&&i+k+1<n&&ss[i-k]==ss[i+k+1]; ++k)
			s[i-k].push_back(i+k+1), f[i-k][i+k+1] = 1;
	}
}

int main() {
	int tc, cn = 0;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%s", ss);
		int n = strlen(ss);
		pa(n);
		for (int k=1; k<n; ++k) for (int i=0; i+k<n; ++i) if (!f[i][i+k]) {
			int j = i + k;
			f[i][j] = INF;
			for (int t=0; t<(int)s[i].size(); ++t) {
				int c = s[i][t];
				f[i][j] = min(f[i][j], f[i][c] + f[c+1][j]);
			}
		}
		printf("Case %d: %d\n", ++cn, f[0][n-1]);
	}
	return 0;
}

// 290199	2013-11-22 20:20:02	 1044 - Palindrome Partitioning	 C++	 0.724	 7876	Accepted
*/

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1 << 10;
const int INF = 0x3f3f3f3f;

char s[N];
int f[N][N];
bool p[N][N];

void init(int n) {
	for (int i=0; i<n; ++i) fill(p[i], p[i]+n, false), fill(f[i], f[i]+n, INF);
	for (int i=0; i<n; ++i) {
		for (int k=0; i-k>=0&&i+k<n&&s[i-k]==s[i+k]; ++k) p[i-k][i+k] = true, f[i-k][i+k] = 1;
		for (int k=0; i-k>=0&&i+k+1<n&&s[i-k]==s[i+k+1]; ++k) p[i-k][i+k+1] = true, f[i-k][i+k+1] = 1;
	}
}

int dfs(int st, int ed, const int n) {
	if (f[st][ed] != INF) return f[st][ed];
	for (int k=st; k<ed; ++k) if (p[st][k]) f[st][ed] = min(f[st][ed], dfs(st, k, n) + dfs(k+1, ed, n));
	return f[st][ed];
}

int main() {
	int tc, cn = 0;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%s", s);
		int n = strlen(s);
		init(n);
		printf("Case %d: %d\n", ++cn, dfs(0, n-1, n));
	}
	return 0;
}

// 290208	2013-11-22 20:42:13	 1044 - Palindrome Partitioning	 C++	 0.088	 6208	Accepted
