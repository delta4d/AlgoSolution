#include <queue>
#include <cstdio>
#include <vector>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 10000;
struct edge {
	int t;
	int w;
	edge(int _t=0, int _w=0):t(_t), w(_w) {}
};
queue<int> q;
vector<edge> conn[MAXN];
int d[MAXN];
int visit[MAXN];

int main() {
	int i, j, k;
	int m, n;
	int tc;
	int x, y, w;
	int r, s, t;
	int sum;
	//freopen("f:\\in.txt", "r", stdin);
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d", &n);
		for (i=0; i<n; ++i) conn[i].clear();
		for (i=0; i<n-1; ++i) {
			scanf("%d %d %d", &x, &y, &w);
			conn[x].push_back(edge(y, w));
			conn[y].push_back(edge(x, w));
		}
		sum = 0;
		for (k=0; k<n; ++k) {
			for (i=0; i<n; ++i) {
				d[i] = INF;
				visit[i] = false;
			}
			while (!q.empty()) q.pop();
			d[k] = 0, visit[k] = true;
			q.push(k);
			while (!q.empty()) {
				s = q.front();
				q.pop();
				for (i=0; i!=conn[s].size(); ++i) {
					t = conn[s][i].t;
					w = conn[s][i].w;
					if (d[t] > d[s] + w) {
						d[t] = d[s] + w;
						if (!visit[t]) {
							visit[t] = true;
							q.push(t);
						}
					}
				}
			}
			for (i=0; i<n; ++i) sum += d[i];
		}
		printf("%.1lf\n", double(sum)/(double(n)*double(n-1)));
	}
	return 0;
}