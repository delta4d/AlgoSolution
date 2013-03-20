#include <vector>
#include <cstdio>
#include <memory>
using namespace std;

typedef vector<int> VI;
typedef VI::iterator VII;
const int MAXN = 10000;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};
int match[MAXN];
bool visit[MAXN];
bool graph[100][100];
VI conn[MAXN];

bool dfs(int n) {
	VII it;
	for (it=conn[n].begin(); it!=conn[n].end(); ++it) {
		if (!visit[*it]) {
			visit[*it] = true;
			if (match[*it] == -1 || dfs(match[*it])) {
				match[*it] = n;
				return true;
			}
		}
	}
	return false;
}

inline bool border(const int &m, const int &n, const int &x, const int &y) {
	return x >= 0 && x < m && y >= 0 && y < n;
}

void gao(const int &m, const int &n) {
	int x, y, tx, ty;
	int i, j, k;
	int res(0);
	for (i=0; i<m*n; ++i) conn[i].clear();
	for (i=0; i<m; ++i) {
		for (j=i%2; j<n; j+=2) {
			if (graph[i][j]) {
				for (k=0; k<4; ++k) {
					x = i + dx[k];
					y = j + dy[k];
					if (border(m, n, x, y) && graph[x][y]) {
						conn[i*m+j].push_back(x*m+y);
					}
				}
			}
		}
	}
	memset(match, -1, sizeof(match));
	for (i=0; i<m; ++i) {
		for (j=i%2; j<n; j+=2) {
			memset(visit, false, sizeof(visit));
			if (graph[i][j] && dfs(i*m+j)) {
				++res;
			}
		}
	}
	//for (i=0; i<m*n; ++i) printf("%d: %d\n", i, match[i]);
	printf("%d\n", res);
}

int main() {
	int m, n;
	int x, y;
	int i, j, k;
	//freopen("f:\\in.txt", "r", stdin);
	scanf("%d %d", &m, &n);
	while (m != 0 || n != 0) {
		scanf("%d", &k);
		memset(graph, true, sizeof(graph));
		for (i=0; i<k; ++i) {
			scanf("%d %d", &x, &y);
			--x; --y;
			graph[x][y] = false;
		}
		gao(m, n);
		scanf("%d %d", &m, &n);
	}
	return 0;
}
