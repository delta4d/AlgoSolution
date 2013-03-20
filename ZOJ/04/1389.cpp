#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define BELOW -1
#define ABOVE 1
#define IN 0

const double eps = 1e-2;
const int MAXN = 50000;

struct cistern {
	int b, h, w, d;
	
	cistern(int _b=0, int _h=0, int _w=0, int _d=0):b(_b), h(_h), w(_w), d(_d) {}
	bool input() {
		return scanf("%d %d %d %d", &b, &h, &w, &d) == 4;
	}
	int bottom() {
		return b;
	}
	int top() {
		return b + h;
	}
	int judge(const double ch) {
		if (ch < bottom()) return -1;
		if (ch > top()) return 1;
		return 0;
	}
	int volume() {
		return h * w * d;
	}
	double volume(const double ch) {
		int ret(judge(ch));
		if (ret == IN) return (ch - bottom()) * w * d;
		if (ret == ABOVE) return volume();
		return 0;
	}
} c[MAXN];

bool cmp(const cistern a, const cistern b) {
	return a.b + a.h < b.b + b.h;
}

inline double calc_volume(const int n, const double	ch) {
	int i, j, k;
	double res(0);
	for (i=0; i<n; ++i) res += c[i].volume(ch);
	return res;
}

double gao(const int n, const double v) {
	int i, j, k;
	double left, right, mid;
	double cv, bv, ch;
	sort(c, c+n, cmp);
	left = 0, right = c[n-1].top();
	mid = left + (right - left) / 2.0;
	while (right - left >= eps) {
		cv = calc_volume(n, mid);
		if (cv < v) left = mid;
		else right = mid;
		mid = left + (right - left) / 2.0;
	}
	return mid;
}

int main() {
	int i, j, k;
	int m, n, v;
	int tc;
	int tot;
	//freopen("f:\\in.txt", "r", stdin);
	scanf("%d", &tc);
	while (tc--) {
		tot = 0;
		scanf("%d", &n);
		for (i=0; i<n; ++i) c[i].input(), tot += c[i].volume();
		scanf("%d", &v);
		if (v > tot) puts("OVERFLOW");
		else printf("%.2lf\n", gao(n, v));
	}
	return 0;
}