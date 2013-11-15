#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 500;
const int MAXL = 80;
struct node {
	int t;
	int w;
	node(int _t=0, int _w=0):t(_t), w(_w) {}
};

vector<node> e[MAXN];
bool fire[MAXN], visit[MAXN];
char buff[MAXN];
int d[MAXN];

int spfa(const int n) {
	int i, j, k;
	queue<int> q;
	fill(d, d+MAXN, INF);
	memset(visit, false, sizeof(visit));
	
}

int gao(const int n) {
	int i, j, k;
	int min(INF), index;
	int max;
	for (i=0; i<n; ++i) {
		if (!fire[i]) {
			fire[i] = true;
			max = spfa(n);
			if (max < min) {
				min = max;
				index = i;
			}
			fire[i] = false;
		}
	}
}

int main() {
	int i, j, k;
	int m, n;
	int x, y, w;
	freopen("f:\\in.txt", "r", stdin);
	while (scanf("%d %d", &m, &n) != EOF) {
		memset(fire, false, sizeof(fire));
		for (i=0; i<m; ++i) {
			scanf("%d", &k);
			fire[k-1] = true;
		}
		for (i=0; i<n; ++i) e[i].clear();
		gets(buff);
		while (strcmp(buff, "") != 0) {
			sscanf(buff, "%d %d %d", &x, &y, &w);
			e[x-1].push_back(node(y-1, w));
			e[y-1].push_back(node(x-1, w));
			gets(buff);
		}
		printf("%d\n", gao(n));
	}
	return 0;
}