#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;

int f[10][100][101];
int t[10][99];
int p[10][10];
int M, N, Z;

int gao(int x, int y, int z) {
	int i, j, k;
	int res;
	if (f[x][y][z] != -1) return f[x][y][z];
	res = INF;
	if (y + 1 < N) res = min(res, gao(x, y+1, z)+t[x][y]);
	for (k=-x; k<=M-x-1; ++k) {
		if (k == 0) continue;
		if (z >= p[x][x+k]) {
			res = min(res, gao(x+k, y, z-p[x][x+k]));
		}
	}
	return f[x][y][z] = res;
}

int main() {
	int i, j, k;
	int tc;
	int x, y, z;
	//freopen("f:\\in.txt", "r", stdin);
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d %d %d", &N, &M, &Z);
		for (i=0; i<M; ++i) for (j=0; j<N-1; ++j) scanf("%d", t[i]+j);
		for (i=0; i<M; ++i) for (j=0; j<M; ++j) scanf("%d", p[i]+j);
		memset(f, -1, sizeof(f));
		for (x=0; x<M; ++x) for (z=0; z<=Z; ++z) f[x][N-1][z] = 0;
		printf("%d\n", gao(0, 0, Z));
	}
	return 0;
}