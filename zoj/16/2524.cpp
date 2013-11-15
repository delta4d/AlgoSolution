#include <set>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 20000;
const int MAXL = 21;
int tot;
struct node {
	char name[MAXL];
	int w, d, l;
	int pt, gd;
	node(int w=0, int d=0, int pt=0, int gd=0):w(w), d(d), l(l), pt(pt), gd(gd) {
		//memset(name, '\0', sizeof(name));
	}
	void init() {
		w = 0, d = 0, l = 0, pt = 0, gd = 0;
		//memset(name, '\0', sizeof(name));
	}
} res[MAXN];

bool cmp(const node &a, const node &b) {
	if (a.pt != b.pt) return a.pt > b.pt;
	if (a.gd != b.gd) return a.gd > b.gd;
	return strcmp(a.name, b.name) <= 0;
}

inline int find_name(char *name) {
	int i;
	for (i=0; i<tot; ++i) if (strcmp(res[i].name, name) == 0) return i;
	return i;
}

int main() {
	int m, n;
	int i, j, k;
	int home_score, away_score;
	char temp;
	char home[MAXL], away[MAXL];
	//freopen("f:\\in.txt", "r", stdin);
	scanf("%d", &n);
	while (true) {
		tot = 0;
		for (i=0; i<n; ++i) {
			scanf("%s %d %c %d %s", home, &home_score, &temp, &away_score, &away);
			k = find_name(home);
			if (k == tot) res[k].init(), strcpy(res[k].name, home), ++tot;
			res[k].w += home_score > away_score ? 1 : 0;
			res[k].d += home_score == away_score ? 1 : 0;
			res[k].l += home_score < away_score ? 1 : 0;
			res[k].pt += home_score > away_score ? 3 : 0;
			res[k].pt += home_score == away_score ? 1 : 0;
			res[k].gd += home_score - away_score;
			k = find_name(away);
			if (k == tot) res[k].init(), strcpy(res[k].name, away), ++tot;
			res[k].w += away_score > home_score ? 1 : 0;
			res[k].d += away_score == home_score ? 1 : 0;
			res[k].l += away_score < home_score ? 1 : 0;
			res[k].pt += away_score > home_score ? 3 : 0;
			res[k].pt += away_score == home_score ? 1 : 0;
			res[k].gd += away_score - home_score;
		}
		sort(res, res+tot, cmp);
		for (i=0; i<tot; ++i) {
			printf("%d %s %d %d %d %d %d\n", 
			i+1, res[i].name, res[i].w, res[i].d, res[i].l, res[i].pt, res[i].gd);
		}
		if (scanf("%d", &n) == EOF) break;
		puts("");
	}
	return 0;
}