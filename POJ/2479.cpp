#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 50000;
int x[MAXN];
int left[MAXN], right[MAXN];
int left_max[MAXN], right_max[MAXN];

int main() {
	int tc;
	int m, n;
	int i, j, k;
	int res;
	int sum;
	//freopen("f:\\in.txt", "r", stdin);
	scanf("%d", &tc);
	for (k=1; k<=tc; ++k) {
		scanf("%d", &n);
		for (i=0; i<n; ++i) scanf("%d", x+i);
		left_max[0] = x[0];
		sum = x[0];
		for (i=1; i<n; ++i) {
			sum = max(sum+x[i], x[i]);
			left_max[i] = max(left_max[i-1], sum);
		}
		right_max[n-1] = x[n-1];
		sum = x[n-1];
		for (i=n-2; i>=0; --i) {
			sum = max(sum+x[i], x[i]);
			right_max[i] = max(right_max[i+1], sum);
		}
		res = -INF;
		for (i=0; i<n-1; ++i) res = max(res, left_max[i]+right_max[i+1]);
		printf("%d\n", res);
	}
	return 0;
}