#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 200;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

vector <int> e[MAXN];
bool v[MAXN];
int mx[MAXN], my[MAXN];
char s[21][21];
vector <int> X, Y;
#define get_x(x) (lower_bound(X.begin(), X.end(), (x)) - X.begin())
#define get_y(y) (lower_bound(Y.begin(), Y.end(), (y)) - Y.begin())

bool dfs(int x) {
	for (int i=(int)e[x].size()-1; i>=0; --i) {
		int y = e[x][i];
		if (v[y]) continue;
		v[y] = true;
		if (my[y] == -1 || dfs(my[y])) {
			mx[x] = y, my[y] = x;
			return true;
		}
	}
	return false;
}

int Hungarian(int n) {
	int ret = 0;
	memset(mx, -1, sizeof(mx));
	memset(my, -1, sizeof(my));
	for (int i=0; i<n; ++i) if (mx[i] == -1) {
		memset(v, false, sizeof(v));
		ret += dfs(i);
	}
	return ret;
}

int main() {
	int tc, cn = 0, n, m;
	for (scanf("%d", &tc); tc--; ) {
		X.clear(), Y.clear();
		for (int i=0; i<MAXN; ++i) e[i].clear();
		scanf("%d%d", &m, &n);
		int tot = 0;
		for (int i=0; i<m; ++i) {
			scanf("%s", s[i]);
			for (int j=0; j<n; ++j) if (s[i][j] == '*') {
				++tot;
				if ((i + j) & 1) X.push_back(i*n+j);
				else Y.push_back(i*n+j);
			}
		}
		for (int i=0; i<m; ++i) for (int j=0; j<n; ++j) if (s[i][j] == '*' && (i + j) % 2 == 1) {
			for (int k=0; k<4; ++k) {
				int x = i + dx[k], y = j + dy[k];
				if (0 <= x && x < m && 0 <= y && y < n && s[x][y] == '*') {
					e[get_x(i*n+j)].push_back(get_y(x*n+y));
				}
			}
		}
		printf("Case %d: %d\n", ++cn, tot-Hungarian(X.size()));
	}
	return 0;
}

// 321487	2014-02-08 00:44:02	 1152 - Hiding Gold	 C++	 0.000	 1220	Accepted
