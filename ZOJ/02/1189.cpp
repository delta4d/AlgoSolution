#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXL = 81;
const int MAXN = 16;

struct node {
	int cnt[10];
	
	node () {
		for (int i=0; i<10; cnt[i++]=0);
	}
	void init() {
		for (int i=0; i<10; cnt[i++]=0);
	}
	bool equal(const node &a) {
		for (int i=0; i<10; ++i) if (cnt[i] != a.cnt[i]) return false;
		return true;
	}
	void deal(int x) {
		int i, j, k;
		do {
			k = x % 10;
			++cnt[k];
			x /= 10;
		} while (x != 0);
	}
	void next(node &r) {
		int i, j, k;
		r.init();
		for (i=0; i<10; ++i) {
			if (cnt[i] != 0) {
				r.deal(i);
				r.deal(cnt[i]);
			}
		}
	}
	void output() {
		for (int i=0; i<10; ++i) printf("%d ", cnt[i]);
		puts("");
	}
} f[MAXN];

char buff[MAXL];

int main() {
	int i, j, k;
	int tc;
	//freopen("f:\\in.txt", "r", stdin);
	//freopen("f:\\out.txt", "w", stdout);
	scanf("%d", &tc);
	while (tc--) {
		scanf("%s", buff);
		while (buff[0] != '-') {
			f[0].init();
			for (i=0; buff[i]; ++i) {
				f[0].deal(buff[i]-'0');
			}
			for (i=1; i<MAXN; ++i) {
				f[i-1].next(f[i]);
				if (f[i].equal(f[i-1])) {
					if (i == 1) printf("%s is self-inventorying\n", buff);
					else printf("%s is self-inventorying after %d steps\n", buff, i);
					goto done;
				} else {
					for (k=0; k<i; ++k) {
						if (f[i].equal(f[k])) {
							printf("%s enters an inventory loop of length %d\n", buff, i-k);
							goto done;
						}
					}
				}
			}
			printf("%s can not be classified after 15 iterations\n", buff);
			done:;
			for (k=0; k<=i; ++k) f[k].output();
			scanf("%s", buff);
		}
		if (tc) puts("");
	}
	return 0;
}