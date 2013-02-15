#include <queue>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 512;
struct node {
	int index;
	int weight;
	node(int a=-1, int b=-1):index(a), weight(b) {}
};
struct answer {
	int src;
	int dst;
	double time;
};
typedef vector<node> VI;
typedef VI::iterator VII;
VI e[MAXN];
bool inqueue[MAXN];
int d[MAXN];
answer res[MAXN];

inline int cmp(const void *a, const void *b) {
	answer *c = (answer *)a;
	answer *d = (answer *)b;
	if (c->src != d->src) return c->src - d->src;
	return c->dst - d->dst;
}

void SPFA(const int n) {
	int i, j, k;
	int s, t, w;
	VII it;
	node tt;
	queue<int> q;
	memset(inqueue, false, sizeof(inqueue));
	fill(d+1, d+n+1, INF);
	d[1] = 0;
	inqueue[1] = true;
	q.push(1);
	while (!q.empty()) {
		s = q.front();
		q.pop();
		inqueue[s] = false;
		for (it=e[s].begin(); it!=e[s].end(); ++it) {
			t = (*it).index, w = (*it).weight;
			if (d[s] + w < d[t]) {
				d[t] = d[s] + w;
				if (!inqueue[t]) {
					q.push(t);
					inqueue[t] = true;
				}
			}
		}
	}
}

inline bool operator== (const answer &a, const answer &b) {
	if (a.src != b.src) return false;
	if (a.dst != b.dst) return false;
	if (a.time != b.time) return false;
	return true;
}

inline bool in(const answer &a, const int n) {
	int i;
	for (i=0; i<n; ++i) {
		if (res[i] == a) return false;
	}
	return true;
}

void gao(const int n, int &num) {
	int i, j, k;
	int src, dst, w;
	answer tt;
	VII it;
	num = 0;
	SPFA(n);
	for (i=1; i<=n; ++i) {
		for (it=e[i].begin(); it!=e[i].end(); ++it) {
			dst = (*it).index, w = (*it).weight;
			src = i;
			if (src > dst) src ^= dst ^= src ^= dst;
			if (max(d[src], d[dst]) - min(d[src], d[dst]) < w) {
				tt.src = src, tt.dst = dst, tt.time = (d[src] + d[dst] + w) / 2.0;
				if (num == 0) {
					res[0] = tt;
					++num;
				} else if (tt.time == res[num-1].time && in(tt, num)) {
					res[num] = tt;
					++num;
				} else if (tt.time > res[num-1].time) {
					res[0] = tt;
					num = 1;
				}
			}
		}
	}
	int r[MAXN];
	k = 1;
	r[0] = 1;
	for (i=2; i<=n; ++i) {
		if (d[i] == d[r[k-1]]) {
			r[k] = i;
			++k;
		} else if (d[i] > d[r[k-1]]) {
			r[0] = i;
			k = 1;
		}
	}
	if (num == 0 || res[0].time == d[r[0]]) {
		for (i=0; i<k; ++i) {
			res[num].src = r[i];
			res[num].dst = r[i];
			res[num].time = d[r[i]];
			++num;
		}
	}
	qsort(res, num, sizeof(res[0]), cmp);
}

int main() {
	int m, n, cn(0);
	int i, j, k;
	int s, t, w;
	//freopen("f:\\in.txt", "r", stdin);
	scanf("%d %d", &n, &m);
	while (n != 0 || m != 0) {
		for (i=1; i<=n; ++i) e[i].clear();
		for (i=0; i<m; ++i) {
			scanf("%d %d %d", &s, &t, &w);
			e[s].push_back(node(t, w));
			e[t].push_back(node(s, w));
		}
		gao(n, k);
		printf("System #%d\n", ++cn);
		for (i=0; i<k; ++i) {
			if (res[i].src == res[i].dst)
				printf("The last domino falls after %.1lf seconds, at key domino %d.\n", res[i].time, res[i].src);
			else
				printf("The last domino falls after %.1lf seconds, between key dominoes %d and %d.\n", res[i].time, res[i].src, res[i].dst);
		}
		puts("");
		scanf("%d %d", &n, &m);
	}
	return 0;	
}