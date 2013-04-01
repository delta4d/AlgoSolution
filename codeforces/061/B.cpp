#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1000;

int f[MAXN];

int gao(int s, const int n) {
	int i, j, k;
	int cnt(1);
	for (i=s-1; i>=0; --i) {
		if (f[i] > f[i+1]) break;
		else ++cnt;
	}
	for (i=s+1; i<n; ++i) {
		if (f[i] > f[i-1]) break;
		else ++cnt;
	}
	return cnt;
}

int main() {
	int i, j, k;
	int m, n;
	int cnt, res(0);
	scanf("%d", &n);
	for (i=0; i<n; ++i) scanf("%d", f+i);
	for (i=0; i<n; ++i) {
		//printf("---%d\n", gao(i, n));
		res = max(res, gao(i, n));
	}
	printf("%d\n", res);
	return 0;
}

// 324243	 Mar 7, 2011 7:17:11 PM	delta_4d	 B - Petya and Countryside	 GNU C++	Accepted	 30 ms	 1300 KB
