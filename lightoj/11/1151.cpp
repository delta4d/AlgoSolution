#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 101;
const double EPS = 1e-10;

double a[MAXN][MAXN], b[MAXN];
int t[MAXN];

template <class T> inline T fastin() {
	register char c = 0;
	register T a = 0;
	while (c < '0' || c > '9') c = getchar();
	while ('0' <= c && c <= '9') a = a * 10 + c - '0', c = getchar();
	return a;
}

bool gaussTpivot(int n, double a[][MAXN], double b[]) {
	int i, j, k, row, col, index[MAXN];
	double maxp, t;
	for (i = 0; i < n; i++) {
		index[i] = i;
	} for (k = 0; k < n; k++) {
		for (maxp = 0, i = k; i < n; i++) {
			for (j = k; j < n; j++) {
				if (fabs(a[i][j]) > fabs(maxp)) {
					maxp = a[row = i][col = j];
				}
			}
		}
		if (fabs(maxp) < EPS) {
			return false;
		}
		if (col != k) {
			for (i = 0; i < n; i++) {
				t = a[i][col];
				a[i][col] = a[i][k];
				a[i][k] = t;
			}
			j = index[col];
			index[col] = index[k];
			index[k] = j;
		}
		if (row != k) {
			for (j = k; j < n; j++) {
				t = a[k][j];
				a[k][j] = a[row][j];
				a[row][j] = t;
			}
			t = b[k];
			b[k] = b[row];
			b[row] = t;
		}
		for (j = k + 1; j < n; j++) {
			a[k][j] /= maxp;
			for (i = k + 1; i < n; i++) {
				a[i][j] -= a[i][k] * a[k][j];
			}
		}
		b[k] /= maxp;

		for (i = k + 1; i < n; i++) {
			b[i] -= b[k] * a[i][k];
		}
	}
	for (i = n - 1; i >= 0; i--) {
		for (j = i + 1; j < n; j++) {
			b[i] -= a[i][j] * b[j];
		}
	}
	for (k = 0; k < n; k++) {
		a[0][index[k]] = b[k];
	}
	for (k = 0; k < n; k++) {
		b[k] = a[0][k];
	}
	return true;
}

int main() {
	int tc, cn = 0, n;
	for (tc=fastin<int>(); tc--; ) {
		n = fastin<int>();
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		for (int i=0; i<100; ++i) t[i] = i;
		for (int i=0,a,b; i<n; ++i) {
			a = fastin<int>(), b = fastin<int>();
			t[a - 1] = b - 1;
		}
		for (int i=0; i<99; ++i) {
			if (t[i] != i) {
				a[i][i] = 1, a[i][t[i]] = -1;
				continue;
			}
			a[i][i] = 6;
			for (int j=1; j<=6; ++j) {
				int nxt = i + j;
				if (nxt >= 100) --a[i][i];
				else --a[i][nxt];
				b[i] = 6;
			}
		}
		a[99][99] = 1, b[99] = 0;
		gaussTpivot(100, a, b);
		printf("Case %d: %.10lf\n", ++cn, b[0]);
	}
	return 0;
}

// 275374	2013-10-18 19:12:41	 1151 - Snakes and Ladders	 C++	 0.172	 1168	Accepted
