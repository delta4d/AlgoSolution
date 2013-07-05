#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 60;

struct operation {
	int x, y, p, q;
	operation() {}
	operation(int x, int y, int p, int q):x(x), y(y), p(p), q(q) {}
	void print() { printf("%d %d %d %d\n", x, y, p, q); }
};

int f[MAXN][MAXN], c[MAXN];
int x[MAXN*MAXN], y[MAXN*MAXN];
vector <operation> op;

int main() {
	int n;

	scanf("%d", &n);
	for (int i=0; i<n; ++i) scanf("%d", c+i);
	for (int i=0; i<n; ++i) for (int j=0; j<c[i]; ++j) {
		scanf("%d", f[i]+j);
		x[f[i][j]] = i, y[f[i][j]] = j;
	}
	for (int i=0,t=1; i<n; ++i) for (int j=0; j<c[i]; ++j,++t) {
		int s = f[i][j];
		if (s == t) continue;
		op.push_back(operation(i+1, j+1, x[t]+1, y[t]+1));
		swap(f[i][j], f[x[t]][y[t]]);
		swap(x[s], x[t]), swap(y[s], y[t]);
	}
	printf("%d\n", (int)op.size());
	for (int i=0; i<(int)op.size(); ++i) op[i].print();

	return 0;
}

// 4006841	 Jul 3, 2013 5:41:35 PM	delta_4d	 B - Young Table	 GNU C++	Accepted	 15 ms	 100 KB
