#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long LL;
const int MAXN = 100000 + 86;
#define LB(x) (lower_bound(px, px+tot, (x)) - px)
#define UB(x) (upper_bound(px, px+tot, (x)) - px)
#define LS(x) ((x) << 1)
#define RS(x) (LS(x) ^ 1)

struct node {
	LL cnt, sum, xsum;
	node(LL _cnt=0, LL _sum=0, LL _xsum=0):cnt(_cnt), sum(_sum), xsum(_xsum) {}
	node operator+(node &a) {
		return node(cnt + a.cnt, sum + a.sum, xsum + a.xsum - sum * a.cnt + a.sum * cnt);
	}
} T[MAXN<<3];
int x[MAXN], px[MAXN<<1], tot;
int t[MAXN], p[MAXN], d[MAXN];

void add(int r, int L, int R, const int sgn, const int v, const int k) {
	if (L == R) {
		T[r].cnt += sgn, T[r].sum += sgn * v; 
		return;
	}
	int M = (L + R) >> 1;
	if (k <= M) add(LS(r), L, M, sgn, v, k);
	else add(RS(r), M+1, R, sgn, v, k);
	T[r] = T[LS(r)] + T[RS(r)];
}

node sum(int r, int L, int R, const int ll, const int rr) {
	if (ll > rr) return node(0, 0, 0);
	if (ll <= L && R <= rr) return T[r];	
	int M = (L + R) >> 1;
	if (rr <= M) return sum(LS(r), L, M, ll, rr);
	if (ll > M) return sum(RS(r), M+1, R,  ll, rr);
	node A = sum(LS(r), L, M, ll, rr), B = sum(RS(r), M+1, R, ll, rr);
	return A + B;
}

int main() {
	int n, m;

	scanf("%d", &n);
	for (int i=0; i<n; ++i) scanf("%d", x+i), px[tot++] = x[i];
	scanf("%d", &m);
	for (int i=0; i<m; ++i) {
		scanf("%d%d%d", t+i, p+i, d+i);
		if (t[i] == 1) px[tot++] = (x[--p[i]] += d[i]);
	}
	for (int i=0; i<m; ++i) if (t[i] == 1) x[p[i]] -= d[i];
	sort(px, px+tot);
	tot = unique(px, px+tot) - px;
	for (int i=0; i<n; ++i) add(1, 0, tot-1, 1, x[i], LB(x[i]));
	for (int i=0; i<m; ++i) {
		if (t[i] == 1) {
			add(1, 0, tot-1, -1, x[p[i]], LB(x[p[i]]));
			x[p[i]] += d[i];
			add(1, 0, tot-1, 1, x[p[i]], LB(x[p[i]]));
		} else {
			printf("%I64d\n", sum(1, 0, tot-1, LB(p[i]), UB(d[i])-1).xsum);	
		}
	}

	return 0;
}

// 3531710	 Apr 14, 2013 10:47:22 AM	delta_4d	 295E - Yaroslav and Points	 GNU C++	Accepted	359 ms	21100 KB
