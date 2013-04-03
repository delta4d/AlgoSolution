#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

/**

int tot;
int x[16];

int gao(const int k, const int n) {
//	if (k == 1 && x[k] == 1) return -1;
	int cnt = 0, cur = k;
	while (cnt < 10) {
		cur = x[cur];
		++cnt;
		if (cur == 1) return cnt;
	}
	return -1;
}

bool ok(const int n) {
	for (int i=1; i<=n; ++i) {
		int d = gao(i, n);
		if (d == -1) return false;
	}	
	return true;
}

void dfs(int d, const int n) {
	if (d == n + 1) {
		tot += ok(n);
		return;
	}	
	for (int i=1; i<=n; ++i) {
		x[d] = i;
		dfs(d+1, n);
	}
}

int main() {
	for (int k=1; k<=8; ++k) {
		tot = 0;
		dfs(1, k);
		printf("%d, ", tot);
	}

	return 0;
}

**/

const long long MOD = 1000000007;
//const long long x[] = {0, 1, 6, 48, 500, 6480, 100842, 1835008};
const long long x[] = {1, 2, 9, 64, 625, 7776, 117649, 2097152};

long long gao(long long x, long long e) {
	long long ret = 1;
	while (e) {
		if (e & 1) ret = ret * x % MOD;
		x = x * x % MOD;
		e >>= 1;
	}
	return ret;
}

int main() {
	long long n, k;
	
	cin >> n >> k;
	
	long long tot = x[k-1] * gao(n-k, n-k) % MOD;

	cout << tot << endl;

	return 0;
}

// 3456974	 Apr 2, 2013 8:03:32 PM	delta_4d	 B - Polo the Penguin and Houses	 GNU C++	Accepted	 15 ms	 0 KB
