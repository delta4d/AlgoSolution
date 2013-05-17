#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 81;

int l[MAXN], r[MAXN], s[MAXN<<1], sz;
double a[MAXN], b[MAXN], c[MAXN];

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
			double f[MAXN][MAXN]={0};
			int cnt=0, t = 0;
			for (int k=0; k<n; ++k) if (k != i) {
				if (l[k] <= s[j] && s[j+1] <= r[k])
					a[t] = (double)(s[j] - l[k]) / (r[k] - l[k]),
					b[t] = (double)(r[k] - s[j+1]) / (r[k] - l[k]),
					c[t] = 1 - a[t] - b[t],
					++t;
				else if (r[k] <= s[j]) ++cnt;
			} else {
				f[0][0] = (double)(s[j+1] - s[j]) / (r[k] - l[k]);	
			}
			for (int k=0; k<t; ++k) {
				for (int x=k+1; x>=0; --x) {
					for (int y=k+1-x; y>=0; --y) {
						f[x][y]	*= b[k];
						if (x) f[x][y] += f[x-1][y] * a[k];
						if (y) f[x][y] += f[x][y-1] * c[k];
					}
				}
			}
			for (int x=0; x<=n; ++x) for (int y=0; y<=n; ++y) p[x+cnt][y] += f[x][y];
		}
		double t[MAXN]={0};
		for (int x=0; x<n; ++x) for (int y=0; x+y<n; ++y) {
			for (int k=0; k<=y; ++k) t[x+k] += p[x][y] / (y + 1);
		}
		for (int k=0; k<n; ++k) printf("%.10lf%s", t[k], k==n-1?"\n":" ");
	}

	return 0;
}

// 3728960	 May 17, 2013 8:38:56 AM	delta_4d	 E - Random Ranking	 GNU C++	Accepted	 890 ms	 100 KB
