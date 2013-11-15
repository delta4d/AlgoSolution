#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXL = 2;
const int MAXN = 26;

struct point {
	char name[MAXL];
	int x;
	int y;
	
	bool input() {
		return scanf("%s %d %d", name, &x, &y) == 3;
	}
} f[MAXN];

struct rec {
	char s[5];
	rec() {
		s[5] = '\0';
	}
	void output() {
		printf(" %s", s);
	}
	void set(int a, int b, int c, int d) {
		s[0] = f[a].name[0];
		s[1] = f[b].name[0];
		s[2] = f[c].name[0];
		s[3] = f[d].name[0];
	}
} r[(MAXN*(MAXN-1))>>1];

int n;

bool cmp(const rec &a, const rec &b) {
	return strcmp(a.s, b.s) < 0;
}

void deal(int a1, int a2, int &p) {
	int i, j, k;
	if (f[a1].x > f[a2].x) swap(a1, a2);
	if (f[a1].y <= f[a2].y) {
		for (i=0; i<n; ++i) {
			for (j=i+1; j<n; ++j) {
				if (i == a1 || i == a2) continue;
				if (j == a1 || j == a2) continue;
				if (f[i].x == f[a1].x && f[i].y == f[a2].y && f[j].x == f[a2].x && f[j].y == f[a1].y) {
					r[p++].set(i, a2, j, a1);
					return;
				}
				if (f[j].x == f[a1].x && f[j].y == f[a2].y && f[i].x == f[a2].x && f[i].y == f[a1].y) {
					r[p++].set(j, a2, i, a1);
					return;
				}
			}
		}
	}
}

int main() {
	int i, j, k;
	int cn(0);
	int p;
	//freopen("f:\\in.txt", "r", stdin);
	scanf("%d", &n);
	while (n != 0) {
		for (i=0; i<n; ++i) f[i].input();
		p = 0;
		for (i=0; i<n; ++i) {
			for (j=i+1; j<n; ++j) {
				deal(i, j, p);
			}
		}
		//deal(1, 4, p);
		sort(r, r+p, cmp);
		if (p == 0) {
			printf("Point set %d: No rectangles\n", ++cn);
		} else {
			printf("Point set %d:\n", ++cn);
			for (i=0; i<p; ++i) {
				r[i].output();
				if ((i + 1) % 10 == 0) puts("");
			}
			if (p % 10 != 0) puts("");
		}
		scanf("%d", &n);
	}
	return 0;
}