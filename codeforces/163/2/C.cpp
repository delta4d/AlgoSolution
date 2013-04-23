#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 1024;

struct triple {
	int a, b, c;
	triple(int _a=0, int _b=0, int _c=0):a(_a), b(_b), c(_c) {}
};

vector <triple> op;

int dx[MAXN], dy[MAXN];
int f[MAXN][MAXN];
int rx[MAXN], ry[MAXN];
int right[MAXN];

int main() {
	int n;
	int a, b;

	scanf("%d", &n);
	for (int i=1; i<n; ++i) {
		scanf("%d%d", &a, &b);
		f[a][b] = 1;
		++dx[a], ++dy[b];
		rx[i] = ry[i] = i;
	}
	rx[n] = ry[n] = n;
	for (int i=n,j; i>=1; --i) {
		for (j=1; j<=i; ++j) if (dx[rx[j]]) break;
		if (j < i) {
			swap(rx[i], rx[j]);
			op.push_back(triple(1, i, j));
		}
	}
	for (int i=1,j; i<=n; ++i) {
		for (j=i; j<=n; ++j) if (dy[ry[j]]) break;
		if (j != i && j <= n) {
			swap(ry[i], ry[j]);
			op.push_back(triple(2, i, j));
		}
	}
	for (int i=1; i<=n; ++i) {
		for (int j=n; j>=1; --j) if (f[rx[i]][ry[j]]) {
			right[rx[i]] = j;
			break;
		}
	}
	for (int i=n,j; i>=1; --i) {
		int mx = 0, idx = 0;	
		for (j=1; j<=i; ++j) if (right[rx[j]] > mx) {
			mx = right[rx[j]], idx = j;
		}
		if (idx && idx != i) {
			swap(rx[i], rx[idx]);
			op.push_back(triple(1, i, idx));
		}
	}

	printf("%d\n", op.size());
	for (int i=0; i<op.size(); ++i) printf("%d %d %d\n", op[i].a, op[i].b, op[i].c);

	return 0;
}

// 3600627	 Apr 22, 2013 4:08:12 PM	delta_4d	 266C - Below the Diagonal	 GNU C++	Accepted	15 ms	
