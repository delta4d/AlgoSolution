#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

typedef pair <int, int> PII;
const int MAXN = 100000 + 86;
#define MP(x, y) make_pair((x), (y))
#define PB push_back
#define LS(x) ((x) << 1)
#define RS(x) (LS(x) ^ 1)
#define MID(x, y) ((x) + (y)) >> 1

vector <int> e[MAXN];
vector <PII> s[MAXN];
int l[MAXN], r[MAXN];
int t, c[MAXN];
int n, q;

struct seg_tree {
	int nz[MAXN<<2], x[MAXN<<2];

	void init() {
		memset(nz, 0, sizeof(nz));
		memset(x, 0, sizeof(x));
	}

	void update(int r, int L, int R) {
		if (x[r]) nz[r] = R - L + 1;
		else if (L >= R) nz[r] = 0;
		else nz[r] = nz[LS(r)] + nz[RS(r)];
	}

	void add(int r, int L, int R, const int a, const int b, const int off) {
//		printf("%d %d %d %d %d %d\n", r, L, R, a, b, off);
		if (a <= L && R <= b) {
			x[r] += off;
			update(r, L, R);
			return;
		}
		int M = MID(L, R);
		if (a <= M) add(LS(r), L, M, a, b, off);
		if (b > M) add(RS(r), M+1, R, a, b, off);
		update(r, L, R);
	}

	int sum() {
		return max(0, nz[1]-1);
	}

	void info(int r, int L, int R) {
		printf("%d [%d, %d] x: %d, nz: %d\n", r, L, R, x[r], nz[r]);
		if (L >= R) return;
		int M = MID(L, R);
		info(LS(r), L, M);
		info(RS(r), M+1, R);
	}
} T;

int dfs(int r, int p) {
	l[r] = ::r[r] = t;
	for (int i=0; i<e[r].size(); ++i) if (e[r][i] != p) ++t, ::r[r] = max(::r[r], dfs(e[r][i], r));
	return ::r[r];
}

void gao(int r, int p) {
	for (int i=0; i<s[r].size(); ++i) T.add(1, 0, n-1, s[r][i].first, s[r][i].second, 1);
	c[r] = T.sum();
	for (int i=0; i<e[r].size(); ++i) if (e[r][i] != p) gao(e[r][i], r); 
	for (int i=0; i<s[r].size(); ++i) T.add(1, 0, n-1, s[r][i].first, s[r][i].second, -1);
}

int main() {
	scanf("%d%d", &n, &q);
	for(int i=1,a,b; i<n; ++i) {
		scanf("%d%d", &a, &b), --a, --b;
		e[a].PB(b), e[b].PB(a);
	}
	dfs(0, -1);
	for (int a,b; q--; ) {
		scanf("%d%d", &a, &b), --a, --b;
		s[a].PB(MP(l[a], r[a])), s[a].PB(MP(l[b], r[b]));
		s[b].PB(MP(l[a], r[a])), s[b].PB(MP(l[b], r[b]));
	}
//	T.add(1, 0, n-1, 1, 3, 1);
//	T.info(1, 0, n-1);
//	puts("==============");
//	T.add(1, 0, n-1, 2, 4, 1);
//	T.info(1, 0, n-1);
//	printf("%d\n", T.sum());
	gao(0, -1);
	for (int i=0; i<n; ++i) printf("%d%s", c[i], i==n-1?"\n":" ");

	return 0;
}

// 3782529	 May 27, 2013 10:38:23 AM	delta_4d	 E - Little Elephant and Tree	 GNU C++	Accepted	 546 ms	 15800 KB
