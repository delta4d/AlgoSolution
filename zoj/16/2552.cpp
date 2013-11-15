#include <cstdio>
using namespace std;

struct player {
	int w;
	int l;
	
	player(int _w=0, int _l=0):w(_w), l(_l) {}
	void init() {w = l = 0;}
	void output() {
		if (w == 0 && l == 0) puts("-");
		else printf("%.3lf\n", double(w)/double(w+l));
	}
};

int main() {
	int i, j, k;
	int n;
	int p1, p2;
	char m1[10], m2[10];
	player f[101];
	//freopen("f:\\in.txt", "r", stdin);
	scanf("%d", &n);
	while (n != 0) {
		scanf("%d", &k);
		for (i=1; i<=n; ++i) f[i].init();
		k *= (n * (n - 1)) >> 1;
		for (i=0; i<k; ++i) {
			scanf("%d %s %d %s", &p1, m1, &p2, m2);
			if (m1[0] == 'p' && m2[0] == 'r') ++f[p1].w, ++f[p2].l;
			else if (m1[0] == 'r' && m2[0] == 's') ++f[p1].w, ++f[p2].l;
			else if (m1[0] == 's' && m2[0] == 'p') ++f[p1].w, ++f[p2].l;
			else if (m2[0] == 'p' && m1[0] == 'r') ++f[p2].w, ++f[p1].l;
			else if (m2[0] == 'r' && m1[0] == 's') ++f[p2].w, ++f[p1].l;
			else if (m2[0] == 's' && m1[0] == 'p') ++f[p2].w, ++f[p1].l;
		}
		for (i=1; i<=n; ++i) f[i].output();
		scanf("%d", &n);
		if (n != 0) puts("");
	}
	return 0;
}