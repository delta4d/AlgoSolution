/*
ID: delta 4d
PROG: hamming
LANG: C++
 */

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 1 << 8;

vector <int> T[MAXN], S[MAXN];
int out[MAXN], tmp[MAXN];
bool find_one, visit[MAXN];
int N, B, D;

inline int h(const int a, const int b) {
	int cc = 0;
	for (int i=0; i<32; ++i) cc += (a & (1 << i)) != (b & (1 << i));
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
	for (int i=0; i<T[r].size(); ++i) {
		int c = T[r][i];
		if (c != p && !visit[c]) {
			visit[c] = true;
			for (int j=0; j<S[c].size(); ++j) visit[S[c][j]] = true;
			dfs(c, r, d+1);
			if (find_one) return;
			visit[c] = false;
			for (int j=0; j<S[c].size(); ++j) visit[S[c][j]] = false;
		}
	}
}

int main() {
#ifndef __DELTA__
	freopen("hamming.in", "r", stdin);
	freopen("hamming.out", "w", stdout);
#endif

	scanf("%d%d%d", &N, &B, &D);
	for (int i=0; i<(1<<B); ++i) for (int j=i+1; j<(1<<B); ++j) {
		if (h(i, j) >= D) T[i].push_back(j);
		else S[i].push_back(j), S[j].push_back(i);
	}
	
	visit[0] = true;
	for (int i=0; i<S[0].size(); ++i) visit[S[0][i]] = true;
	dfs(0, -1, 0);
	for (int i=0; i<N; ++i) printf("%d%s", out[i], (i==N-1||i%10==9)?"\n":" ");

	return 0;
}
