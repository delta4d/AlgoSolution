#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 10001;

int f[MAXN];
int b[MAXN];

int main() {
	int i, j, k;
	int m, n;
	int x, y;
	int a;
	//freopen("f:\\in.txt", "r", stdin);
	while (scanf("%d", &n) == 1) {
		//for (i=1; i<=n; ++i) scanf("%x", a+i);
		for (i=1; i<=n; ++i) {
			scanf("%x", &a);
			k = a - f[i-1];
			if (k <= -8) k = -8;
			else if (k >= 7) k = 7;
			f[i] = k + f[i-1];
			b[i] = k;
		}
		printf("%d\n", n>>1);
		for (i=1; i<=n; ++i,++i) {
			x = b[i], y = b[i+1];
			if (x < 0) x += 16;
			if (y < 0) y += 16;
			printf("%02x", (x<<4)+y);
			if (((i+1)>>1) % 8 == 0 || i == n - 1) puts("");
			else printf(" ");
		}
	}
	return 0;
}