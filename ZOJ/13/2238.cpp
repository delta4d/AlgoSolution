#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 1000010;
const int ten[7] = {1, 10, 100, 1000, 10000, 100000, 1000000};
bool visit[MAXN];
bool gaoding;
char res[7][MAXN];
int pre_x[MAXN];
int pre_d[MAXN];

void dfs(int x, int d, int n) {
	int i, j, k;
	int y;
	if (d == ten[n] + n - 1) {
		res[n][d] = '\0';
		gaoding = true;
		return;
	}
	y = x / ten[n-1];
	y = x - y * ten[n-1];
	for (i=0; i<10; ++i) {
		k = y * 10 + i;
		if (!visit[k]) {
			visit[k] = true;
			res[n][d] = i + '0';
			dfs(k, d+1, n);
			if (gaoding) return;
			visit[k] = false;
		}
	}
}

void gen() {
	int i, j, k;
	for (i=5; i<=5; ++i) {
		memset(visit, false, sizeof(visit));
		visit[0] = true, gaoding = false;
		for (j=0; j<i; ++j) res[i][j] = '0';
		dfs(0, i, i);
	}
}

int main() {
	int i, j, k;
	int n;
	freopen("f:\\in.txt", "r", stdin);
	gen();
	scanf("%d", &n);
	while (n != 0) {
		puts(res[n]);
		scanf("%d", &n);
	}
	return 0;
}