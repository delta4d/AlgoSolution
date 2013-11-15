#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;

const int MAXN = 1000;
struct node {
	int J;
	int F;
} r[MAXN];

bool cmp(const node &a, const node &b) {
	return double(a.J) / a.F > double(b.J) / b.F;
}

int main() {
	int n;
	int i, j, k;
	double res, c;
	//freopen("f:\\in.txt", "r", stdin);
	scanf("%lf %d", &c, &n);
	while (n != -1 || c != -1) {
		for (i=0; i<n; ++i) {
			scanf("%d %d", &r[i].J, &r[i].F);
		}
		sort(r, r+n, cmp);
		res = 0;
		for (i=0; i<n; ++i) {
			if (c >= r[i].F) {
				res += r[i].J;
				c -= r[i].F;
			} else {
				res += (double)c * r[i].J / r[i].F;
				break;
			}
		}
		printf("%.3lf\n", res);
		scanf("%lf %d", &c, &n);
	}
	return 0;
}