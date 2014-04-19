#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

char s[10][10];
bool v[100][100][100];
struct node {
	int a, b, c, p;
	node(int _a=0, int _b=0, int _c=0, int _p=0):a(_a), b(_b), c(_c), p(_p) {}
	bool exit(int e[]) {
		int cc[] = {a, b, c};
		sort(cc, cc+3);
		return e[0] == cc[0] && e[1] == cc[1] && e[2] == cc[2];
	}
};
queue <node> q;

void F(int n, int x, int y, int &tx, int &ty) {
	tx = min(n-1, max(0, tx)), ty = min(n-1, max(0, ty));
	if (s[tx][ty] == '#') tx = x, ty = y;
}

int gao(const int n) {
	int ep[3], sp[3];
	for (int i=0,en=0,sn=0; i<n; ++i) for (int j=0; j<n; ++j) {
		if (s[i][j] == 'X') ep[en++] = i * 10 + j;
		else if ('A' <= s[i][j] && s[i][j] <= 'C') sp[sn++] = i * 10 + j;
	}
	sort(ep, ep+3);
	memset(v, false, sizeof(v));
	while (!q.empty()) q.pop();
	q.push(node(sp[0], sp[1], sp[2]));
	v[sp[0]][sp[1]][sp[2]] = true;
	while (!q.empty()) {
		node tt = q.front(); q.pop();
		if (tt.exit(ep)) return tt.p;
		int xa = tt.a / 10, ya = tt.a % 10, xb = tt.b / 10, yb = tt.b % 10, xc = tt.c / 10, yc = tt.c % 10;
		for (int k=0; k<4; ++k) {
			int txa = xa + dx[k], txb = xb + dx[k], txc = xc + dx[k];
			int tya = ya + dy[k], tyb = yb + dy[k], tyc = yc + dy[k];
			F(n, xa, ya, txa, tya);
			F(n, xb, yb, txb, tyb);
			F(n, xc, yc, txc, tyc);
			if (txa == txb && tya == tyb && txb == xb && tyb == yb ||
				txa == txc && tya == tyc && txc == xc && tyc == yc) txa = xa, tya = ya;
			if (txb == txc && tyb == tyc && txc == xc && tyc == yc || 
				txb == txa && tyb == tya && txa == xa && tya == ya) txb = xb, tyb = yb;
			if (txc == txa && tyc == tya && txa == xa && tya == ya ||
				txc == txb && tyc == tyb && txb == xb && tyb == yb) txc = xc, tyc = yc;
			int sa = txa * 10 + tya, sb = txb * 10 + tyb, sc = txc * 10 + tyc;
			if (v[sa][sb][sc]) continue;
			v[sa][sb][sc] = true;
			q.push(node(sa, sb, sc, tt.p+1));
		}
	}
	return -1;
}

int main() {
	int tc, cn = 0, n;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d", &n);
		for (int i=0; i<n; ++i) scanf("%s", s[i]);
		printf("Case %d: ", ++cn);
		int p = gao(n);
		if (p == -1) puts("trapped");
		else printf("%d\n", p);
	}
	return 0;
}

// 295470	2013-12-04 20:01:54	 1055 - Going Together	 C++	 0.036	 2360	Accepted
