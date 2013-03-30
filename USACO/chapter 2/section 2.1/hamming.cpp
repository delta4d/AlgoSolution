/*
 ID: delta 4d
 PROG: hamming
 LANG: C++
 */

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 256;

vector <int> T[MAXN], S[MAXN];
int N, B, D;
int out[MAXN], tmp[MAXN];
bool find_one, visit[MAXN];

inline int h(int i, int j) {
	int cc = 0;
	for (int b=0; b<31; ++b) cc += (i & (1 << b)) != (j & (1 << b));
	return cc;
}

void dfs(int r, int p, int d) {
	if (find_one) return;	
	tmp[d] = r;
	if (d >= N - 1) {
		find_one = true;
		for (int i=0; i<N; ++i) out[i] = tmp[i];
		return;
	}
	for (int i=0; i<(int)T[r].size(); ++i) {
		int c = T[r][i];
		if (visit[c] || c == p) continue;
		for (int j=0; j<(int)S[c].size(); ++j) visit[S[c][j]] = true;
		dfs(c, r, d+1);
		if (find_one) return;
		for (int j=0; j<(int)S[c].size(); ++j) visit[S[c][j]] = false;
	}
}

int main() {
#ifndef __DELTA__
	freopen("hamming.in", "r", stdin);
	freopen("hamming.out", "w", stdout);
#endif

	scanf("%d%d%d", &N, &B, &D);
	for (int i=0; i<(1<<B); ++i) for (int j=i+1; j<(1<<B); ++j) {
		S[i].push_back(i);
		if (h(i, j) >= D) T[i].push_back(j);
		else { S[i].push_back(j); S[j].push_back(i); }
	}
	for (int i=0; i<(int)S[0].size(); ++i) visit[S[0][i]] = true;
	dfs(0, -1, 0);
	for (int i=0; i<N; ++i) printf("%d%s", out[i], (i==N-1||i%10==9)?"\n":" ");

	return 0;
}
