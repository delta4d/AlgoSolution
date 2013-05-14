#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 1000000 + 86;

int a[5000], c[MAXN];
bool v[MAXN];

int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i=0; i<n; ++i) scanf("%d", a+i);
	sort(a, a+n);
	for (int i=0; i<n; ++i) for (int j=i+1; j<n; ++j) ++c[a[j] - a[i]];
	for (int m=1,i,j,s,mx=a[n-1]+1,K=k*(k+1)>>1; ; ++m) {
		for (j=m,s=0; j<=mx&&s<=K; j+=m) s += c[j];
		if (s > K) continue;
		for (i=j=0; j<=k&&i<n; ++i) v[a[i]%m] ? ++j : v[a[i]%m] = true;
		if (j <= k) return printf("%d\n", m), 0;
		for (j=0; j<i; ++j) v[a[j]%m] = false;
	}
	return 0;
}

// 3715198	 May 13, 2013 9:33:25 AM	delta_4d	 C - Minimum Modular	 GNU C++	Accepted	 124 ms	 4900 KB
