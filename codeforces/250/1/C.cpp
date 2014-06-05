#include <cstdio>
#include <algorithm>
using namespace std;

using ll = long long;
int const N = 222;
int const M = 1e9 + 7;

int n;
ll f[N][N];
struct point {
	ll x, y;
	point(ll _x=0, ll _y=0):x(_x), y(_y) {}
	ll operator*(const point &rhs) const { return x * rhs.y - y * rhs.x; }
	point operator-(const point &rhs) const { return point(x-rhs.x, y-rhs.y); }
} p[N];

int main() {
	scanf("%d", &n);
	for (int i=0; i<n; ++i) scanf("%I64d%I64d", &p[i].x, &p[i].y);
	ll area = 0;
	for (int i=1; i+1<n; ++i) area += (p[i] - p[0]) * (p[i+1] - p[0]);
	if (area < 0) reverse(p, p+n);
	for (int i=0; i<n; ++i) f[i][i] = f[i][(i+1)%n] = 1;
	for (int step=2; step<n; ++step) for (int i=0; i<n; ++i) {
		int j = (i + step) % n;
		for (int t=1; t<=step-1; ++t) {
			int k = (i + t) % n;
			if ((p[k] - p[i]) * (p[j] - p[i]) > 0) {
				f[i][j] = (f[i][j] + f[i][k] * f[k][j]) % M;
			}
		}
	}
	printf("%I64d\n", f[0][n-1]);
	return 0;
}

// 6785735	 2014-06-03 11:34:08	delta_4d	 C - The Child and Polygon	 GNU C++0x	Accepted	 78 ms	 400 KB
