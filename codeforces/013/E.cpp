#include <cstdio>
#include <algorithm>
using namespace std;

const int BS = 512;
const int MAXN = 100000 + 86;

int p[MAXN], cnt[MAXN], next[MAXN], pre[MAXN];
int n, m;

void gao(int k) {
	int nu = k / BS;	
	if (p[k] >= n) cnt[k] = 1, next[k] = -1, pre[k] = k;
	else if (p[k] / BS > nu) cnt[k] = 1, next[k] = p[k], pre[k] = k;
	else cnt[k] = cnt[p[k]] + 1, next[k] = next[p[k]], pre[k] = pre[p[k]];
}

void query(int k) {
	int cc = 0, i = -1;	
	for (i=k; next[i]>0; cc+=cnt[i],i=next[i]);
	printf("%d %d\n", pre[i]+1, cc+cnt[i]);
}

int main() {
	scanf("%d%d", &n, &m);

	for (int i=0; i<n; ++i) scanf("%d", p+i), p[i] += i;
	for (int i=n-1; i>=0; --i) gao(i);
	while (m--) {
		int op, a, b;
		scanf("%d%d", &op, &a); --a;
		if (op) {
			query(a);
		} else {
			scanf("%d", &b);	
			p[a] = a + b;
			int l = a / BS * BS, r = min(l + BS - 1, n - 1);
			for (int i=r; i>=l; --i) gao(i);
		}
	}

	return 0;
}

// 3667838	 May 4, 2013 2:11:35 PM	delta_4d	 E - Holes	 GNU C++	Accepted	546 ms	1544 KB
