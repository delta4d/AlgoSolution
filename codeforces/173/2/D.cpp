#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 301;

int x[3];
int dp[MAXN][MAXN];

int dfs(int a, int b) {
	if (!a && !b) return dp[a][b] = 0;
	if (dp[a][b] != -1) return dp[a][b];
	int failc = 0;
	for (int i=0; i<a; ++i) failc += 1 - dfs(i, b);
	if (failc) return dp[a][b] = 1;
	for (int i=0; i<b; ++i) failc += 1 - dfs(a, i);
	if (failc) return dp[a][b] = 1;
	int mn = min(a, b);
	for (int i=mn; i>=1; --i) failc += 1 - dfs(a-i, b-i);
	if (failc) return dp[a][b] = 1;
	return dp[a][b] = 0;
}

int main() {
	int n;

	scanf("%d", &n);
	for (int i=0; i<n; ++i) scanf("%d", x+i);
	sort(x, x+n);

	if (n == 1) {
		if (x[0]) puts("BitLGM");
		else puts("BitAryo");
	} else if (n == 2) {
		memset(dp, -1, sizeof(dp));
		if (dfs(x[0], x[1])) puts("BitLGM");
		else puts("BitAryo");
	} else {
		if ((x[0] ^ x[1] ^ x[2])) puts("BitLGM");
		else puts("BitAryo");
	}

	return 0;
}

// 3318807	 Mar 15, 2013 7:28:44 AM	delta_4d	 282D - Yet Another Number Game	 GNU C++	Accepted	140 ms	300 KB
