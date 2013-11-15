#include <cstdio>
#include <memory>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 2001;
bool visit[MAXN];
int d[MAXN];
int graph[MAXN][MAXN];
char s[MAXN][8];

inline void input(const int &n) {
	int i;
	for (i=0; i<n; ++i) scanf("%s", s[i]);
}

inline int dis(const int &x, const int &y) {
	int i;
	int res(0);
	for (i=0; i<8; ++i) {
		res += s[x][i] == s[y][i] ? 0 : 1;
	}
	return res;
}

inline void construct_graph(const int &n) {
	int i, j;
	for (i=0; i<n; ++i) {
		for (j=i; j<n; ++j) {
			graph[i][j] = graph[j][i] = dis(i, j);
		}
	}
}

inline int mst(const int &n) {
	int i, j, k;
	int index;
	int res(0);
	int min;
	memset(visit, false, sizeof(visit));
	fill(d, d+n, INF);
	d[0] = 0;
	for (k=0; k<n; ++k) {
		min = INF;
		for (i=0; i<n; ++i) {
			if (!visit[i] && min > d[i]) {
				min = d[i];
				index = i;
			}
		}
		visit[index] = true;
		res += d[index];
		for (i=0; i<n; ++i) {
			if (!visit[i] && graph[index][i] < d[i]) d[i] = graph[index][i];
		}
	}
	return res;
}

int main() {
	int n, m;
	int i, j, k;
	//freopen("f:\\in.txt", "r", stdin);
	scanf("%d", &n);
	while (n != 0) {
		input(n);
		construct_graph(n);
		printf("The highest possible quality is 1/%d.\n", mst(n));
		scanf("%d", &n);
	}
	return 0;
}
