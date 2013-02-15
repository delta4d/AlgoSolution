#include <cstdio>
#include <cstring>
using namespace std;

const int INF = 0x3f3f3f3f;
bool visit[5];
bool r[5][5];
int n;
int rank;
char out[6], res[6];
char s[100][6];

inline void tran(const int k) {
	int i, j;
	memset(r, false, sizeof(r));
	for (i=0; i<5; ++i) {
		for (j=i+1; j<5; ++j) {
			r[s[k][i]-'A'][s[k][j]-'A'] = true;
		}
	}
}

inline void judge() {
	int i, j, k;
	int len(0);
	int x, y;
	for (k=0; k<n; ++k) {
		tran(k);
		for (i=0; i<5; ++i) {
			for (j=i+1; j<5; ++j) {
				x = out[i] - 'A', y = out[j] - 'A';
				if (!r[x][y]) {
					++len;
				}
			}
		}
	}
	if (len < rank) {
		rank = len;
		strcpy(res, out);
	}
}

void dfs(int d) {
	int i, j, k;
	if (d == 5) {
		judge();
		return;
	}
	for (i=0; i<5; ++i) {
		if (!visit[i]) {
			visit[i] = true;
			out[d] = i + 'A';
			dfs(d+1);
			visit[i] = false;
		}
	}
}

void gao() {
	int i, j, k;
	memset(visit, false, sizeof(visit));
	rank = INF;
	dfs(0);
	printf("%s is the median ranking with value %d.\n", res, rank);
}

int main() {
	int i, j, k;
	//freopen("f:\\in.txt", "r", stdin);
	res[5] = out[5] = '\0';
	scanf("%d", &n);
	while (n != 0) {
		for (i=0; i<n; ++i) scanf("%s", s[i]);
		gao();
		scanf("%d", &n);
	}
	return 0;
}