#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;
const int MAXN = 12;

LL n[MAXN];
LL T;

inline void gen() {
	LL x;
	LL i, j, k;
	T = 0;
	for (x=0; x<MAXN; ++x) {
		k = (x % 12) + 1;
		n[x] = (k * k * (k + 1) * (k + 1)) >> 2;
		T += n[x];
	}
}

inline void deal(LL&y1, LL&m1, LL&d1, LL&y2, LL&m2, LL&d2) {
	swap(y1, y2);
	swap(m1, m2);
	swap(d1, d2);
}

inline void gao(LL&y1, LL&m1, LL&d1, LL&y2, LL&m2, LL&d2) {
	if (y1 < y2) return;
	if (y1 == y2) {
		if (m1 < m2) return;
		if (m1 == m2) {
			if (d1 < d2) return;
			deal(y1, m1, d1, y2, m2, d2);
		} else {
			deal(y1, m1, d1, y2, m2, d2);
		}
	} else {
		deal(y1, m1, d1, y2, m2, d2);
	}
}

int main() {
	LL i, j, k;
	LL y1, y2, m1, m2, d1, d2;
	LL a, b, p;
	LL temp;
	LL A, B;
	LL res;
	gen();
	//freopen("f:\\in.txt", "r", stdin);
	while (scanf("%lld-%lld-%lld %lld-%lld-%lld", &m1, &d1, &y1, &m2, &d2, &y2) != EOF) {
		gao(y1, m1, d1, y2, m2, d2);
		a = y1, b = y2 - 1;
		if (a > b) {
			temp = 0;
		} else {
			p = (b - a + 1) / 12;
			temp = p * T + (b / 11 - (a == 0 ? -1 : (a - 1) / 11));
			for (i=a+12*p; i<=b; ++i) temp += n[i%12];
		}
		A = (((m1 - 1) * (m1 - 1) * (m1) * (m1)) >> 2) + d1 + (m1 > 1 && y1 % 11 == 0);
		B = (((m2 - 1) * (m2 - 1) * (m2) * (m2)) >> 2) + d2 + (m2 > 1 && y2 % 11 == 0);
		res = temp - A + 1 + B;
		printf("%lld\n", res);
	}
	return 0;
}