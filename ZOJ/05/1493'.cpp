#include <cstdio>
using namespace std;

int main() {
	int i, j, k;
	int m, n;
	int sum, a, bi, bii;
	//freopen("f:\\in.txt", "r", stdin);
	while (scanf("%d", &n) == 1) {
		sum = 0;
		n >>= 1;
		printf("%d\n", n);
		for (i=0; i<n; ++i) {
			scanf("%x", &a);
			k = a - sum;
			if (k <= -8) k = -8;
			else if (k >= 7) k = 7;
			sum += k;
			bi = k;
			scanf("%x", &a);
			k = a - sum;
			if (k <= -8) k = -8;
			else if (k >= 7) k = 7;
			sum += k;
			bii = k;
			if (bi < 0) bi += 16;
			if (bii < 0) bii += 16;
			printf("%x", (bi<<4)+bii);
			if (i % 8 == 7 || i == n - 1) puts("");
			else printf(" "); 
		}
	}
	return 0;
}