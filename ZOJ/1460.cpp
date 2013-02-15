#include <set>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;
typedef pair<LL, LL> PII;
typedef pair<PII, PII> PPP;
typedef set<PPP> SPPP;

const LL MAXN = 1000;
const LL MAXL = 16;

LL x1[MAXL], y1[MAXL], x2[MAXL], y2[MAXL];
SPPP iset;

inline LL gcd(LL a, LL b) {
	LL t;
	if (a < b) swap(a, b);
	while (b) {
		t = a;
		a = b;
		b = t % b;
	}
	return a;
}

inline void sim(LL x[], LL a, LL b) {
	LL s(LL(a) * LL(b) >= 0 ? 1 : -1);
	a = a >= 0 ? a : -a;
	b = b >= 0 ? b : -b;
	LL t(gcd(a, b));
	a /= t, b /= t;
	a *= s;
	x[0] = a, x[1] = b;
}

inline bool intersect(const LL i, const LL j, LL x[], LL y[]) {
	LL a1(y1[i] - y2[i]), b1(x2[i] - x1[i]), c1(x2[i] * y1[i] - x1[i] * y2[i]);
	LL a2(y1[j] - y2[j]), b2(x2[j] - x1[j]), c2(x2[j] * y1[j] - x1[j] * y2[j]);
	
	if (a1 * b2 == a2 * b1) return false;
	sim(x, c1 * b2 - c2 * b1, a1 * b2 - a2 * b1);
	sim(y, a1 * c2 - a2 * c1, a1 * b2 - a2 * b1);
}

inline bool in(const LL x[], const LL y[]) {
	return 0 <= x[0] && x[0] <= MAXN * x[1] && 0 <= y[0] && y[0] <= MAXN * y[1];
}

int main() {
	LL i, j, k;
	LL m, n;
	LL tot, cnt;
	LL x[2], y[2];
	
	//freopen("d:\\in.txt", "r", stdin);
	
	while (scanf("%lld", &n), n) {
		tot = 1;
		for (k=0, i=0; k<n; ++k) {
			scanf("%lld %lld %lld %lld", x1+i, y1+i, x2+i, y2+i);
			if (x1[i] == 0 && y1[i] == 0 && x2[i] == 0 && y2[i] == MAXN ||
				x1[i] == 0 && y1[i] == MAXN && x2[i] == 0 && y2[i] == 0 ||
			    x1[i] == 0 && y1[i] == 0 && x2[i] == MAXN && y2[i] == 0 ||
			    x1[i] == MAXN && y1[i] == 0 && x2[i] == 0 && y2[i] == 0 ||
				x1[i] == 0 && y1[i] == MAXN && x2[i] == MAXN && y2[i] == MAXN ||
				x1[i] == MAXN && y1[i] == MAXN && x2[i] == 0 && y2[i] == MAXN ||
				x1[i] == MAXN && y1[i] == MAXN && x2[i] == MAXN && y2[i] == 0 ||
				x1[i] == MAXN && y1[i] == 0 && x2[i] == MAXN && y2[i] == MAXN) continue;

			iset.clear();
			for (j=0; j<i; ++j) {
				if (intersect(i, j, x, y) && in(x, y)) {
					if (x[0] == 0) continue;
					if (x[0] == MAXN && x[1] == 1) continue;
					if (y[0] == 0) continue;
					if (y[0] == MAXN && y[1] == 1) continue; 
					iset.insert(make_pair(make_pair(x[0], x[1]), make_pair(y[0], y[1])));
				}
			}
			tot += iset.size() + 1;
			++i;
		}
		printf("%lld\n", tot);
	}

	return 0;
}