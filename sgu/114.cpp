#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;

const LL INF = 0x3f3f3f3f3f3f3f3fll;
const int MAXN = 15086;

LL A[MAXN], B[MAXN];
pair<LL, LL> f[MAXN];

int main() {
	int i, j, k;
	int m, n;
	LL mn, res, tmp;
	
	scanf("%d", &n);
	for (i=1; i<=n; ++i) scanf("%I64d %I64d", &f[i].first, &f[i].second);
	sort(f+1, f+n+1);
	for (i=1; i<=n; ++i) {
		A[i] = A[i-1] + f[i].second;
		B[i] = B[i-1] + f[i].first * f[i].second;
	}
	mn = INF;
	for (i=1; i<=n; ++i) {
		tmp = (2 * A[i] - A[n]) * f[i].first + (B[n] - 2 * B[i]);
		//printf("%I64d\n", tmp);
		if (tmp < mn) mn = tmp, res = f[i].first;
	}
	printf("%I64d.00000000000\n", res);
	
	return 0;
}