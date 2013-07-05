#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 100000 + 86;

vector <int> e[MAXN];
vector <pair<int, int> > out;
int x[MAXN], tot;

void dfs(int r, int p) {
	x[r] = tot++;
	for (auto c: e[r]) {
		if (c == p) continue;
		if (r) printf("2 %d %d\n", r, c);
		dfs(c, r);
		if (p != -1) out.push_back(make_pair(x[r], x[c]));
	}
	if (p == -1) {
		if (e[r].size() > 1) out.push_back(make_pair(1, x[e[r][1]]));
		for (int i=1; i+1<(int)e[r].size(); ++i) out.push_back(make_pair(x[e[r][i]], x[e[r][i+1]]));
	}
}

int main() {
	int n;

	scanf("%d", &n);
	for (int i=1, a, b; i<n; ++i) {
		scanf("%d%d", &a, &b);
		e[a].push_back(b), e[b].push_back(a);
	}
	printf("%d\n", n-1);
	dfs(1, -1);
//	for (int i=1; i<=n; ++i) printf("%d ", x[i]); puts("");
	for (auto v: out) printf("%d %d\n", v.first, v.second);

	return 0;
}

// 4025024	 Jul 5, 2013 10:02:58 AM	delta_4d	 D - T-decomposition	 GNU C++0x	Accepted	 218 ms	 9200 KB
