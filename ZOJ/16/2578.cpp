#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const double INF = 999999999999.9;
const int MAXL = 251;
const int MAXN = 32000;

struct node {
	double pos;
	char name[MAXL];
	int dir;
} f[MAXN];

inline bool cmp(const node &a, const node &b) {
	return a.pos < b.pos;
}

inline int find_name(char name[], const int n) {
	int i, j, k;
	for (i=0; i<n; ++i) if (strcmp(name, f[i].name) == 0) return i;
}

inline int find_rev(const int k, const int n) {
	int i, j;
	int d(f[k].dir);
	int cnt(0);
	for (i=k+d; i>=0&&i<n; i+=d) cnt += (f[i].dir * d == -1);
	return cnt;
}

inline int find_last(const int k, const int off) {
	return k + f[k].dir * off;
}

int main() {
	int i, j, k;
	int m, n;
	double l, v;
	double len, t;
	char dir[2];
	char name[MAXL];
	//freopen("f:\\in.txt", "r", stdin);
	while (scanf("%d", &n), n) {
		scanf("%lf %lf", &l, &v);
		len = -INF;
		for (i=0; i<n; ++i) {
			scanf("%s %lf %s", dir, &f[i].pos, f[i].name);
			f[i].dir = dir[0] == 'p' || dir[0] == 'P' ? 1 : -1;
			if (len < (t = fabs(f[i].pos - (f[i].dir==1?l:0)))) {
				len = t;
				strcpy(name, f[i].name);
			}
		}
		t = len / v;
		t *= 100.0;
		t = (int)t;
		t /= 100.0;
		sort(f, f+n, cmp);
		j = find_name(name, n);
		m = find_rev(j, n);
		k = find_last(j, m);
		printf("%13.2lf %s\n", t, f[k].name);
	}
	return 0;
}