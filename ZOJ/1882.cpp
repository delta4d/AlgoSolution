#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

const double eps = 1e-8;
const int MAXN = 100;
typedef vector<int> VI;
typedef VI::iterator VII;
struct point {
	double x;
	double y;
};

int n, m;
double s, v;
point hole[MAXN];
point gopher[MAXN];
VI conn[MAXN];
bool visit[MAXN];
int match[MAXN];

inline bool suc(const point &a, const point &b) {
	double d((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
	return d <= v * v * s * s + eps;
}

bool dfs(const int x) {
	int y;
	VII it;
	for (it=conn[x].begin(); it!=conn[x].end(); ++it) {
		y = *it;
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
	for (i=0; i<n; ++i) {
		memset(visit, false, sizeof(visit));
		if (dfs(i)) ++k;
	}
	return k;
}

int main() {
	int i, j, k;
	//freopen("f:\\in.txt", "r", stdin);
	while (scanf("%d %d %lf %lf", &n, &m, &s, &v) != EOF) {
		for (i=0; i<n; ++i) {
			scanf("%lf %lf", &gopher[i].x, &gopher[i].y);
			conn[i].clear();
		}
		for (i=0; i<m; ++i) scanf("%lf %lf", &hole[i].x, &hole[i].y);
		k = 0;
		for (i=0; i<n; ++i) {
			for (j=0; j<m; ++j) {
				if (suc(gopher[i], hole[j])) {
					conn[i].push_back(j);
				}
			}
		}
		printf("%d\n", n-gao());
	}
	return 0;
}