#include <cstdio>
#include <memory>
using namespace std;

const int MAXN = 11;
int n;
bool find;
bool visit[MAXN];
bool graph[MAXN][MAXN];

inline bool done(const int &x) {
	if (x != 0) return false;
	for (int i=0; i<=n; ++i) if (!visit[i]) return false;
	return true;
}

void dfs(int x) {
	int y;
	if (done(x)) {
		find = true;
		return;
	}
	for (y=0; y<=n; ++y) {
		if (!visit[y] && graph[x][y]) {
			visit[y] = true;
			dfs(y);
			if (find) return;
			visit[y] = false;
		}
	}
}

int main() {
	int cn(0);
	int i, j, k;
	//freopen("f:\\in.txt", "r", stdin);
	scanf("%d", &n);
	while (n != 0) {
		//initial graph
		memset(graph, false, sizeof(graph));
		for (i=1; i<=n; ++i) {
			scanf("%d", &j);
			graph[i][j] = graph[j][i] = true;
			while (getchar() != '\n') {
				scanf("%d", &j);
				graph[i][j] = graph[j][i] = true;
			}
		}
		find = false;
		memset(visit, false, sizeof(visit));
		dfs(0);
		printf("Case %d: ", ++cn);
		if (find) printf("Granny can make the circuit.\n");
		else printf("Granny can not make the circuit.\n");
		scanf("%d", &n);
	}
	return 0;
}
