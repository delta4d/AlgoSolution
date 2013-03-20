#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 27;
int graph[MAXN][MAXN];
bool visit[MAXN];
int d[MAXN];
int n;
double v[MAXN];
char buff[80];

void gao() {
	int i, j, k;
	int index, min;
	double max, temp;
	int x;
	for (i=0; i<MAXN; ++i) d[i] = INF;
	d[0] = 0;
	memset(visit, false, sizeof(visit));
	for (k=0; k<MAXN; ++k) {
		min = INF;
		for (i=0; i<MAXN; ++i) {
			if (!visit[i] && d[i] < min) {
				min = d[i];
				index = i;
			}
		}
		visit[index] = true;
		for (i=0; i<MAXN; ++i) {
			if (!visit[i] && d[index] + graph[index][i] < d[i]) {
				d[i] = d[index] + graph[index][i];
			}
		}
	}
	max = -(double)INF;
	for (i=1; i<MAXN; ++i) {
		if (d[i] == INF) continue;
		temp = v[i] * pow(0.95, (double)d[i]);
		if (max < temp) {
			max = temp;
			x = i;
		}
	}
	printf("Import from %c\n", x+'A'-1);
}

int main() {
	int i, j, k;
	int len;
	char x, y;
	double w;
	//freopen("f:\\in.txt", "r", stdin);
	while (scanf("%d", &n) != EOF) {
		for (i=0; i<MAXN; ++i) for (j=0; j<MAXN; ++j) graph[i][j] = INF;
		for (i=0; i<n; ++i) {
			getchar();
			scanf("%c %lf", &x, &w);
			getchar();
			scanf("%s", buff);
			len = strlen(buff);
			k = x - 'A' + 1;
			v[k] = w;
			for (j=0; j<len; ++j) {
				if (buff[j] == '*') graph[k][0] = graph[0][k] = 1;
				else graph[k][buff[j]+1-'A'] = graph[buff[j]+1-'A'][k] = 1;
			}
		}
		gao();
	}
	return 0;
}