#include <cstdio>
#include <vector>
using namespace std;

const int MAXN = 100000 + 86;

vector <int> f[MAXN];

double dfs(int d, int r, int p) {
	double tot = 1.0 / d;
	for (int i=0; i<(int)f[r].size(); ++i) {
		if (f[r][i] == p) continue;
		tot += dfs(d+1, f[r][i], r);
	}	
	return tot;
}

int main() {
	int n;
	int a, b;

	scanf("%d", &n);
	for (int i=1; i<n; ++i) {
		scanf("%d%d", &a, &b), --a, --b;
		f[a].push_back(b);
		f[b].push_back(a);
	}
	printf("%.16lf\n", dfs(1, 0, -1));

	return 0;
}

// 3427460	 Mar 31, 2013 5:10:44 PM	delta_4d	 280C - Game on Tree	 GNU C++	Accepted	93 ms	9100 KB
