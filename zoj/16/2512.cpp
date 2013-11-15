#include <cstdio>
#include <cstring>
using namespace std;

char s[1001];
int len;

inline bool sym(int x, int y) {
	int i, j, k(len>>1);
	int l(x), r(y);
	for (i=0; i<=k; ++i) {
		if (s[l] != s[r]) return false;
		--l, ++r;
		if (l == -1) l = len - 1;
		if (r == len) r = 0;
	}
	return true;
}

int main() {
	int i, j, k;
	//freopen("f:\\in.txt", "r", stdin);
	while (scanf("%s", s) != EOF) {
		len = strlen(s);
		for (i=0; i<len; ++i) {
			if (sym(i, i)) {
				printf("Symmetric\n");
				printf("%d\n", i+1);
				break;
			}
			if (sym(i, i+1)) {
				printf("Symmetric\n");
				printf("%d-%d\n", i+1, i+2);
				break;
			}
		}
		if (i == len) puts("Not symmetric");
	}
	return 0;
}