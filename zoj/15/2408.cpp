#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int MAXN = 13;
double c[MAXN];
double in[MAXN];
int cc[MAXN];

inline double f(int n, double c[], double x) {
	int i;
	double p(0.0);
	for (i=n; i>=0; --i) {
		p = p * x + c[i];
	}
	return p;
}

double gao(const int n) {
	double left(1.0), right(2.0), mid;
	double t;
	while (left <= right) {
		mid = (right - left) / 2.0 + left;
		t = f(n, c, mid);
		if (fabs(t) < eps) return mid;
		if (t < eps) left = mid;
		else right = mid;	
	}
}

int main() {
	int m, n;
	int i, j, k;
	int fc;
	int cn(0);
	double fin;
	//freopen("f:\\in.txt", "r", stdin);
	scanf("%d", &n);
	while (n != -1) {
		for (i=0; i<n; ++i) scanf("%d %lf", cc+i, in+i);
		scanf("%d %lf", &fc, &fin);
		memset(c, 0, sizeof(c));
		m = -INF;
		for (i=0; i<n; ++i) {
			k = fc - cc[i] + 1;
			c[k] = in[i];
			m = max(k, m);
		}
		c[0] = -fin;
		printf("Case %d: ", ++cn);
		printf("%.5lf\n", gao(m)-1.0);
		scanf("%d", &n);
		if (n != -1) puts("");
	}
	return 0;
}