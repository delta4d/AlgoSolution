#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

inline bool judge(int g[][5]) {
	int i, j, k;
	for (i=0; i<5; ++i) {
		for (j=0; j<4; ++j) {
			if (g[i][j] != g[i][j+1]) break;
		}
		if (j == 4) return true;
	}
	for (i=0; i<5; ++i) {
		for (j=0; j<4; ++j) {
			if (g[j][i] != g[j+1][i]) break;
		}
		if (j == 4) return true;
	}
	for (i=0; i<4; ++i) {
		if (g[i][i] != g[i+1][i+1]) break;
	}
	if (i == 4) return true;
	for (i=0; i<4; ++i) {
		if (g[i][4-i] != g[i+1][3-i]) break;
	}
	if (i == 4) return true;
	return false;
}

inline void check(int g[][5], const int n) {
	for (int i=0; i<5; ++i) {
		for (int j=0; j<5; ++j) {
			if (g[i][j] == n) {
				g[i][j] = -1;
				return;
			}
		}
	}
}

int main() {
	int i, j, k;
	int m, n;
	int tc;
	int g[5][5];
	g[2][2] = -1;
	//freopen("f:\\in.txt", "r", stdin);
	scanf("%d", &tc);
	while (tc--) {
		for (i=0; i<5; ++i) {
			for (j=0; j<5; ++j) {
				if (i == 2 && j == 2) continue;
				scanf("%d", g[i]+j);
			}
		}
		for (i=0; i<75; ++i) {
			scanf("%d", &n);
			check(g, n);
			if (judge(g)) {
				printf("BINGO after %d numbers announced\n", i+1);
				break;
			}
		}
		for (++i; i<75; ++i) scanf("%*d");
	}
	return 0;
}