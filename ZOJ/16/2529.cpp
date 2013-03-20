#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXL = 128;
const int prime[25] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43,
                       47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
char buff[10];
char s1[MAXL], s2[MAXL];
int a1[MAXL>>2], a2[MAXL>>2];
int x1[MAXL>>2], x2[MAXL>>2];
int r[MAXL>>2];

inline int to_int(const int n) {
	int res(0);
	for (int i=0; i<n; ++i) {
		res = res * 10 + buff[i] - '0';
	}
	return res;
}

inline int tran(char *s, int *a) {
	int len(strlen(s));
	int i, j, k(0);
	int n(0);
	for (i=0; i<=len; ++i) {
		if (s[i] == ',' || s[i] == '\0') {
			a[n] = to_int(k);
			k = 0, ++n;
		} else {
			buff[k] = s[i];
			++k;
		}
	}
	return n;
}

inline void reverse(int *a, int *x, const int len) {
	for (int i=0; i<len; ++i) x[i] = a[len-i-1];
}

inline void gao(const int len1, const int len2) {
	int i, j, k, c(0);
	int len(max(len1, len2));
	memset(x1, 0, sizeof(x1)); memset(x2, 0, sizeof(x2));
	reverse(a1, x1, len1);
	reverse(a2, x2, len2);
	memset(r, 0, sizeof(r));
	for (i=0; i<len; ++i) {
		r[i] = (x1[i] + x2[i] + c) % prime[i];
		c = (x1[i] + x2[i] + c) / prime[i];
	}
	if (c != 0) {
		r[len] = c;
		++len;
	}
	printf("%d", r[len-1]);
	for (i=len-2; i>=0; --i) printf(",%d", r[i]);
	puts("");
}

int main() {
	int i, j, k;
	int len1, len2;
	//freopen("f:\\in.txt", "r", stdin);
	while (scanf("%s %s", s1, s2) != EOF) {
		len1 = tran(s1, a1);
		len2 = tran(s2, a2);
		gao(len1, len2);
	}
	return 0;
}