#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 60;
const int MAXL  = 21;

int n;
int ratio[MAXN][MAXN];
char name[MAXN][MAXL];

inline int gcd(const int _x, const int _y) {
	int x;
	int y;
	int t;
	x = max(_x, _y);
	y = min(_x, _y);
	while (y != 0) {
		t = x % y;
		x = y;
		y = t;
	}
	return x;
}

inline void sim(int &x, int &y) {
	int t(gcd(x, y));
	x /= t, y /= t;
}

inline int find_num(char s[]) {
	for (int i=0; i<n; ++i) if (strcmp(s, name[i]) == 0) return i;
	strcpy(name[n], s);
	return n++;
}

inline void gao() {
	int i, j, k;
	for (k=0; k<n; ++k) {
		for (i=0; i<n; ++i) {
			for (j=0; j<n; ++j) {
				if (ratio[i][j] != 0) continue;
				if (ratio[i][k] == 0 || ratio[k][i] == 0) continue;
				if (ratio[j][k] == 0 || ratio[k][j] == 0) continue;
				ratio[i][j] = ratio[i][k] * ratio[k][j];
				ratio[j][i] = ratio[j][k] * ratio[k][i];
				sim(ratio[i][j], ratio[j][i]);
			}
		}
	}
}

int main() {
	int i, j, k;
	int m;
	int x, y;
	int pa, pb;
	char a[MAXL], b[MAXL];
	char op[2];
	//freopen("f:\\in.txt", "r", stdin);
	for (i=0; i<MAXN; ++i) ratio[i][i] = 1;
	scanf("%s", op);
	while (true) {
		if (op[0] == '.') break;
		//n = 0;
		//memset(ratio, 0, sizeof(ratio));
		while (true) {
			scanf("%d %s %*s %d %s", &x, a, &y, b);
			pa = find_num(a);
			pb = find_num(b);
			sim(x, y);
			ratio[pa][pb] = x, ratio[pb][pa] = y;
			scanf("%s", op);
			if (op[0] != '!') break;
		}
		gao();
		while (true) {
			scanf("%s %*s %s", a, b);
			pa = find_num(a);
			pb = find_num(b);
			if (ratio[pa][pb]&&ratio[pb][pa]) printf("%d %s = %d %s\n", ratio[pa][pb], a, ratio[pb][pa], b);
			else printf("? %s = ? %s\n", a, b);
			scanf("%s", op);
			if (op[0] != '?') break;
		}
	}
	return 0;
}