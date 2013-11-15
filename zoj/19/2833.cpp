#include <cstdio>
#include <memory>
using namespace std;

const int MAXN = 100001;
int f[MAXN];
char order[2];

int find_root(int x) {
	if (f[x] < 0) return x;
	return f[x] = find_root(f[x]);
}

inline void Union(int x, int y) {
	int rx(find_root(x));
	int ry(find_root(y));
 	if (rx == ry) return;
 	f[rx] += f[ry];
 	f[ry] = rx;
 	f[y] = rx;
}

inline void init() {
	memset(f, -1, sizeof(f));
}

int main() {
	int cn(0);
	int x, y;
	int m, n;
	int i, j, k;
	//freopen("f:\\in.txt", "r", stdin);
	scanf("%d %d", &n, &m);
	while (1) {
		init();
		printf("Case %d:\n", ++cn);
		for (i=0; i<m; ++i) {
			scanf("%s", order);
			switch (order[0]) {
				case 'M': scanf("%d %d", &x, &y); Union(x, y); break;
				case 'Q': scanf("%d", &x); printf("%d\n", -f[find_root(x)]); break;
				default : puts("error"); throw "error"; break;
			}
		}
		if (scanf("%d %d", &n, &m) != EOF) puts("");
		else break;
	}
	
	return 0;
}
