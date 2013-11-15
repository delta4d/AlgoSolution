#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 201;
const int MAXC = 26;
const int MAXL = 80;

bool f[MAXC][MAXN][MAXN];

inline void floyd(const int s, const int n) {
	int i, j, k;
	for (k=1; k<=n; ++k) {
		for (i=1; i<=n; ++i) {
			for (j=1; j<=n; ++j) {
				if (f[s][i][k] && f[s][k][j]) f[s][i][j] = true;
			}
		}
	}
}

void gao(const int n) {
	int i, j, k;
	for (i=0; i<MAXC; ++i) {
		floyd(i, n);
	}
}

int main() {
	int i, j, k;
	int n, m;
	int s, t;
	char buff[MAXL];
	//freopen("f:\\in.txt", "r", stdin);
	scanf("%d", &n);
	while (n != 0) {
		for (i=0; i<MAXC; ++i) for (j=0; j<=n; ++j) for (k=0; k<=n; f[i][j][k++]=false);
		scanf("%d %d", &s, &t);
		while (s != 0 || t != 0) {
			scanf("%s", buff);
			for (i=0; buff[i]; f[buff[i++]-'a'][s][t]=true);
			scanf("%d %d", &s, &t);
		}
		gao(n);
		scanf("%d %d", &s, &t);
		while (s != 0 || t != 0) {
			k = 0;
			for (i=0; i<MAXC; ++i) if (f[i][s][t]) k = 1, printf("%c", i+'a');
			if (!k) puts("-");
			else puts("");
			scanf("%d %d", &s, &t);
		}
		puts("");
		scanf("%d", &n);
	}
	return 0;
}