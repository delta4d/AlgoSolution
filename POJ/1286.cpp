#include <cstdio>
#include <cmath>
using namespace std;

double f[25];

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

inline double polya(int p, int n) {
	int i;
	double ans(0);
	for(i=0; i<n; ++i) ans += pow(p*1.0, gcd(n, i));
	if(n % 2 == 1) {
		for(i=0; i<n; ++i) ans += pow(p*1.0, n/2+1);
	} else {
		for(i=0; i<n/2; ++i) ans += pow(p*1.0, n/2) + pow(p*1.0, n/2+1);
	}
	return ans/(n<<1);
}

inline void gen() {
	f[0] = 0;
	for (int i=1; i<25; ++i) f[i] = polya(3, i);
}

int main() {
	int i, j, k;
	int c(3), s;
	//freopen("f:\\in.txt", "r", stdin);
	gen();
	scanf("%d", &s);
	while (s >= 0) {
		printf("%.0lf\n", f[s]);
		scanf("%d", &s);
	}
	return 0;
}