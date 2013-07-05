#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 512;
char x[MAXN];
char y[MAXN];
char xy[MAXN<<1];
char ta[MAXN<<1];

inline bool gao(const int n, int &cnt) {
	int i, j, k(1);
	int len(n<<1);
	xy[len] = '\0';
	while (k <= 2000) {
		for (i=0; i<=n-1; ++i) {
			xy[i<<1] = y[i];
			xy[(i<<1)+1] = x[i];
		}
		if (strcmp(xy, ta) == 0) {
			cnt = k;
			return true;
		}
		for (i=0; i<n; ++i) {
			x[i] = xy[i];
			y[i] = xy[i+n];
		}
		++k;
	}
	return false;
}

int main() {
	int tc, len, cnt;
	int i, j, k, t;
	//freopen("f:\\in.txt", "r", stdin);
	scanf("%d", &tc);
	for (t=1; t<=tc; ++t) {
		scanf("%d", &len);
		scanf("%s %s %s", x, y, ta);
		if (gao(len, cnt)) printf("%d %d\n", t, cnt);
		else printf("%d %d\n", t, -1);
	}
	return 0;
}