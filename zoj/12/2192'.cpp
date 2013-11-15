#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 20;
bool graph[MAXN][MAXN];
bool visit[MAXN];
int match[MAXN];
int p[26];
int w[5];
int n;
char buff[20];

bool dfs(int x) {
	
}

bool gao() {
	int i, j, k;
	int res(0);
	memset(match, -1, sizeof(match));
	for (i=0; i<n; ++i) {
		memset(visit, false, sizeof(visit));
		if (dfs(i)) ++res;	
	}
	return res == n;
}

int main() {
	int i, j ,k ;
	int s, t;
	int x, y;
	freopen("f:\\in.txt", "r", stdin);
	p['S'-'A'] = 0, p['M'-'A'] = 1, p['L'-'A'] = 2, p['X'-'A'] = 3, p['T'-'A'] = 4;
	scanf("%s", buff);
	while (strcmp(buff, "ENDOFINPUT") != 0) {
		memset(graph, false, sizeof(graph));
		scanf("%d", &n);
		for (i=0; i<n; ++i) {
			scanf("%s", buff);
			s = p[buff[0]-'A'], t = p[buff[1]-'A'];
			for (j=s; j<=t; ++j) {
				graph[i][j] = true;
			}
		}
		printf("%s\n", gao()?res[0]:res[1]);
		scanf("%s", buff);
	}
	return 0;
}