#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 500;
int x[MAXN], y[MAXN];

int main() {
	int i, j, k, t;
	int sx, sy;
	int xx, yy;
	int res, cur;
	int tx, ty;
	//freopen("f:\\in.txt", "r", stdin);
	scanf("%d", &k);
	while (k != 0) {
		scanf("%d %d", &sx, &sy);
		for (i=0; i<k; ++i) scanf("%d %d", x+i, y+i);
		scanf("%d %d", &xx, &yy);
		res = -INF;
		for (i=1; i<=sx; ++i) {
			for (j=1; j<=sy; ++j) {
				cur = 0;
				tx = min(i+xx-1, sx), ty = min(j+yy-1, sy);
				for (t=0; t<k; ++t) {
					if (x[t] >= i && x[t] <= tx && y[t] >= j && y[t] <= ty) ++cur;
				}
				res = max(res, cur);
			}
		}
		printf("%d\n", res);
		scanf("%d", &k);
	}
	return 0;
}