#include <cstdio>
#include <cstring>
using namespace std;

const double eps = 1e-8;
const int MAXN = 101;
const double INF = 999999999.0;

double cost[MAXN][MAXN];
double d[MAXN], w[MAXN];
bool visit[MAXN];

void gao(const int n) {
	int i, j, k;
	int index;
	double max;
	memset(visit, false, sizeof(visit));
	memset(d, 0, sizeof(d));
	d[n] = 1.0;
	for (k=0; k<n; ++k) {
		max = -INF;
		for (i=1; i<=n; ++i) {
			if (!visit[i] && max + eps < d[i]) {
				max = d[i];
				index = i;
			}
		}
		visit[index] = true;
		for (i=1; i<=n; ++i) {
			if (!visit[i] && d[i] + eps < d[index] * cost[index][i]) {
				d[i] = d[index] * cost[index][i];
			}
		}
	}
	double sum(0.0);
	for (i=1; i<n; ++i) sum += w[i] * d[i];
	printf("%.2lf\n", sum);
}

int main() {
	int i, j, k;
	int m, n;
	int x, y;
	double v;
	//freopen("f:\\in.txt", "r", stdin);
	while (scanf("%d %d", &n, &m) != EOF) {
		for (i=1; i<n; ++i) scanf("%lf", w+i);
		memset(cost, 0, sizeof(cost));
		for (i=0; i<m; ++i) {
			scanf("%d %d %lf", &x, &y, &v);
			cost[x][y] = cost[y][x] = 1.0 - v > cost[x][y] ? 1.0 - v : cost[x][y];
		}
		gao(n);
	}
	return 0;
}