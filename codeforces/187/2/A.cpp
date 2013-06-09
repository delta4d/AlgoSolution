#include <cstdio>
using namespace std;

int x[1024][2];

int main() {
	int n;

	scanf("%d", &n);
	for (int i=0; i<n; ++i) scanf("%d%d", x[i], x[i]+1);
	int tot = 0;
	for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) if (j != i && x[j][1] == x[i][0]) { ++tot; break; }
	printf("%d\n", n-tot);

	return 0;
}

// 3845879	 Jun 8, 2013 11:48:33 AM	delta_4d	 A - Sereja and Bottles	 GNU C++	Accepted	15 ms	0 KB
