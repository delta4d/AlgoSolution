#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 0x7fffffff;
const int MAXN = 50000;

int w[MAXN+1], h[MAXN];

int main() {
	int i, j, k;
	int n;
	int res;
	int left, right;
	//freopen("f:\\in.txt", "r", stdin);
	while (scanf("%d", &n), n+1) {
		for (i=0; i<n; ++i) scanf("%d %d", &k, h+i), w[i+1] = w[i] + k;
		res = -INF;
		for (k=0; k<n; ++k) {
			for (left=k; left>=0; --left) if (h[left] < h[k]) break;
			for (right=k; right<n; ++right) if (h[right] < h[k]) break;
			res = max(res, (w[right] - w[left+1]) * h[k]);
		}
		printf("%d\n", res);
	}
	return 0;
}