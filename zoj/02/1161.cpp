#include <queue>
#include <cstdio>
#include <cstring>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 25;

struct node {
	int x;
	node(int x=0):x(x) {}
};

priority_queue<node> q;
int h;
int t[MAXN], f[MAXN], d[MAXN], c[MAXN];
int out[MAXN], tout[MAXN];

bool operator<(const node &a, const node &b) {
	if (c[a.x] != c[b.x]) return c[a.x] < c[b.x];
	return a.x > b.x;
}

void gao(const int n) {
	int i, j, k;
	int r, s, tt;
	node p;
	int tot;
	memset(out, 0, sizeof(out));
	r = -INF;
	for (k=1; k<=n; ++k) {
		while (!q.empty()) q.pop();
		tt = h;
		for (i=0; i<k; ++i) {
			c[i] = f[i];
			q.push(i);
			tt -= t[i];
		}
		tt += t[k-1];
		s = 0;
		memset(tout, 0, sizeof(tout));
		for (i=0; i<tt&&!q.empty(); ++i) {
			p = q.top();
			q.pop();
			if (c[p.x] <= 0) continue;
			++tout[p.x];
			s += c[p.x];
			c[p.x] -= d[p.x];
			q.push(p);
		}
		tot = 0;
		for (i=0; i<n; ++i) tot += tout[i];
		tout[0] += tt - tot;
		if (s > r) {
			r = s;
			for (i=0; i<n; ++i) out[i] = tout[i];
		} else if (s == r) {
			for (i=0; i<n; ++i) {
				if (out[i] < tout[i]) {
					break;
				} else if (out[i] > tout[i]) {
					i = n;
					break;
				}
			}
			if (i < n) for (i=0; i<n; ++i) out[i] = tout[i];
		}
	}
	printf("%d", out[0]*5);
	for (i=1; i<n; ++i) printf(", %d", out[i]*5);
	puts("");
	printf("Number of fish expected: %d\n", r);
}

int main() {
	int tc, n;
	int i, j, k;
	int r, s;
	//freopen("f:\\in.txt", "r", stdin);
	//freopen("f:\\out.txt", "w", stdout);
	scanf("%d", &tc);
	for (k=0; k<tc; ++k) {
		scanf("%d", &n);
		while (true) {
			scanf("%d", &h);
			h *= 12;
			for (i=0; i<n; ++i) scanf("%d", f+i);
			for (i=0; i<n; ++i) scanf("%d", d+i);
			for (i=0; i<n-1; ++i) scanf("%d", t+i);
			gao(n);
			scanf("%d", &n);
			if (n == 0) break;
			puts("");
		}
		if (k != tc - 1) puts("");
	}
	return 0;
}