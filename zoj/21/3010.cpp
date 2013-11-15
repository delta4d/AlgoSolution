#include <cstdio>
#include <bitset>
#include <memory>
#include <vector>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 11;
bitset<MAXN> state;
vector<int> conn[MAXN];
double cost[MAXN];
double max_score;
int n;
bool visit[MAXN];

inline bool done() {
	int i;
	for (i=1; i<=n; ++i) {
		if (state[i] == 1) return false;
	}
	return true;
}

void dfs(int d, double	cur_score) {
	int i, j, k;
	vector<int>::iterator it;
	if (cur_score <= max_score) return;
	if (done() && cur_score	> max_score) {
		max_score = cur_score;
		return;
	}
	for (i=d; i<=n; ++i) {
		if (!visit[i]) {
			visit[i] = true;
			for (it=conn[i].begin(); it!=conn[i].end(); ++it) {
				state.flip(*it);
			}
			dfs(d+1, cur_score*(1.0-cost[i]/100.0));
			for (it=conn[i].begin(); it!=conn[i].end(); ++it) {
				state.flip(*it);
			}
			visit[i] = false;
		}
	}
}

int main() {
	int i, j, k;
	int t, f;
	int x, y;
	int m;
	//freopen("f:\\in.txt", "r", stdin);
	scanf("%d %d", &n, &m);
	while (n != 0 || m != 0) {
		memset(conn, false, sizeof(conn));
		for (x=1; x<=n; ++x) conn[x].clear();
		for (x=1; x<=n; ++x) {
			conn[x].push_back(x);
			scanf("%d", &t);
			for (i=0; i<t; ++i) {
				scanf("%d", &y);
				conn[x].push_back(y);
			}
			scanf("%lf", cost+x);
		}
		max_score = -INF;
		memset(visit, false, sizeof(visit));
		state.set();
		dfs(1, (double)m);
		if (max_score < 0) printf("-1\n");
		else printf("%.2lf\n", max_score);
		scanf("%d %d", &n, &m);
	}
	return 0;
}