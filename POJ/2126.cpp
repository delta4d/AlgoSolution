#include <cstdio>
using namespace std;

const int MAXN = 21;
int x[MAXN];

int main() {
	int tc;
	int i, j, k;
	int n;
	//freopen("f:\\in.txt", "r", stdin);
	while (scanf("%d", &n) != EOF) {
		for (i=0; i<=n; ++i) scanf("%d", x+i);
		if (n > 2) {
			puts("NO");
		} else if (n == 0 || n == 1) {
			puts("YES");
		} else {
			puts(x[1]*x[1]>=4*x[0]*x[2] ? "NO" : "YES");
		}
	}
	return 0;
}