#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1024;

pair <int, int> f[MAXN];

int main() {
	int i, j, k;
	int m, n;
	int cn(0);
	int x, y;
	
	//freopen("in.txt", "r", stdin);
	scanf("%d", &n);
	while (true) {
		for (i=0; i<n; ++i) scanf("%d %d", &f[i].first, &f[i].second);
		printf("Case %d:\n", ++cn);
		for (i=0; i<n; ++i) {
			x = y = -1;
			for (j=0; j<n; ++j) {
				if (f[j].first > f[i].first && f[j].second > f[i].second) {
					if (x == -1 || f[j].first < x || f[j].first == x && f[j].second < y) x = f[j].first, y = f[j].second;
				}
			}
			printf("%d %d\n", x, y);
		}
		scanf("%d", &n);
		if (n == 0) break;
		puts("");
	}
	return 0;
}