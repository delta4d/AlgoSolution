#include <map>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;

const int INF = 0x3f3f3f3f;
const int MAXN = 100000;
int tt[MAXN];
map<int, int> f, g;
int p1[40];
int ten[40];
char buff[40];

inline int digit(int x) {
	int ret(0);
	while (x) {
		x /= 10;
		++ret;
	}
	return ret;
}

void init() {
	int i, j, k;
	for (i=1; i<MAXN; ++i) tt[i] = tt[i-1] + digit(i);
	for (i=1; i<40; i+=2) ten[i] = LL(pow(10.0, i/2.0));
	ten[0] = 1;
	for (i=2; i<40; i+=2) ten[i] = ten[i-2] * 10;
	for (i=1; i<40; ++i) p1[i] = 9 * ten[(i-1)<<1] * i;
}

int _find(const int ww) {
	int i, j, k;
	int sum(0), rem, rank, rr;
	int ss;
	
	for (i=1; ; ++i) {
		sum += p1[i];
		if (sum > ww) break;
	}
	sum -= p1[i];
	rem = ww - sum;
	ss = ten[(i-1)<<1];
	if (rem == 0) {
		return 9;
	} else {
		rank = rem / i;
		rr = rem - rank * i;
		if (rr == 0) {
			return (ss+rank-1) % 10;
		} else {
			sprintf(buff, "%d", ss+rank);
			return buff[rr-1] - '0';
		}
	}
}

int gao1(int);

int gao2(int n) {
	if (g.count(n)) return g[n];
	if (n == 1) return g[n] = 1;
	return g[n] = gao1(n>>1) << 1;
}

int gao1(int n) {
	if (f.count(n)) return f[n];
	if (n == 1) return f[n] = 1;
	if (n % 2 == 0) {
		return f[n] = (gao2(n>>1) << 1) - 1;
	} else {
		return f[n] = (gao2((n+1)>>1) << 1) - 1;
	}
}

int main() {
	int i, j, k;
	int m, n;
	int tc;
	
	init();
	//puts("--------");
	while (1 == scanf("%d", &n)) {
		printf("%d\n", _find(gao1(tt[n])));
	}

	return 0;
}