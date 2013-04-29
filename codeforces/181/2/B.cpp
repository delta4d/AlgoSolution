#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 64;

bool f[MAXN][MAXN];
bool v[MAXN];
int sz;
int n, m;	
vector <int> p[MAXN];
int c[4];

void dfs(int r, const int k) {
	v[r] = true;
	p[k].push_back(r);
	for (int i=1; i<=n; ++i) if (f[r][i] && !v[i]) {
		dfs(i, k);
	}
}

int main() {
	int x, y;

	scanf("%d%d", &n, &m);
	for (int i=0; i<m; ++i) {
		scanf("%d%d", &x, &y);
		f[x][y] = f[y][x] = true;
	}
	for (int i=1; i<=n; ++i) if(!v[i]) {
		dfs(i, sz++);	
		if (p[sz-1].size() > 3) {
			puts("-1");
			return 0;
		}
		++c[p[sz-1].size()];
	}
	if (c[1] < c[2] || (c[1] - c[2]) % 3) { puts("-1"); return 0; }
	memset(v, false, sizeof(v));
	for (int i=0; i<sz; ++i) if (p[i].size() == 2 && !v[i]) {
		for (int j=0; j<sz; ++j) if (p[j].size() == 1 && !v[j]) {
			p[i].push_back(p[j][0]);
			p[j].pop_back();
			v[i] = v[j] = true;
			break;
		}
	}
	for (int i=0; i<sz; ++i) if (p[i].size() == 1 && !v[i]) {
		v[i] = true;
		for (int k=0; k<2; ++k)
		for (int j=0; j<sz; ++j) if (p[j].size() == 1 && !v[j]) {
			v[j] = true;
			p[i].push_back(p[j][0]);
			p[j].pop_back();
			break;
		}
	}
	for (int i=0; i<sz; ++i) if (p[i].size() == 3) {
		for (int j=0; j<3; ++j) printf("%d%s", p[i][j], j==2?"\n":" ");
	}

	return 0;
}

// 3643798	 Apr 27, 2013 6:12:31 PM	delta_4d	 300B - Coach	 GNU C++	Accepted	15 ms	100 KB
