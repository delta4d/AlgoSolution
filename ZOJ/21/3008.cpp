#include <cstdio>
#include <memory>
using namespace std;

typedef long long LL;
const int MAXN = 11111;
bool visit[MAXN];
int prime[MAXN];
int PN;
LL res;
struct factor {
	int fac;
	int cnt;
}f[MAXN];

inline void gen_prime(int &PN) {
	int i, j, k;
	int pn(0);
	memset(visit, false, sizeof(visit));
	for (i=2; i<=MAXN; ++i) {
		if (!visit[i]) prime[pn++] = i;
		for (j=i<<1; j<=MAXN; j+=i) visit[j] = true;
	}
	PN = pn;
}

inline void decomposition(int n, const int p, int &fn) {
	int i, j, k;
	int m(n);
	fn = 0;
	for (i=0; prime[i]*prime[i]<=m; ++i) {
		if (n % prime[i] == 0) {
			f[fn].fac = prime[i];
			f[fn].cnt = 1;
			n /= prime[i];
			while (n % prime[i] == 0) {
				++f[fn].cnt;
				n /= prime[i];
			}
			++fn;
		}
	}
	if (n != 1) {
		f[fn].fac = n;
		f[fn].cnt = 1;
		++fn;
	}
	for (i=0; i<PN; ++i) f[i].cnt *= p;
}

void dfs(const int n, const int fn, int d, int cur) {
	int i, j, k;
	LL cc;
	if (d == fn && cur <= n) {
		++res;
		return;
	}
	cc = cur;
	dfs(n, fn, d+1, cc);
	for (i=0; i<f[d].cnt; ++i) {
		cc *= f[d].fac;
		if (cc <= n) dfs(n, fn, d+1, cc);
		else break;
	}
}

int main() {
	int n, m;
	int i, j, k;
	int fn;
	//freopen("f:\\in.txt", "r", stdin);
	//freopen("f:\\out.txt", "w", stdout);
	gen_prime(PN);
	while (scanf("%d %d", &n, &m) != EOF) {
		decomposition(n, m, fn);
		res = 0;
		dfs(n, fn, 0, 1);
		printf("%lld\n", res);
	}
	return 0;
}