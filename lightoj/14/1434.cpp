#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const char dir[][3] = {"U", "D", "L", "R", "UL", "UR", "DL", "DR", "*"};
const int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1, 0};
const int dy[] = {0, 0, -1, 1, -1, 1, -1, 1, 0};

char p[32][32], s[16];
int v[32][32][16];
int m, n;
int x, y;
int path[16];
bool find_one;

void dfs(int x, int y, int d) {
	if (find_one) return;
	if (v[x][y][d] == 0) return;
	if (s[d] == '\0') {
		find_one = true;
		v[x][y][d] = 1;
		return;
	}
	for (int k=0; k<9; ++k) {
		int tx = x + dx[k], ty = y + dy[k];
		if (0 <= tx && tx < m && 0 <= ty && ty < n && p[tx][ty] == s[d] && v[x][y][d] == -1) {
			path[d-1] = k;
			dfs(tx, ty, d+1);
			if (find_one) {
				v[x][y][d] = 1;
				return;
			}
		}
	}
	v[x][y][d] = 0;
}

void gao() {
	find_one = false;
	memset(v, -1, sizeof(v));
	for (int i=0; i<m; ++i) for (int j=0; j<n; ++j) if (p[i][j] == s[0]) {
		dfs(x=i, y=j, 1);
		if (find_one) return;
	}
}

int main() {
	int tc, cn = 0, q;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d%d", &m, &n);
		for (int i=0; i<m; ++i) scanf("%s", p[i]);
		printf("Case %d:\n", ++cn);
		for (scanf("%d", &q); q--; ) {
			scanf("%s", s);
			gao();
			if (find_one) {
				printf("%s found: (%d,%d)", s, x+1, y+1);
				for (int i=0; s[i+1]; ++i) printf(", %s", dir[path[i]]);
				puts("");
			} else {
				printf("%s not found\n", s);
			}
		}
	}
	return 0;
}

// 322751	2014-02-13 01:21:57	 1434 - Patch Quilt	 C++	 0.020	 1152	Accepted
