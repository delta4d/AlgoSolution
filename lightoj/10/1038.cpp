#include <cstdio>
using namespace std;

const int N = 100000 + 86;

double f[N];
int c[N];

void init() {
	for (int i=1; i<N; ++i) {
		if (i > 1) f[i] = (f[i] + c[i] + 1) / c[i];
		for (int j=i<<1; j<N; j+=i) f[j] += f[i], ++c[j];
	}
}

int main() {
	init();
	int tc, cn = 0, n;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d", &n);
		printf("Case %d: %.10lf\n", ++cn, f[n]);
	}
	return 0;
}

// 254624	2013-08-23 01:29:49	 1038 - Race to 1 Again	 C++	 0.028	 2260	Accepted
