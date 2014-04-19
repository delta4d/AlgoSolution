#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;

int c[26];
char s[21];
ll f[21], n;

void init() {
	f[0] = 1;
	for (int i=1; i<=20; ++i) f[i] = i * f[i-1];
}

ll countme() {
	ll ret = 0, dd = 1;
	for (int i=0; i<26; ++i) dd *= f[c[i]], ret += c[i];
	ret = f[ret] / dd;
	return ret;
}

int main() {
	init();
	int tc, cn = 0;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%s%lld", s, &n);
		memset(c, 0, sizeof(c));
		int L = strlen(s);
		for (int i=0; i<L; ++i) ++c[s[i]-'a'];
		printf("Case %d: ", ++cn);
		if (countme() < n) {
			puts("Impossible");
			continue;
		}
		while (L--) {
			ll tot = 0;
			for (int i=0; i<26; ++i) if (c[i]) {
				--c[i];
				ll cc = countme();
				if (tot + cc >= n && n > tot) {
					printf("%c", i+'a');
					break;
				}
				++c[i], tot += cc;
			}
			n -= tot;
		}
		puts("");
	}
	return 0;
}

// 295523	2013-12-04 21:44:47	 1060 - nth Permutation	 C++	 0.000	 1088	Accepted
