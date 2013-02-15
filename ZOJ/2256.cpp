#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;

const double eps = 1e-8;

int main() {
	int x, n, t;
	int i, j, k, s;
	//freopen("f:\\in.txt", "r", stdin);
	scanf("%d", &x);
	while (x != 0) {
		if (x <= 4) {
			puts("10");
		} else if (x <= 8) {
			printf("%d\n", ((x-4)<<1)+10);
		} else {
			n = x >> 3;
			k = x & 7;
			s = 18 * n;
			if (k == 0) printf("%d\n", s);
			else if (k == 1) printf("%d.4\n", s+2);
			else if (k == 2) printf("%d.8\n", s+4);
			else if (k == 3) printf("%d.2\n", s+7);
			else if (k == 4) printf("%d.6\n", s+9);
			else printf("%d\n", s+10+((k-4)<<1));
		}
		scanf("%d", &x);
	}
	return 0;
}