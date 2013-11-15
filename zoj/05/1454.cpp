#include <cstdio>
#include <cstring>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 1001;
int x[13];
int d[13][MAXN];

int main() {
	int n, max, min;
	int i, j, k;
	int h, s, f;
	int temp;
	//freopen("f:\\in.txt", "r", stdin);
	scanf("%d", &n);
	while (n != 0) {
		max = -INF;
		scanf("%d %d %d", &h, &s, &f);
		for (i=1; i<=n; ++i) {
			scanf("%d", x+i);
			max = max > x[i] ? max : x[i];
		}
		for (i=0; i<=max; ++i) {
			if (i < x[1]) d[1][i] = INF;
			else if (i == x[1]) d[1][i] = (h + s) * x[1];
			else d[1][i] = d[1][i-1] + h + s;
		}
		for (i=2; i<=n; ++i) {
			for (j=x[i]; j<=max; ++j) {
				d[i][j] = INF;
				for (k=x[i-1]; k<=max; ++k) {
					if (k < j) {
						temp = (j - k) * h + j * s;
						d[i][j] = d[i][j] < d[i-1][k] + temp ? d[i][j] : d[i-1][k] + temp;
					} else {
						temp = (k - j) * f + j * s;
						d[i][j] = d[i][j] < d[i-1][k] + temp ? d[i][j] : d[i-1][k] + temp;
					}
				}
			}
		}
		min = INF;
		for (i=x[n]; i<=max; ++i) min = min < d[n][i] ? min : d[n][i];
		printf("%d\n", min);
		scanf("%d", &n);
	}
	return 0;
}
