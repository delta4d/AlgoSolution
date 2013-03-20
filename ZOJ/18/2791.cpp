#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

inline int to_ten(char *s) {
	int n(0);
	int pre(1);
	int i, j, k;
	for (i=0; s[i]; ++i) {
		if (s[i] == 'm') {
			n += pre * 1000;
			pre = 1;
		} else if (s[i] == 'c') {
			n += pre * 100;
			pre = 1;
		} else if (s[i] == 'x') {
			n += pre * 10;
			pre = 1;
		} else if (s[i] == 'i') {
			n += pre;
			pre = 1;
		} else {
			pre = s[i] - '0';
		}
	}
	return n;
}

inline void to_mcxi(int n) {
	int t;
	t = n / 1000;
	if (t > 1) printf("%d", t);
	if (t > 0) printf("m");
	n -= t * 1000;
	t = n / 100;
	if (t > 1) printf("%d", t);
	if (t > 0) printf("c");
	n -= t * 100;
	t = n / 10;
	if (t > 1) printf("%d", t);
	if (t > 0) printf("x");
	n -= t * 10;
	t = n / 1;
	if (t > 1) printf("%d", t);
	if (t > 0) printf("i");
	puts("");
}

inline void compute(char *s1, char *s2) {
	int i, j, k;
	int n1, n2;
	n1 = to_ten(s1), n2 = to_ten(s2);
	to_mcxi(n1+n2);
}

int main() {
	int i, j, k;
	int m, n;
	int tc;
	char s1[32], s2[32];
	//freopen("f:\\in.txt", "r", stdin);
	scanf("%d", &tc);
	while (tc--) {
		scanf("%s %s", s1, s2);
		compute(s1, s2);
	}
	return 0;
}