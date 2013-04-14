#include <queue>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;

const LL MOD = 1000000007;
const LL MAXN = 64;

struct node {
	int a, b;
	int turn;

	node() {}
	node(int _a, int _b, int _turn):
		a(_a), b(_b), turn(_turn) {}
};

LL C[MAXN][MAXN];
int p[MAXN][MAXN][2];
int t[MAXN][MAXN][2];
queue <node> q;

int n, k;
int a, b;

void gao(int a, int b) {
	p[a][b][0] = 0;
	t[a][b][0] = 1;
	q.push(node(a, b, 0));
	while (!q.empty()) {
		node cc = q.front();
		q.pop();
		int sa = cc.a, sb = cc.b, tt = cc.turn ^ 1;
		if (cc.turn) sa = ::a - sa, sb = ::b - sb;
		for (int i=sa; i>=0; --i) {
			for (int j=sb; j>=0; --j) {
				int sum = i * 50 + j * 100;
				if (!sum || sum > k) continue;
				int aa = cc.a - i, bb = cc.b - j;
				if (cc.turn) aa = cc.a + i, bb = cc.b + j;
				if (p[aa][bb][tt] == -1) {
					q.push(node(aa, bb, tt));
					p[aa][bb][tt] = p[cc.a][cc.b][cc.turn] + 1;
				}
				if (p[aa][bb][tt] == p[cc.a][cc.b][cc.turn] + 1) {
					LL xx = C[sa][i] * C[sb][j] % MOD;
					t[aa][bb][tt] = (t[aa][bb][tt] + xx * t[cc.a][cc.b][cc.turn]) % MOD;
				}
			}
		}	
	}
	cout << p[0][0][1] << endl;
	cout << t[0][0][1] << endl;
}

void init() {
	for (int i=0; i<MAXN; ++i) {
		C[i][0] = C[i][i] = 1;
		for (int j=1; j<i; ++j) {
			C[i][j] = (C[i-1][j-1] + C[i-1][j]) % MOD;
		}
	}
	memset(p, -1, sizeof(p));
}

int main() {
	ios_base::sync_with_stdio(false);

	init();
	int x;
	cin >> n >> k;
	for (int i=0; i<n; ++i) {
		cin >> x;
		x == 50 ? ++a : ++b;
	}
	gao(a, b);

	return 0;
}

// 3516042	 Apr 12, 2013 9:43:02 AM	delta_4d	 295C - Greg and Friends	 GNU C++	Accepted	 15 ms	 200 KB
