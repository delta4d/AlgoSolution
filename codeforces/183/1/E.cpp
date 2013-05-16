#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 81;

int l[MAXN], r[MAXN], s[MAXN<<1], sz;

int main() {
	int n;

	scanf("%d", &n);
	for (int i=0; i<n; ++i) {
		scanf("%d%d", l+i, r+i);
		s[sz++] = l[i], s[sz++] = r[i];
	}
	sort(s, s+sz);
	for (int i=0; i<n; ++i) {
		double p[MAXN][MAXN]={0};
		for (int j=0; j+1<sz; ++j) if (s[j] != s[j+1] && l[i] <= s[j] && s[j+1] <= r[i]) {
			double a[MAXN]={0}, b[MAXN]={0}, c[MAXN]={0};
			for (int k=0; k<n; ++k) {
				if (r[k] <= s[j]) a[k] = 1;
				else if (l[k] >= s[j+1]) b[k] = 1;
				else a[k] = (double)(s[j] - l[k]) / (r[k] - l[k]),
					 b[k] = (double)(r[k] - s[j+1]) / (r[k] - l[k]),
					 c[k] = 1 - a[k] - b[k];
			}
			double f[MAXN][MAXN]={0};
			f[0][0] = c[i];
			for (int k=0,cc=1; k<n; ++k) if (k != i) {
				for (int x=cc; x>=0; --x) {
					for (int y=cc-x; y>=0; --y) {
						f[x][y]	*= b[k];
						if (x) f[x][y] += f[x-1][y] * a[k];
						if (y) f[x][y] += f[x][y-1] * c[k];
					}
				}
				++cc;
			}
			for (int x=0; x<=n; ++x) for (int y=0; y<=n; ++y) p[x][y] += f[x][y];
		}
		double t[MAXN]={0};
		for (int x=0; x<n; ++x) for (int y=0; x+y<n; ++y) {
			for (int k=0; k<=y; ++k) t[x+k] += p[x][y] / (y + 1);
		}
		for (int k=0; k<n; ++k) printf("%.10lf%s", t[k], k==n-1?"\n":" ");
	}

	return 0;
}

// 3725781	 May 16, 2013 9:30:16 AM	delta_4d	 E - Random Ranking	 GNU C++	Accepted	1984 ms	72 KB
