#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;

const LL f[] = {1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, 16796, 58786, 208012, 742900, 
		  2674440ll, 9694845ll, 35357670ll, 129644790ll, 477638700ll, 1767263190ll,
		  6564120420ll, 24466267020ll, 91482563640ll, 343059613650ll, 1289904147324ll};

LL tt[26][2];
char out[26];

LL build(LL off, LL n, LL k) {
	int i, j;
	if (n <= 0) return -1;
	if (n == 1) return off;
	for (i=0; i<n; ++i) {
		k -= f[i] * f[n-1-i];
		if (k <= 0) {
			k += f[i] * f[n-1-i];
			break;
		}
	}
	tt[i+off][0] = build(off, i, (k-1)/f[n-1-i]+1);
	tt[i+off][1] = build(i+off+1, n-1-i, (k-1)%f[n-1-i]+1);
	return i + off;
}

void travel(LL &d, LL root) {
	out[d] = root + 'a';
	if (tt[root][0] == -1 && tt[root][1] == -1) return;
	if (tt[root][0] != -1) travel(++d, tt[root][0]);
	if (tt[root][1] != -1) travel(++d, tt[root][1]);
}

int main() {
	LL i, j, k;
	LL m, n;
	LL root;
	//freopen("f:\\in.txt", "r", stdin);
	scanf("%lld %lld", &n, &k);
	while (true) {
		memset(tt, -1, sizeof(tt));
		root = build(0, n, k);
		m = 0;
		travel(m, root);
		out[m+1] = '\0';
		puts(out);
		for (i=0; i<n; ++i) {
			printf("%c", i+'a');
			if (tt[i][0] == -1) printf(" %c ", '*');
			else printf(" %c ", tt[i][0]+'a');
			if (tt[i][1] == -1) printf("%c\n", '*');
			else printf("%c\n", tt[i][1]+'a');
		}
		if (scanf("%lld %lld", &n, &k) == 2) puts("");
		else break;
	}
	return 0;
}
  