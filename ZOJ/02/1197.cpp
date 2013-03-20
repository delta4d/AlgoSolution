#include <cstdio>
#include <memory>
using namespace std;

const int NOT_MATCHED = -1;
const int MAXN = 30;
int cn;
int n;
struct slide {
	int xmin;
	int ymin;
	int xmax;
	int ymax;
}s[MAXN];

struct point {
	int x;
	int y;
}p[MAXN];

int match[MAXN];
int match1[MAXN];
bool visit[MAXN];
bool visit1[MAXN];
bool graph[MAXN][MAXN];

inline void input() {
	int i;
	for (i=1; i<=n; ++i)
		scanf("%d %d %d %d", &s[i].xmin, &s[i].xmax, &s[i].ymin, &s[i].ymax);
	for (i=1; i<=n; ++i)
		scanf("%d %d", &p[i].x, &p[i].y);
}

inline bool in(const slide &a, const point &b) {
	return b.x >= a.xmin && b.x <= a.xmax && b.y >= a.ymin && b.y <= a.ymax;
}

inline void init() {
	int i, j;
	memset(graph, false, sizeof(graph));
	for (i=1; i<=n; ++i) {
		for (j=1; j<=n; ++j) {
			if (in(s[i], p[j])) graph[j][i] = true;
		}
	}
}

bool dfs1(const int x) {
	int y;
	for (y=1; y<=n; ++y) {
		if (!visit1[y] && graph[x][y]) {
			visit1[y] = true;
			if (match1[y] == -1 || dfs1(match1[y])) {
				match1[y] = x;
				return true;
			} 
		}
	}
	return false;
}

bool essential(const int &x, const int &y) {
	int i;
	int res(0);
	graph[x][y] = false;
	memset(match1, -1, sizeof(match1));
	for (i=1; i<=n; ++i) {
		memset(visit1, false, sizeof(visit1));
		if (dfs1(i)) ++res;
	}
	graph[x][y] = true;
	return res != n;
}

bool dfs(const int x) {
	int y;
	for (y=1; y<=n; ++y) {
		if (!visit[y] && graph[x][y]) {
			visit[y] = true;
			if (match[y] == -1 || dfs(match[y])) {
				if (essential(x, y)) {
					match[y] = x;
					return true;
				}
			}
		}
	}
	return false;
}

void gao() {
	int i, j;
	int res(0);
	int ll;
	bool none(true);
	input();
	init();
	memset(match, -1, sizeof(match));
	for (i=1; i<=n; ++i) {
		memset(visit, false, sizeof(visit));
		if (dfs(i)) ++res;
	}
	printf("Heap %d\n", ++cn);
	for (ll=n; match[ll]==NOT_MATCHED&&ll>0; --ll);
	if (ll == 0) {
		puts("none\n");
		return;
	}
	for (i=1; i<ll; ++i) {
		if (match[i] != NOT_MATCHED) {
			none = false;
			printf("(%c,%d) ", i+'A'-1, match[i]);
		}
	}
	printf("(%c,%d)\n\n", i+'A'-1, match[i]);
}

int main() {
	//freopen("f:\\in.txt", "r", stdin);
	//freopen("f:\\out.txt", "w", stdout);
	scanf("%d", &n);
	while (n != 0) {
		gao();
		scanf("%d", &n);
	}
	return 0;
}