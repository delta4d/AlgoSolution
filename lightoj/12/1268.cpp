#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef unsigned int uint;
const int MAXN = 50;
char s[MAXN+1], c[MAXN+1], t[MAXN+1];
uint mat[MAXN][MAXN];

void matrix_mul(const uint n, uint x[][MAXN], uint y[][MAXN]) {
	uint i, j, k;
	uint tmp[MAXN][MAXN];

	memset(tmp, 0, sizeof(tmp));
	for (i=0; i<n; ++i) for (j=0; j<n; ++j) for (k=0; k<n; ++k) {
		tmp[i][j] = tmp[i][j] + x[i][k] * y[k][j];
	}
	for (i=0; i<n; ++i) for (j=0; j<n; ++j) x[i][j] = tmp[i][j];
}

void matrix_binary_exp(const uint n, uint x[][MAXN], uint exp) {
	uint i, j, k;
	uint tmp[MAXN][MAXN];

	memset(tmp, 0, sizeof(tmp));
	for (i=0; i<n; ++i) tmp[i][i] = 1;
	while (exp) {
		if (exp & 1) matrix_mul(n, tmp, x);
		matrix_mul(n, x, x);
		exp >>= 1;
	}
	for (i=0; i<n; ++i) for (j=0; j<n; ++j) x[i][j] = tmp[i][j];
}

int pre(int len) {
	for (int i=len; i>0; --i) {
		bool match = true;
		for (int j=0; match&&j<i; ++j) match = (s[j] == t[len-i+j]);
		if (match) return i;
	}
	return 0;
}

void init(int &len, int &choice) {
	len = (int)strlen(s), choice = (int)strlen(c);
	strcpy(t, s);
	memset(mat, 0, sizeof(mat));
	for (int i=0; i<len; ++i) {
		char tmp = t[i];
		for (int j=0; c[j]; ++j) {
			t[i] = c[j];
			int p = pre(i + 1);
			if (p < len) ++mat[p][i];
		}
		t[i] = tmp;
	}
}

int main() {
	int tc, cn = 0, n, len, choice;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d%s%s", &n, c, s);
		init(len, choice);
		matrix_binary_exp(len, mat, n-1);
		uint tot = 0;
		for (int i=0; i<len; ++i) tot += (choice - 1) * mat[i][0] + mat[i][1];
		printf("Case %d: %u\n", ++cn, tot);
	}
	return 0;
}

// 305497	2013-12-28 23:22:18	 1268 - Unlucky Strings	 C++	 0.388	 1096	Accepted
