#include <cstdio>
using namespace std;

bool is_prime(const int n) {
	if (n == 1) return false;
	for (int i=2; i*i<=n; ++i) if (n % i == 0) return false;
	return true;
}

int main() {
	int i, j, k;
	int n;

	for (scanf("%d", &n), i=0, k=0; i<n; ++i) {
		scanf("%d", &j);
		k += is_prime(j);
	}
	printf("%d\n", k);

	return 0;
}
