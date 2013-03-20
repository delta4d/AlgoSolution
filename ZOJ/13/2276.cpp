#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 100;
int a[MAXN];
int x[MAXN], y[MAXN];

int main() {
	int i, j, k;
	int n;
	int s1, s2;
	int res;
	//freopen("f:\\in.txt", "r", stdin);
	scanf("%d", &n);
	while (n != 0) {
		for (i=0; i<n; ++i) scanf("%d", a+i);
		scanf("%d %d", &s1, &s2);
		memset(x, -1, sizeof(x));
		memset(y, -1, sizeof(y));
		x[s1] = 0, y[s2] = 0;
		for (j=0; j<n; ++j)
		for (i=0; i<n; ++i) {
			if (x[i] != -1) {
				k = i - a[i], k += n, k %= n;
				if (x[k] == -1) x[k] = x[i] + 1;
				else x[k] = min(x[k], x[i]+1);
				k = i + a[i], k %= n;
					if (x[k] == -1) x[k] = x[i] + 1;
					else x[k] = min(x[k], x[i]+1);
			}
			if (y[i] != -1) {
				k = i - a[i], k += n, k %= n;
				if (y[k] == -1) y[k] = y[i] + 1;
				else y[k] = min(y[k], y[i]+1);
				k = i + a[i], k %= n;
				if (y[k] == -1) y[k] = y[i] + 1;
				else y[k] = min(y[k], y[i]+1);
			}
		}
		res = INF;
		for (i=0; i<n; ++i) {
			if (x[i] != -1 && y[i] != -1) {
				res = min(res, x[i] + y[i]);
			}
		}
		if (res == INF) puts("Lara is traped!");
		else printf("open it on the %dth move!\n", res);
		scanf("%d", &n);
	}
	return 0;
}