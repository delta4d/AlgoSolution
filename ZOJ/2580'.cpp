#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

const int MAXN = 10;
struct node {
	int x;
	int y;
	node(int _x=0, int _y=0):x(_x), y(_y) {}
};
vector<node> q;
int f[MAXN][MAXN];
char buff[MAXN];
bool zhaodaole;
bool col[MAXN][MAXN];
bool row[MAXN][MAXN];
bool squ[3][3][MAXN];

inline void init() {
	memset(col, false, sizeof(col));
	memset(row, false, sizeof(row));
	memset(squ, false, sizeof(squ));
	memset(f, 0, sizeof(f));
	q.clear();
}

inline void output() {
	int i, j, k;
	for (i=0; i<9; ++i) {
		for (j=0; j<9; ++j) printf("%d", f[i][j]);
		puts("");
	}
}

void dfs(int depth) {
	int i, j, k;
	int x, y;
	int s, t;
	if (depth == q.size()) {
		output();
		zhaodaole = true;
		return;
	}
	x = q[depth].x, y = q[depth].y;
	s = x / 3 * 3, t = y / 3 * 3;
	for (k=1; k<10; ++k) {
		if (!col[y][k] && !row[x][k] && !squ[s][t][k]) {
			col[y][k] = row[x][k] = squ[s][t][k] = true;
			f[x][y] = k;
			dfs(depth+1);
			if (zhaodaole) return;
			col[y][k] = row[x][k] = squ[s][t][k] = false;
		}
	}
}

int main() {
	int i, j, k;
	int tc;
	freopen("f:\\in.txt", "r", stdin);
	scanf("%d", &tc);
	while (tc--) {
		init();
		for (i=0; i<9; ++i) {
			scanf("%s", buff);
			for (j=0; j<9; ++j) {
				k = f[i][j] = buff[j] - '0';
				if (k == 0) {
					q.push_back(node(i, j));
				} else {
					col[j][k] = row[i][k] = squ[i/3][j/3][k] = true;
				}
			}
		}
		zhaodaole = false;
		dfs(0);
	}
	return 0;
}