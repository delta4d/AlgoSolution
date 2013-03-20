#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 16;
const int MAXL = 128;

struct node {
	char s[MAXL];
	
	void init() {
		s[0] = '\0';
	}
	bool input() {
		scanf("%s", s);
		return s[0] != '-';
	}
	bool equal(const node &a) {
		return strcmp(s, a.s) == 0;
	}
	void next(node &a) {
		int cnt[10];
		int i, j, k;
		int m, n;
		int p;
		for (i=0; i<10; cnt[i++]=0);
		for (i=0; s[i]; ++i) {
			++cnt[s[i]-'0'];
		}
		p = 0;
		for (i=0; i<10; ++i) {
			if (cnt[i] == 0) continue;
		 	n = cnt[i];
		 	do {
			 	k = n % 10;
			 	a.s[p++] = k + '0';
			 	n /= 10;
		 	} while (n != 0);
		 	n = i;
		 	do {
			 	k = n % 10;
			 	a.s[p++] = k + '0';
			 	n /= 10;
		 	} while (n != 0);
		}
		a.s[p] = '\0';
	}
} f[MAXN];

int main() {
	int i, j, k;
	int tc;
	
	//freopen("f:\\in.txt", "r", stdin);
	scanf("%d", &tc);
	while (tc--) {
		while (f[0].input()) {
			for (i=1; i<MAXN; ++i) {
				f[i-1].next(f[i]);
				if (f[i].equal(f[i-1])) {
					if (i == 1) printf("%s is self-inventorying\n", f[0].s);
					else printf("%s is self-inventorying after %d steps\n", f[0].s, i-1);
					goto done;
				} else {
					for (k=0; k<i; ++k) {
						if (f[i].equal(f[k])) {
							printf("%s enters an inventory loop of length %d\n", f[0].s, i-k);
							goto done;
						}
					}
				}
			}
			printf("%s can not be classified after 15 iterations\n", f[0].s);
			done:;
		}
		//for (i=0; i<4; ++i) printf("%s\n", f[i].s);
		if (tc) puts("");
	}
	return 0;
}