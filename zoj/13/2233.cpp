#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 100;
const double eps = 1e-6;

int m, n;
int d[MAXN];
int visit[MAXN];
bool f[MAXN][MAXN];
double tank[MAXN];
double res[MAXN];

void dfs(int r, const int mark) {
	int i, j, k;
	visit[r] = mark;
	for (i=0; i<m; ++i) {
		if (visit[i] == -1 && f[r][i]) {
			dfs(i, mark);
		}
	}
}

int main() {
	int i, j, k;
	int x, y;
	int tc;
	int cnt;
	double avg, sum;
	
	//freopen("f:\\in.txt", "r", stdin);
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d %d", &m, &n);
		memset(d, 0, sizeof(d));
		memset(f, false, sizeof(f));
		memset(res, 0, sizeof(res));
		for (i=0; i<m; ++i) scanf("%lf", tank+i);
		for (i=0; i<n; ++i) {
			scanf("%d %d", &x, &y);
			--x, --y;
			f[x][y] = true;
			++d[x], ++d[y];
		}
		memset(visit, -1, sizeof(visit));
		for (i=0; i<m; ++i) {
			if (visit[i] != -1) continue;
			sum = 0;
			cnt = 0;
			dfs(i, i);
			for (k=0; k<m; ++k) {
				if (visit[k] == i) {
					sum += tank[k];
					cnt += d[k];
				}
			}
			if (cnt == 0) {
				res[i] = tank[i];
				continue;
			}
			avg = sum / cnt;
			for (k=0; k<m; ++k) {
				if (visit[k] == i) {
					res[k] = avg * d[k];
				}
			}
		}
		for (i=0; i<m; ++i) printf("%.3lf\n", res[i]);
		puts("");
	}
	return 0;
}