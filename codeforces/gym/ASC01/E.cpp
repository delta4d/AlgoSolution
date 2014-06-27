#include <bits/stdc++.h>
using namespace std;

int const L = 1 << 7;

char buf[L];
struct BigInt {
	int d[L], n;

	void readin() {
		scanf("%s", buf);
		n = (int)strlen(buf);
		for (int i=0; i<n; ++i) d[i] = buf[n-1-i] - '0';
	}

	void div2() {
		for (int i=n-1,cc=0; i>=0; --i) {
			cc = cc * 10 + d[i];
			d[i] = cc >> 1, cc &= 1;
		}
		if (!d[n-1]) --n;
		if (!n) ++n;
	}

	void minus(int y) {
		d[0] -= y;
		for (int i=0; i<n; ++i) {
			if (d[i] < 0) d[i] += 10, --d[i+1];
		}
		if (!d[n-1]) --n;
	}

	bool odd() {
		return d[0] & 1;
	}

	bool zero() {
		return n == 1 && d[0] == 0;
	}
} N;

int mat[32][32], A[32][32], M, P;

bool ok(int a, int b) {
	for (int i=0; i+1<M; ++i) {
		int a0 = a >> i & 1, a1 = a >> (i + 1) & 1;
		int b0 = b >> i & 1, b1 = b >> (i + 1) & 1;
		if (a0 == a1 && b0 == b1 && a0 == b0) return false;
	}
	return true;
}

void mul(int a[][32], int b[][32]) {
	int n = 1 << M, tmp[32][32]={0};
	for (int k=0; k<n; ++k) {
		for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) {
			tmp[i][j] = (tmp[i][j] + a[i][k] * b[k][j]) % P;
		}
	}
	for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) a[i][j] = tmp[i][j];
}

int main() {
#ifdef ONLINE_JUDGE
	freopen("nice.in", "r", stdin);
	freopen("nice.out", "w", stdout);
#endif
	N.readin();
	scanf("%d%d", &M, &P);
	int m = 1 << M;
	for (int i=0; i<m; ++i) for (int j=0; j<m; ++j) {
		mat[i][j] = ok(i, j);
	}
	for (int i=0; i<m; ++i) A[i][i] = 1;
	N.minus(1);
	while (!N.zero()) {
		if (N.odd()) mul(A, mat);
		mul(mat, mat);
		N.div2();
	}
	int tot = 0;
	for (int i=0; i<m; ++i) for (int j=0; j<m; ++j) {
		tot = (tot + A[i][j]) % P;
	}
	printf("%d\n", tot);
	return 0;
}

// 6964417	 2014-06-26 19:21:53	delta_4d	 E - Nice Patterns Strike Back	 GNU C++0x	Accepted	154 ms	188 KB
