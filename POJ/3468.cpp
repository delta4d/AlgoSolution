#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const long long MAXN = 100000 + 86;
#define LS(x) ((x) << 1)
#define RS(x) (LS(x) ^ 1)
#define MID(L, R) (((L) + (R)) >> 1)

struct seg_tree {
	struct node {
		long long  off, sum;
		node(long long _off=0, long long _sum=0):off(_off), sum(_sum) {}	
	} x[MAXN<<2];	

	void init(int r, int L, int R) {
		x[r].off = 0, x[r].sum = 0;
		if (L == R) {
			scanf("%lld", &x[r].sum);
			return;
		}
		int M = MID(L, R);
		init(LS(r), L, M);
		init(RS(r), M+1, R);
		pushup(r);
	}

	void pushdown(long long r, long long m) {
		if (!x[r].off) return;
		x[LS(r)].off += x[r].off, x[RS(r)].off += x[r].off;
		x[LS(r)].sum += ((m + 1) >> 1) * x[r].off, x[RS(r)].sum += (m >> 1) * x[r].off;
		x[r].off = 0;
	}

	void pushup(long long r) {
		x[r].sum = x[LS(r)].sum + x[RS(r)].sum;	
	}

	void add(long long r, long long L, long long R, const long long a, const long long b, const long long v) {
		if (a <= L && R <= b) {
			x[r].off += v, x[r].sum += (R - L + 1) * v;
			return;
		}	
		pushdown(r, R-L+1);
		long long M = MID(L, R);
		if (a <= M) add(LS(r), L, M, a, b, v);
		if (b > M) add(RS(r), M+1, R, a, b, v);
		pushup(r);
	}

	long long sum(long long r, long long L, long long R, const long long a, const long long b) {
		if (a <= L && R <= b) return x[r].sum;
		pushdown(r, R-L+1);
		long long M = MID(L, R);
		long long tot = 0;
		if (a <= M) tot += sum(LS(r), L, M, a, b);
		if (b > M) tot += sum(RS(r), M+1, R, a, b);
		pushup(r);
		return tot;
	}
} T;

int main() {
	long long n, q;
	long long a, b, c;
	char op[2];

	while (2 == scanf("%lld%lld", &n, &q)) {
		T.init(1, 1, n);	
		while (q--) {
			scanf("%s%lld%lld", op, &a, &b);
			if (op[0] == 'C') {
				scanf("%lld", &c);	
				T.add(1, 1, n, a, b, c);
			} else {
				printf("%lld\n", T.sum(1, 1, n, a, b));	
			}
		}
	}

	return 0;
}
