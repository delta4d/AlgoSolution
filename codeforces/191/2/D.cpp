#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

struct operation {
	char c;
	int x, y;
	operation() {}
	operation(char _c, int _x, int _y):c(_c), x(_x), y(_y) {}
	void to_s() { printf("%c %d %d\n", c, x, y); }
};

vector <operation> op;
char mp[511][511];
bool v[511][511];
int n, m;

void gao(int x, int y, const int rx, const int ry) {
	v[x][y] = true;
	op.push_back(operation('B', x+1, y+1));
	for (int k=0; k<4; ++k) {
		int tx = x + dx[k], ty = y + dy[k];
		if (tx < 0 || tx >= n || ty < 0 || ty >= m || mp[tx][ty] != '.' || v[tx][ty]) continue;
		gao(tx, ty, rx, ry);
	}
	if (x != rx || y != ry) op.push_back(operation('D', x+1, y+1)), op.push_back(operation('R', x+1, y+1));
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i=0; i<n; ++i) scanf("%s", mp[i]);
	for (int i=0; i<n; ++i) for (int j=0; j<m; ++j) if (mp[i][j] == '.' && !v[i][j]) gao(i, j, i, j);
	printf("%d\n", (int)op.size());
	for (auto x: op) x.to_s();
	return 0;
}

// 4021887	 Jul 4, 2013 8:07:36 PM	delta_4d	 D - Block Tower	 GNU C++0x	Accepted	 421 ms	 38500 KB
