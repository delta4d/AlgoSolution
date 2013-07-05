#include <cstdio>
using namespace std;

int f[31];

inline void gen() {
	int i;
	f[0] = 1;
	f[2] = 3;
	for (i=4; i<=30; i+=2) f[i] = 4*f[i-2] - f[i-4];
}

int main() {
	int n;
	gen();
	scanf("%d", &n);
	while (n != -1) {
		printf("%d\n", n%2?0:f[n]);
		scanf("%d", &n);
	}
	return 0;
}