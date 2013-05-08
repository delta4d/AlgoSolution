#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 1 << 7;
const int INF = MAXN;
const int MOD = 1000000007;
int C[MAXN][MAXN];
int f[MAXN>>1][MAXN>>1][MAXN>>1][MAXN];
// [i: current max number][j: i appear j times][k: total k numbers][w: total w ways]

void add(int &x, const int y) {
	x += y;	
	(x >= MOD) && (x -= MOD);
}

int main() {
	for (int i = 0, j; i < MAXN; ++i) for (C[i][0] = C[i][i] = 1, j = 1; j < i; ++j) {
		C[i][j] = min(C[i-1][j-1] + C[i-1][j], INF);
	}

	int tot = 0;
	int N, M, K;
	scanf("%d%d%d", &N, &M, &K), N >>= 1;

	f[0][1][0][1] = 1;
	for (int i = 0; i <= N && i < M; ++i) for (int j = 1; j <= N; ++j) {
		for (int k = 0; k <= N; ++k) for (int w = 0; w <= K; ++w) {
			int cc = f[i][j][k][w];
			if (!cc) continue;
			if (i) tot = (tot + (long long)cc * (M - i)) % MOD;
			for (int x = 1; x + k <= N; ++x) {
				int nw = w * C[j + x - 1][x];	
				if (nw > K) continue;
				add(f[i + 1][x][k + x][nw], cc);
			}
		}	
	}

	printf("%d\n", tot);

	return 0;
}

// 3694014	 May 8, 2013 7:54:24 PM	delta_4d	 E - Yaroslav and Arrangements	 GNU C++	Accepted	62 ms	131372 KB
