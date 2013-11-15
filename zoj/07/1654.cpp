#include <cstdio>
#include <memory>
using namespace std;

#define SPACE 'o'
#define GRASS '*'
#define WALL '#'
const int MAXN = 1250;
const int MAXL = 51;
int h[MAXL][MAXL];
int v[MAXL][MAXL];
int match[MAXN];
bool visit[MAXN];
bool conn[MAXN][MAXN];
char s[MAXL][MAXL];

void construct_graph(const int &m, const int &n, int &x, int &y) {
	int i, j, k;
	int hn(1), vn(1);
	memset(conn, false, sizeof(conn));
	memset(v, -1, sizeof(v));
	memset(h, -1, sizeof(h));
	for (i=0; i<m; ++i) {
		for (j=0; j<n; ++j) {
			if (s[i][j] == SPACE) {
				if (h[i][j] == -1) {
					for (k=j; s[i][k]!=WALL&&k<n; ++k) h[i][k] = hn;
					++hn;
				}
				if (v[i][j] == -1) {
					for (k=i; s[k][j]!=WALL&&k<m; ++k) v[k][j] = vn;
					++vn;
				}
				conn[h[i][j]][v[i][j]] = true;
			}
		}
	}
	x = hn; y = vn;
}

bool dfs(const int &x, const int &n) {
	int y;
	for (y=1; y<n; ++y) {
		if (!visit[y] && conn[x][y]) {
			visit[y] = true;
			if (match[y] == -1 || dfs(match[y], n)) {
				match[y] = x;
				return true;
			}
		}
	}
	return false;
}

int matching(const int &m, const int &n) {
	int i, j, k;
	int res(0);
	memset(match, -1, sizeof(match));
	for (i=1; i<m; ++i) {
		memset(visit, false, sizeof(visit));
		if (dfs(i, n)) ++res;
	}
	return res;
}

int main() {
	int tc;
	int len;
	int cn(0);
	int n, m;
	int i, j, k, t;
	int hn, vn;
	//freopen("f:\\in.txt", "r", stdin);
	scanf("%d", &tc);
	for (t=0; t<tc; ++t) {
		scanf("%d %d", &m, &n);
		for (i=0; i<m; ++i) scanf("%s", s[i]);
		construct_graph(m, n, hn, vn);
		printf("Case :%d\n", ++cn);
		printf("%d\n", matching(hn, vn));
	}	
	return 0;
}
