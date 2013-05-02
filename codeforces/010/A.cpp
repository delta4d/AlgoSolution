#include <cstdio>
using namespace std;

const int MAXN = 128;
int n, p1, p2, p3, t1, t2;
int l[MAXN], r[MAXN];
int tot = 0;

int gao(int t) {
	if (t <= t1) return t * p1;
	if (t <= t1 + t2) return t1 * p1 + (t - t1) * p2;
	return t1 * p1 + t2 * p2 + (t - t1 - t2) * p3;
}

int main() {

	scanf("%d%d%d%d%d%d", &n, &p1, &p2, &p3, &t1, &t2);
	for (int i=0; i<n; ++i) scanf("%d%d", l+i, r+i);
	for (int i=0; i<n; ++i) {
		tot += (r[i] - l[i]) * p1;
		if (i + 1 < n) tot += gao(l[i+1]-r[i]);
	}
	printf("%d\n", tot);

	return 0;
}
