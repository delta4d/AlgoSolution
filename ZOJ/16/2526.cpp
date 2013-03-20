#include <cstdio>
#include <cstring>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 500;
int graph[MAXN][MAXN];
int path[MAXN];
int cnt[MAXN];
int w[MAXN];
int d[MAXN];
int bean[MAXN];
bool visit[MAXN];

void gao(const int n, const int s, const int t) {
	int i, j, k;
	int min, index;
	int temp;
	int p[MAXN];
	int c;
	memset(cnt, 0, sizeof(cnt));
	memset(path, -1, sizeof(path));
	memset(visit, false, sizeof(visit));
	for (i=0; i<n; ++i) d[i] = INF, bean[i] = -INF;
	d[s] = 0, cnt[s] = 1, bean[s] = w[s];
	for (k=0; k<n; ++k) {
		min = INF;
		for (i=0; i<n; ++i) {
			if (!visit[i] && d[i] < min) {
				min = d[i];
				index = i;
			}
		}
		visit[index] = true;
		for (i=0; i<n; ++i) {
			if (!visit[i]) {
				temp = d[index] + graph[index][i];
				if (temp < d[i]) {
					path[i] = index;
					bean[i] = bean[index] + w[i];
					cnt[i] = 1;
					d[i] = temp;
				} else if (temp != INF && temp == d[i]) {
					cnt[i] += cnt[index];
					if (bean[index] + w[i] > bean[i]) {
						bean[i] = bean[index] + w[i];
						path[i] = index;
					}
				}
			}
		}
	}
	printf("%d %d\n", cnt[t], bean[t]);
	k = 0, c = t;
	while (path[c] != -1) {
		p[k++] = c;
		c = path[c];
	}
	printf("%d", s);
	for (i=k-1; i>=0; --i) {
		printf(" %d", p[i]);
	}
	puts("");
}

int main() {
	int m, n, s, t;
	int i, j, k;
	int x, y, v;
	//freopen("f:\\in.txt", "r", stdin);
	while (scanf("%d %d %d %d", &n, &m, &s, &t) != EOF) {
		for (i=0; i<n; ++i) scanf("%d", w+i);
		for (i=0; i<n; ++i) for (j=0; j<n; ++j) graph[i][j] = INF;
		for (i=0; i<m; ++i) {
			scanf("%d %d %d", &x, &y, &v);
			graph[x][y] = graph[y][x] = v;
		}
		gao(n, s, t);
	}
	return 0;
}