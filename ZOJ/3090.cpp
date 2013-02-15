#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXL = 21;
const int MAXN = 1000;
const int INF = 0x7fffffff;

struct component {
	char type[MAXL];
	int price;
	int quality;
	void input() {
		scanf("%s %*s %d %d", type, &price, &quality);
	}
} f[MAXN];

inline bool cmp(const component &a, const component &b) {
	return strcmp(a.type, b.type) < 0;
}

inline bool gao(const int s, const int n, int b) {
	int i(0), j, k;
	int cost(0), min_cost;
	while (i < n) {
		j = i, min_cost = INF;
		while (strcmp(f[j].type, f[i].type) == 0) {
			if (f[j].quality >= s) min_cost = min(min_cost, f[j].price);
			++j;
			if (j == n) break;
		}
		//if (min_cost == INF) return false;
		b -= min_cost;
		if (b < 0) return false;
		i = j;
	}
	return true;
}

inline int gao(const int l, const int r, const int n, const int b) {
	int i, j, k;
	int left(l-1), right(r+1), mid;
	while (left + 1 < right) {
		mid = (left + right) >> 1;
		if (gao(mid, n, b)) left = mid;
		else right = mid;
	}
	return left;
}

int main() {
	int i, j, k;
	int tc;
	int n, b;
	int l, r;
	//freopen("f:\\in.txt", "r", stdin);
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d %d", &n, &b);
		l = INF, r = -INF;
		for (i=0; i<n; ++i) {
			f[i].input();
			l = min(l, f[i].quality);
			r = max(r, f[i].quality);
		}
		sort(f, f+n, cmp);
		printf("%d\n", gao(l, r, n, b));
	}
	return 0;
}