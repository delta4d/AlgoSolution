#include <cstdio>
using namespace std;

int F[32];

void init() {
	F[0] = F[1] = 1;
	for (int i=2; i<32; ++i) F[i] = F[i-1] + F[i-2];
}

int main() {
	init();

	int tc;
	scanf("%d", &tc);
	for (int i, gi, j; tc; --tc) {
		scanf("%d%d%d", &i, &gi, &j);
		if (i > 1 && (gi - F[i-2]) % F[i-1]) {
			puts("-1");
			continue;
		}
		long long t = gi;
		if (i > 1 && (gi - F[i-2]) % F[i-1] == 0) t = (gi - F[i-2]) / F[i-1];
		if (t < 1) {
			puts("-1");
			continue;
		}
		long long a = 1, b = t;
		for (i=2; i<=j; ++i) t = a + b, a = b, b = t;
		printf("%lld\n", b);
	}

	return 0;
}
