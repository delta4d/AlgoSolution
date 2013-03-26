#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 1000000 + 86;

int x[MAXN<<1], n;

inline int nxt(const int x, const int k) { return x % k == 0 ? x - k : x / k * k; }

int main() {
	scanf("%d", &n);
	for (int i=0; i<n; ++i) x[i] = i + 1;
	for (int k=2; k<=n; ++k) for (int i=n,j; i>0; i=j) x[i+k-2] = x[(j=nxt(i, k))+k-2];
	for (int i=0; i<n; ++i) printf("%d%s", x[i+n-1], i==n-1?"\n":" ");

	return 0;
}

// 3399791	 Mar 24, 2013 3:28:20 PM	delta_4d	 286B - Shifting	 GNU C++	Accepted	515 ms	7800 KB
