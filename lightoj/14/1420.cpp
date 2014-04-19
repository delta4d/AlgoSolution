#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 101;
const int MOD = 1000000007;

int f[2][N][N];
char A[N+1]="A", B[N+1]="B", C[N+1]="C";

inline void add(int &a, int b) {
	a += b;
	if (a >= MOD) a -= MOD;
	if (a < 0) a += MOD;
}

int gao() {
	f[0][0][0] = 1;
	int a = strlen(A+1), b = strlen(B+1), c = strlen(C+1);
	int cur = 0, nxt = 1;
	for (int i=0; i<=a; ++i) {
		nxt = cur ^ 1;
		for (int j=0; j<=b; ++j) for (int k=0; k<=c; ++k) {
			if (!i && !j && !k) continue;
			int &cc = f[cur][j][k];
			cc = 0;
			if (C[k] == A[i]) add(cc, f[nxt][j][k-1]);
			if (C[k] == B[j]) add(cc, f[cur][j-1][k-1]);
			if (i) {
				add(cc, f[nxt][j][k]);
				if (C[k] == B[j]) add(cc, -f[nxt][j-1][k-1]);
			}
			if (j) {
				add(cc, f[cur][j-1][k]);
				if (C[k] == A[i]) add(cc, -f[nxt][j-1][k-1]);
			}
			if (i && j) add(cc, -f[nxt][j-1][k]);
		}
		cur = nxt;
	}
	return f[cur^1][b][c];
}

int main() {
	int tc, cn = 0;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%s%s%s", A+1, B+1, C+1);
		printf("Case %d: %d\n", ++cn, gao());
	}
	return 0;
}

// 304238	2013-12-25 23:40:11	 1420 - Subsequences forming Strings	 C++	 1.096	 1168	Accepted
