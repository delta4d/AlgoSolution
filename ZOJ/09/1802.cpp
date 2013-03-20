#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

typedef vector<int> VI;
typedef VI::iterator VII;
const int INF = 0x3f3f3f3f;
const int MAXN = 12;
VI conn[MAXN];
int c[MAXN];
bool color[4];
double x[MAXN], y[MAXN];

inline bool connect(const int i, const int j) {
	return (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]) <= 400;
}

void dfs(const int x) {
	VII it;
	int y, k;
	memset(color, false, sizeof(color));
	for (it=conn[x].begin(); it!=conn[x].end(); ++it) {
		y = *it;
		if (c[y] != -1) {
			color[c[y]] = true;
		}
	}
	k = 0;
	while (color[k]) ++k;
	c[x] = k;
	for (it=conn[x].begin(); it!=conn[x].end(); ++it) {
		y = *it;
		if (c[y] == -1) dfs(y);
	}
}

int gao(const int n) {
	int i, j, k;
	int r(-INF);
	memset(c, -1, sizeof(c));
	for (i=0; i<n; ++i) if (c[i] == -1) dfs(i);
	for (i=0; i<n; ++i) r = max(r, c[i]);
	return r + 1;
}

int main() {
	int i, j, k;
	int cn(0);
	int n;
	//freopen("f:\\in.txt", "r", stdin);
	scanf("%d", &n);
	while (n != 0) {
		for (i=0; i<n; ++i) {
			scanf("%lf %lf", x+i, y+i);
			conn[i].clear();
		}
		for (i=0; i<n; ++i) {
			for (j=i+1; j<n; ++j) {
				if (connect(i, j)) {
					conn[i].push_back(j);
					conn[j].push_back(i);
				}
			}
		}
		printf("The towers in case %d can be covered in %d frequencies.\n", ++cn, gao(n));
		scanf("%d", &n);
	}
	return 0;
}