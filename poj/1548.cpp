#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

const int MAXN = 24 * 24 + 1;
bool visit[MAXN];
int match[MAXN];
int xx[MAXN], yy[MAXN];
int w[MAXN];
vector<int> c[MAXN];

bool dfs(int x) {
	int y;
	int i;
	for (i=0; i!=c[x].size(); ++i) {
		y = c[x][i];
		if (!visit[y]) {
			visit[y] = true;
			if (match[y] == -1 || dfs(match[y])) {
				match[y] = x;
				return true;
			}
		}
	}
	return false;
}

int gao() {
	int i, j, k(0);
	memset(match, -1, sizeof(match));
	for (i=0; i<MAXN; ++i) {
		memset(visit, false, sizeof(visit));
		if (dfs(i)) ++k;
	}
	return k;
}

int main() {
	int i, j, k;
	int x, y;
	//freopen("f:\\in.txt", "r", stdin);
	scanf("%d %d", &x, &y);
	while (x != -1 || y != -1) {
		k = 0;
		while (x != 0 || y != 0) {
			xx[k] = x, yy[k] = y;
			w[k] = (x - 1) * 24 + y - 1;
			++k;
			scanf("%d %d", &x, &y);
		}
		for (i=0; i<MAXN; ++i) c[i].clear();
		for (i=0; i<k; ++i) {
			for (j=0; j<k; ++j) {
				if (j == i) continue;
				if (xx[j] >= xx[i] && yy[j] >= yy[i]) c[w[i]].push_back(w[j]);
			}
		}
		printf("%d\n", k-gao());
		scanf("%d %d", &x, &y);
	}
	return 0;
}