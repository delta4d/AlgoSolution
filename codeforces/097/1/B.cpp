#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;

LL x[16], y[16];
LL idx[16];
bool ok;
bool visit[16];
LL out[16];

LL xmult(int a, int b, int c) {
	return (x[c] - x[a]) * (y[b] - y[a]) - (x[b] - x[a]) * (y[c] - y[a]);
}

LL dmult(int a, int b, int c) {
	return (x[c] - x[a]) * (x[b] - x[a]) + (y[c] - y[a]) * (y[b] - y[a]);
}

LL dis(int a, int b) {
	return (x[a] - x[b]) * (x[a] - x[b]) + (y[a] - y[b]) * (y[a] - y[b]);
}

bool square(const int src, const int dst) {
	int i, j, k;
	int a, b, c;
	
	LL d1 = dis(idx[src], idx[src+1]);
	LL d2 = dis(idx[src+1], idx[src+2]);
	LL d3 = dis(idx[src+2], idx[src+3]);
	LL d4 = dis(idx[src+3], idx[src]);
	
	if (!(d1 == d2 && d2 == d3 && d3 == d4)) return false;
	for (i=0; i<4; ++i) {
		a = idx[(src + i)];
		b = idx[src+(i+1)%4];
		c = idx[src+(i+3)%4];
		if (dmult(a, b, c) != 0) return false;
	}
	for (i=0; i<4; ++i) {
		a = idx[(src + i)];
		b = idx[src+(i+1)%4];
		c = idx[src+(i+3)%4];
		if (xmult(a, b, c) == 0) return false;
	}
	return true;
}

bool rectangle(const int src, const int dst) {
	int i, j, k;
	int a, b, c;
	
	LL d1 = dis(idx[src], idx[src+1]);
	LL d2 = dis(idx[src+1], idx[src+2]);
	LL d3 = dis(idx[src+2], idx[src+3]);
	LL d4 = dis(idx[src+3], idx[src]);
	
	if (!(d1 == d3 && d2 == d4)) return false;
	for (i=0; i<4; ++i) {
		a = idx[(src + i)];
		b = idx[src+(i+1)%4];
		c = idx[src+(i+3)%4];
		if (dmult(a, b, c) != 0) return false;
	}
	for (i=0; i<4; ++i) {
		a = idx[(src + i)];
		b = idx[src+(i+1)%4];
		c = idx[src+(i+3)%4];
		if (xmult(a, b, c) == 0) return false;
	}
	return true;
}

void update() {
//	idx[1] = 5, idx[2] = 7, idx[3] = 6, idx[4] = 8;
//	idx[5] = 1, idx[6] = 3, idx[7] = 2, idx[8] = 4;
	if (square(1, 4) && rectangle(5, 8)) {
		ok = true;
		for (int i=1; i<=8; ++i) out[i] = idx[i];
		return;
	} 
}

void dfs(int d) {
	if (ok) return;
	if (d == 9) {
		update();
		return;
	}
	for (int i=1; i<=8; ++i) {
		if (!visit[i]) {
			visit[i] = true;
			idx[d] = i;
			dfs(d+1);
			visit[i] = false;
		}
	}
}

int main() {
	LL i, j, k;
	LL m, n;
	
//	freopen("in.txt", "r", stdin);
	
	for (i=1; i<=8; ++i) scanf("%I64d %I64d", x+i, y+i);
	ok = false;
	dfs(1);
	if (!ok) {
		puts("NO");
	} else {
		puts("YES");
		for (i=1; i<=4; ++i) printf("%I64d%c", out[i], i==4?'\n':' ');
		for (i=5; i<=8; ++i) printf("%I64d%c", out[i], i==8?'\n':' ');
	}
	
	return 0;
}

// 941219	 Dec 9, 2011 7:37:58 PM	delta_4d	 B - Rectangle and Square	 GNU C++	Accepted	 50 ms	 1300 KB
