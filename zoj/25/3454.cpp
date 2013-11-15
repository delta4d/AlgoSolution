#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;

const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;
const int MAXN = 100000;
int f[MAXN];
int g[MAXN];
int d[MAXN];
bool visit[MAXN];
vector<LL> num;

inline int lcm(int x, int y) {
	if (x < y) swap(x, y);
	int t;
	int tx(x), ty(y);
	if (x == 0 || y == 0) return 0;
	while (y != 0) {
		t = x % y;
		x = y;
		y = t;
	}
	return tx * (ty / x);
}

void gao(const int n, const int m) {
	int i, j, k;
	int s, t;
	LL res;
	int a(-INF);
	res = 1;
	num.clear();
	for (i=0; i<n; visit[i++]=false);
	for (i=0; i<m; ++i) {
		if (visit[g[i]]) continue;
		for (i=0; i<n; d[i++]=0);
		s = g[i];
		k = 1;
		d[s] = k;
		visit[s] = true;
		while (true) {
			t = s;
			s = f[s];
			if (d[s] > 0) break;
			visit[s] = true;
			d[s] = ++k;
		}
		a = max(d[s]-d[g[i]], a);
		//num.push_back(LL(d[t]-d[s]+1));
		res = lcm(res, LL(d[t]-d[s]+1)) % MOD;
	}
	//res = 1;
	//for (i=0; i!=num.size(); ++i) res = lcm(res, num[i]) % MOD;
	printf("%lld\n", LL(a)+res);
}

int main() {
	int i, j, k;
	int m, n;	
	//freopen("f:\\in.txt", "r", stdin);
	while (scanf("%d", &n) != EOF) {
		for (i=0; i<n; ++i) scanf("%d", f+i);
		scanf("%d", &m);
		for (i=0; i<m; ++i) scanf("%d", g+i);
		gao(n, m);
	}
	return 0;
}