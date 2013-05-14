#include <cstdio>
using namespace std;

int main() {
	int n;

	scanf("%d", &n);

	if (n % 2 == 0) return puts("-1"), 0;

	for (int i=0; i<n; ++i) printf("%d%s", i, i==n-1?"\n":" ");
	for (int i=0; i<n-1; ++i) {
		int j = (n - 2 - 2 * i) % n;
		if (j < 0) j += n;
		printf("%d ", j);
	}
	printf("%d\n", 0);
	for (int i=n-2; i>=0; --i) printf("%d ", i);
	printf("%d\n", n - 1);

	return 0;
}

// 3706855	 May 12, 2013 5:14:28 PM	delta_4d	 A - Lucky Permutation Triple	 GNU C++	Accepted	 125 ms	 0 KB
