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

inline void init() {
	q.clear();
}

inline void output() {
	int i, j, k;
	for (i=1; i<=9; ++i) {
		for (j=1; j<=9; ++j) printf("%d", f[i][j]);
		puts("");
	}
}

void dfs(int depth) {
	int i, j, k;
	int x, y;
	int s, t;
	bool used[MAXN];
	if (depth == q.size()) {
		output();
		zhaodaole = true;
		return;
	}
	memset(used, false, sizeof(used));
	x = q[depth].x, y = q[depth].y;
	s = (x - 1) / 3 * 3, t = (y - 1) / 3 * 3;
	for (i=1; i<10; ++i) used[f[x][i]] = used[f[i][y]] = true;
	for (i=1; i<=3; ++i) for (j=1; j<=3; ++j) used[f[s+i][t+j]] = true;
	for (k=1; k<10; ++k) {
		if (used[k]) continue;
		f[x][y] = k;
		dfs(depth+1);
		if (zhaodaole) return;
	}
	f[x][y] = 0;
}

int main() {
	int i, j, k;
	int tc;
	//freopen("f:\\in.txt", "r", stdin);
	scanf("%d", &tc);
	while (tc--) {
		init();
		for (i=1; i<=9; ++i) {
			scanf("%s", buff);
			for (j=1; j<=9; ++j) {
				k = f[i][j] = buff[j-1] - '0';
				if (k == 0) {
					q.push_back(node(i, j));
				}
			}
		}
		zhaodaole = false;
		dfs(0);
	}
	return 0;
}