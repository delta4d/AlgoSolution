#include <cstdio>
#include <cstring>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 10001;
int c[20];
bool reach[MAXN];

inline int gcd(int x, int y) {
	int t;
	if (x < y) x ^= y ^= x ^= y;
	while (y != 0) {
		t = x % y;
		x = y;
		y = t;
	}
	return x;
}

void bfs(const int n) {
	int i, j, k;
	reach[1] = true;
	for (i=0; i<n; ++i) {
		if (c[i] == 1) continue;
		for (j=1; j<MAXN; ++j) {
			if (reach[j]) {
				k = j * c[i];
				while (k < MAXN) {
					reach[k] = true;
					k *= c[i];
				}
			}
		}
	}
}

int main() {
	int tc, n, m;
	int i, j, k, t;
	int a, b, x, y;
	int minc;
	bool find;
	freopen("f:\\in.txt", "r", stdin);
	freopen("f:\\out.txt", "w", stdout);
	scanf("%d", &tc);
	for (t=1; t<=tc; ++t) {
		scanf("%d", &n);
		minc = INF;
		for (i=0; i<n; ++i) {
			scanf("%d", c+i);
			if (minc > c[i]) minc = c[i];
		}
		for (i=0; i<n; ++i) c[i] /= minc;
		memset(reach, false, sizeof(reach));
		bfs(n);
		scanf("%d", &m);
		printf("Scenario #%d:\n", t);
		for (i=0; i<m; ++i) {
			scanf("%d %d", &a, &b);
			k = gcd(a, b);
			x = a / k, y = b / k;
			if (x < y) x ^= y ^= x ^= y;
			find = false;
			for (j=x; j<MAXN; j+=x) {
				if (reach[j] && reach[j/x*y]) {
					printf("Gear ratio %d:%d can be realized.\n", a, b);
					find = true;
					break;
				}
			}
			if (!find) printf("Gear ratio %d:%d cannot be realized.\n", a, b);	
		}
		puts("");
	}
	return 0;
}