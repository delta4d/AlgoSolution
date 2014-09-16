#include <bits/stdc++.h>
using namespace std;

using ld = long double;
int const MAGIC = 700;

ld f[2][MAGIC];
ld *cur = f[0], *nxt = f[1];

int main() {
	int N, K;
	scanf("%d%d", &N, &K);
	for (int i=1; i<=N; ++i) {
		for (int j=1; j<MAGIC; ++j) {
			nxt[j] = ((j * cur[j] + cur[j+1] + j) / (j + 1) + j / 2.) / K + (1 - 1. / K) * cur[j];
		}
		swap(cur, nxt);
	}
	printf("%.20lf\n", (double)cur[1]*K);
	return 0;
}

// 7723740	2014-09-08 23:02:38	delta_4d	D - World of Darkraft - 2	GNU C++0x	Accepted	1076 ms	0 KB
