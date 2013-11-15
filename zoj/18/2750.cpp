#include <memory>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 1000;
const int MAXL = 80;

int graph[MAXN][MAXN];
int d[MAXN];
int w[MAXN];
bool visit[MAXN];
char s[MAXN][MAXL];

inline bool r(const int i, const int j) {
	int len(strlen(s[i]));
	for (int k=0; k<4; ++k) {
		if (s[i][len-4+k] != s[j][k]) return false;
	}
	return true;
}

int gao(const int n) {
	int i, j, k;
	int index, mmin;
	memset(visit, false, sizeof(visit));
	fill(d, d+n, INF);
	d[0] = 0;
	for (k=0; k<n; ++k) {
		mmin = INF;
		for (i=0; i<n; ++i) {
			if (!visit[i] && d[i] < mmin) {
				mmin = d[i];
				index = i;
			}
		}
		visit[index] = true;
		for (i=0; i<n; ++i) {
			if (!visit[i] && d[index] + graph[index][i] < d[i]) {
				d[i] = d[index] + graph[index][i];
			}
		}
	}
	return d[n-1] == INF ? -1 : d[n-1];
}

int main() {
	int n;
	int i, j, k;
	//freopen("f:\\in.txt", "r", stdin);
	scanf("%d", &n);
	while (n != 0) {
		for (i=0; i<n; ++i) scanf("%d %s", w+i, s[i]);
		for (i=0; i<n; ++i) for (j=0; j<n; ++j) graph[i][j] = INF;
		for (i=0; i<n; ++i) {
			for (j=0; j<n; ++j) {
				if (j == i) continue;
				if (r(i, j)) graph[i][j] = min(graph[i][j], w[i]);
			}
		}
		printf("%d\n", gao(n));
		scanf("%d", &n);
	}
	return 0;
}