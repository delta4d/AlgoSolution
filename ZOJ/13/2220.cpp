#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 51;
int s, h;
int x[MAXN], y[MAXN];
bool hatch[41][41];

inline int dis2(int x1, int y1, int x2, int y2) {
	return (x1 - x2) * (x1 - x2) + (y1- y2) * (y1 - y2);
}

inline bool bound(double d, int i, int j) {
	return i + d <= s && i - d >=0 && j + d <= s && j - d >= 0;
}

inline void gao() {
	int i, j, k;
	int px(INF), py(INF);
	int d;
	
	for (i=1; i<s; ++i) {
		for (j=1; j<s; ++j) {
			if (hatch[i][j]) continue;
			d = -INF;
			for (k=0; k<h; ++k) {
				d = max(d, dis2(i, j, x[k], y[k]));
			}
			if (bound(sqrt(d), i, j)) {
				px = i;
				py = j;
				goto done;
			}
		}
	}
done:
	if (px == INF) puts("poodle");
	else printf("%d %d\n", px, py);
}

int main() {
	int i, j, k;
	int tc;
	//freopen("f:\\in.txt", "r", stdin);
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d %d", &s, &h);
		memset(hatch, false, sizeof(hatch));
		for (i=0; i<h; ++i) {
			scanf("%d %d", x+i, y+i);
			hatch[x[i]][y[i]] = true;
		}
		gao();
	}
	return 0;
}