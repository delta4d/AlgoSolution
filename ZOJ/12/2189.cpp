#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int cost[] = {25, 10, 5, 1};
const int MAXN = 100;

int tot, sum;
int num[4];

struct node {
	int cnt[4];
	bool visit;
	
	node() {
		visit = false;
		memset(cnt, 0, sizeof(cnt));
	}
	void clear() {
		visit = false;
		memset(cnt, 0, sizeof(cnt));
	}
	void mark() {
		visit = true;
	}
	void inc(const int i) {
		++cnt[i];
	}
	void dec(const int i) {
		--cnt[i];
	}
	int all() {
		int ret(0);
		for (int i=0; i<4; ++i) ret += cnt[i];
		return ret;
	}
	void print() {
		for (int i=0; i<4; ++i) printf("%d%s", cnt[i], i==3?"\n":" ");
	}
} f[4101];

int main() {
	int i, j, k;
	int m, n;
	double t;
	
	//freopen("f:\\in.txt", "r", stdin);
	while (scanf("%lf", &t) == 1) {
		tot = t * 100 + 0.5;
		memset(num, 0, sizeof(num));
		sum = 0;
		for (i=0; i<4; ++i) {
			scanf("%d", num+i);
			sum += num[i] * cost[i];
		}
		if (sum < tot) {
			puts("NO EXACT CHANGE");
		} else {
			for (i=0; i<=sum; ++i) f[i].clear();
			f[0].mark();
			for (i=0; i<4; ++i) {
				for (j=0; j<num[i]; ++j) {
					for (k=tot; k>=0; --k) {
						if (f[k].visit && k  + cost[i] <= tot) {
							if (!f[k+cost[i]].visit || f[k+cost[i]].all() > f[k].all() + 1) {
								for (int t=0; t<4; ++t) f[k+cost[i]].cnt[t] = f[k].cnt[t];
								f[k+cost[i]].inc(i);
								f[k+cost[i]].mark();
							}
						}
					}
				}
			}
			if (f[tot].visit) f[tot].print();
			else puts("NO EXACT CHANGE");
		}
	}
	return 0;
}