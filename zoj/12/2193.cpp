#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

bool visit[10];
bool f[10][10];
bool circle;
int g[4][4];

void dfs(int k) {
	int i, j;
	//printf("%d ", k);
	if (visit[k]) {
		circle = true;
		return;
	}
	visit[k] = true;
	for (i=1; i<10; ++i) {
		if (f[k][i]) {
			dfs(i);
			if (circle) return;
		}
	}
	visit[k] = false;
}

bool judge_suc() {
	int i, j, k;
	circle = false;
	memset(visit, false, sizeof(visit));
	for (i=1; i<10; ++i) {
		dfs(i);
		if (circle) return false;
	}
	return true;
}

void gao() {
	int i, j, k;
	int x, y;
	memset(f, false, sizeof(f));
	for (i=1; i<10; ++i) {
		x = (i - 1) / 3, y = (i - 1) % 3;
		if (g[x][y] != i) f[i][g[x][y]] = true;
		if (g[x][y+1] != i) f[i][g[x][y+1]] = true;
		if (g[x+1][y] != i) f[i][g[x+1][y]] = true;
		if (g[x+1][y+1] != i) f[i][g[x+1][y+1]] = true;
	}
	puts(judge_suc()?"THESE WINDOWS ARE CLEAN":"THESE WINDOWS ARE BROKEN");
}

int main() {
	int i, j, k;
	char buff[32];
	//freopen("f:\\in.txt", "r", stdin);
	//freopen("f:\\out.txt", "w", stdout);
	scanf("%s", buff);
	while (strcmp(buff, "ENDOFINPUT") != 0) {
		//puts(buff);
		for (i=0; i<4; ++i) for (j=0; j<4; ++j) scanf("%d", g[i]+j);
		scanf("%*s");
		gao();
		scanf("%s", buff);
	}
	return 0;
}