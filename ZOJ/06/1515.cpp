#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 101;

double res[MAXN];

inline int S1(int n) {
	return (n + 1) * n / 2;
}

inline int S2(int n) {
	return n * (n + 1) * (2 * n + 1) / 6;
}

inline int S3(int n) {
	int k(S1(n));
	return k * k;
}

void gen() {
	int i, j, k;
	int n;
	for (n=2; n<MAXN; ++n) {
		k = (n + 1) * (n + 1) * S1(n-1) - 2 * (n + 1) * (S2(n) - S1(n)) + S3(n) - S2(n);
		res[n] = 1.0 / double(k);
	}
	for (i=2; i<MAXN; ++i) {
		for (k=i*i; k>i*i-4; --k) 
			res[i] *= double(k);
		res[i] /= 24.0;
	}
}

int main() {
	int n, p;
	gen();
	//freopen("f:\\in.txt", "r", stdin);
	while (scanf("%d %d", &n, &p), n||p) {
		printf("%.2lf\n", res[n]*p/100.0);
	}
	return 0;
}