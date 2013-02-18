/*
ID: delta 4d
PROG: gift1
LANG: C++
*/

#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 10;
const int MAXL = 80;
char name[MAXN][MAXL];
char giver[MAXL], receiver[MAXL];
int init[MAXN];
int last[MAXN];

inline int find(const int n, char *s) {
	for (int i=0; i<n; ++i) if (strcmp(s, name[i]) == 0) return i;
}

int main() {
	int n, m;
	int i, j, k;
	int gid, rid;
	int avg;
	//freopen("f:\\in.txt", "r", stdin); 
	freopen("gift1.in", "r", stdin);
	freopen("gift1.out", "w", stdout);
	while (scanf("%d", &n) != EOF) {
		for (i=0; i<n; ++i) scanf("%s", name[i]);
		memset(init, 0, sizeof(init));
		memset(last, 0, sizeof(last));
		for (i=0; i<n; ++i) {
			scanf("%s", giver);
			gid = find(n, giver);
			//printf("gid: %d\n", gid);
			scanf("%d %d", init+gid, &m);
			if (m == 0) continue;
			avg = init[gid] / m;
			last[gid] += init[gid] - m * avg;
			//init[gid] -= avg * m;
			for (k=0; k<m; ++k) {
				scanf("%s", receiver);
				rid = find(n, receiver);
				last[rid] += avg;
			}
		}
		for (i=0; i<n; ++i) printf("%s %d\n", name[i], last[i]-init[i]);
	}
	return 0;
}