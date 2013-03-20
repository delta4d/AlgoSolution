#include <cmath>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

const double eps = 1e-8;
const int MAXN = 16;
const int MAXL = 32;

int m, n;
double f[1<<13], g[1<<13], cc[1<<13], ct[1<<13];
double u[1<<13], d[1<<13], lose[MAXN][MAXN];

struct node {
	char name[MAXL];
	double u, d;
	double r, p, s;
	
	void input() {
		scanf("%s", name);
		scanf("%lf %lf %lf %lf %lf", &u, &d, &r, &p, &s);
		double a(u+d), b(r+p+s);
		u /= a, d /= a;
		r /= b, p /= b, s /= b;
	}
} t[MAXN];

void init() {
	for (int i=0; i<(1<<13); ++i) cc[i] = __builtin_popcount(i), ct[i] = __builtin_ctz(i);
}

double rps(int a, int b) {
	return t[a].r * t[b].p + t[a].p * t[b].s + t[a].s * t[b].r;
}

double gao() {
	int i, j, k, ii, jj, kk;
	int a[MAXN], b;
	double w, l, d, p;
	
	memset(f, 0, sizeof(f));
	for (i=1; i<(1<<n); ++i) {
		if (cc[i] == 1) {
			f[i] = 0;
		} else if (cc[i] == 2) {
			int x = ct[i];
			int y = ct[i^(1<<x)];
			f[i] = 1 / (lose[x][y] + lose[y][x]);
		} else {
			double x = 0;
			double y = 1;
			for (j = (i - 1) & i; j > 0; j = (j - 1) & i) {
				k = i ^ j;
				if (cc[j] != cc[k] && ::u[j] > 0 && ::d[k] > 0) {
					p = ::u[j] * ::d[k];
					x += p;
					y += p * f[cc[j] < cc[k] ? j : k];
				}
			}
			f[i] = y / x;
		}
//		printf("%d = %lf\n", i, f[i]);
	}
	return isinf(f[(1<<n)-1]) ? -100000 : f[(1<<n)-1];
}

double zaigao() {
	int i, j, k, ii, jj, kk;
	int a[MAXN], b;
	double w, l, d, p;
	double ret(0);
	
	memset(g, 0, sizeof(g));
	g[(1<<n)-1] = 1;
	for (i=(1<<n)-1; i>0; --i) {
		if (fabs(g[i]) < eps) continue;
		if (cc[i] == 1) {
			ret = max(ret, g[i]);
		} else if (cc[i] == 2) {
			int x = ct[i];
			int y = ct[i^(1<<x)];
			if (lose[x][y] + lose[y][x] > 0) {
				g[1 << x] += lose[x][y] / (lose[x][y] + lose[y][x]) * g[i];
				g[1 << y] += lose[y][x] / (lose[x][y] + lose[y][x]) * g[i];
			}
		} else {
			double x(0);
			for (j=i&(i-1); j; j=(j-1)&i) {
				if (cc[j] != cc[i^j]) x += ::u[j] * ::d[i^j];
			}
			if (fabs(x) < eps) continue;
			for (j=i&(i-1); j; j=(j-1)&i) {
				k = i ^ j;
				if (cc[j] > cc[k]) g[k] += g[i] * ::u[j] * ::d[k] / x;
				else if (cc[j] < cc[k]) g[j] += g[i] * ::u[j] * ::d[k] / x;
			}
		}
	}
	return ret;
}

int main() {
	int i, j, k;
	int tc;
	double ret, mx;
	
//	freopen("d:\\in.txt", "r", stdin);
	init();
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d", &n);
		for (i=0; i<n; ++i) t[i].input();
		for (i=0; i<n; ++i) for (j=0; j<n; ++j) lose[i][j] = rps(i, j);
		for (u[0]=d[0]=i=1; i<(1<<n); ++i) {
			k = ct[i];
			u[i] = u[i ^ (1 << k)] * t[k].u;
			d[i] = d[i ^ (1 << k)] * t[k].d;
		}
		ret = gao();
		if (ret < 0) printf("Infinity ");
		else printf("%.3lf ", ret);
		mx = zaigao();
		vector <string> out;
		for (i=0; i<n; ++i) if (fabs(g[1<<i]-mx) < eps) out.push_back(t[i].name);
		sort(out.begin(), out.end());
		printf("%.3lf%%\n", mx*100);
		for (i=0; i<out.size(); ++i) printf("%s%s", out[i].c_str(), i==out.size()-1?"\n":" ");
	}
	return 0;
}