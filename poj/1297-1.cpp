#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const double eps = 1e-8;
const double INF = 999999999999999.9;
const int MAXN = 101;

double f[MAXN];
int list[MAXN];

int main() {
	int m, n;
	int i, j, k;
	int index;
	double price;
	//freopen("f:\\in.txt", "r", stdin);
	f[0] = 0.0;
	scanf("%d %d", &m, &n);
	while (m != 0 || n != 0) {
		for (i=1; i<=m; ++i) {
			scanf("%d", list+i);
			f[i] = INF;
		}
		for (i=0; i<n; ++i) {
			scanf("%d %lf", &index, &price);
			for (j=m; j>=1; --j) {
				if (list[j] == index) f[j] = min(f[j], f[j-1]+price);
			}
		}
		if (fabs(f[m] - INF) < eps) puts("Impossible");
		else printf("%.2lf\n", f[m]);
		scanf("%d %d", &m, &n);
	}
	return 0;
}