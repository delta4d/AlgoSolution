#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int B[3][3] = {{1, 2, 1}, {2, 4, 2}, {1, 2, 1}};

struct matrix {
	int *p;
	int n;
	
	matrix() {
		p = NULL;
	}
	void init(const int nn) {
		n = nn;
		p = new int[n*n];
	}
	bool input() {
		if (scanf("%d", &n), !n) return false;
		p = new int[n*n];
		for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) scanf("%d", p+i*n+j);
		return true;
	}
	void output() {
		for (int i=0; i<n; ++i) {
			for (int j=0; j<n; ++j) printf("%s%d", j?" ":"", p[i*n+j]);
			puts("");
		}
	}
	int ele(const int i, const int j) {
		return p[i * n + j];
	}
	void set_ele(const int i, const int j, const int x) {
		p[i*n+j] = x;
	}
	void give_away() {
		delete []p;
	}
};

inline int tran(matrix &I, const int x, const int y, const int n) {
	int i, j, k(0);
	if (x == 0 || x == n - 1 || y == 0 || y == n - 1) return I.ele(x, y);
	for (i=0; i<3; ++i) {
		for (j=0; j<3; ++j) {
			k += I.ele(x+i-1, y+j-1) * B[i][j];
		}
	}
	return k >> 4;
}

int main() {
	int i, j, k;
	int n;
	int cn(0);
	matrix I, II;
	//freopen("f:\\in.txt", "r", stdin);
	while (I.input()) {
		n = I.n;
		II.init(n);
		for (i=0; i<n; ++i) {
			for (j=0; j<n; ++j) {
				II.set_ele(i, j, tran(I, i, j, n));
			}
		}
		printf("Case %d:\n", ++cn);
		II.output();
		II.give_away();
		I.give_away();
	}
	return 0;
}