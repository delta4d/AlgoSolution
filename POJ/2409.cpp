#include<cstdio>
using namespace std;

typedef long long LL;
const int MAXN = 33;
int f[MAXN][MAXN];

inline int gcd(int a, int b) {
	int t;
	if (a < b) a ^= b ^= a ^= b;
	while (b != 0) {
		t = a % b;
		a = b;
		b = t;
	}
	return a;
}

inline int pow(int n, int k) {
	int r(1);
	for (int i=0; i<k; ++i) r *= n;
	return r;
}

inline int polya(int p, int n) {
	int i;
	int ans(0);
	for(i=0; i<n; ++i) ans += pow(p, gcd(n, i));
	if(n % 2 == 1) {
		for(i=0; i<n; ++i) ans += pow(p, n/2+1);
	} else {
		for(i=0; i<n/2; ++i) ans += pow(p, n/2) + pow(p, n/2+1);
	}
	return ans/(n<<1);
}

inline void gen() {
	int p, n;
	for (p=1; p<MAXN; ++p) {
		for (n=1; p*n<MAXN; ++n) {
			f[p][n] = polya(p, n);
		}
	}
}

int main() {
	int i, j, k;
	int c, s;
	//freopen("f:\\in.txt", "r", stdin);
	gen();
	scanf("%d %d", &c, &s);
	while (c != 0 || s != 0) {
		printf("%d\n", f[c][s]);
		scanf("%d %d", &c, &s);
	}
	return 0;
}