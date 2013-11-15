#include <cstdio>
#include <cstring>
using namespace std;

char x[1001];
char y[202];

inline void COPY(char *dst, char *src) {
	int len(strlen(src));
	int i;
	for (i=0; i<len; ++i) dst[i] = src[i];
	dst[i] = '\0';
	return;
}

int main() {
	int i, j, k;
	int lenx, leny;
	int res;
	//freopen("f:\\in.txt", "r", stdin);
	while (scanf("%s %s", x, y) != EOF) {
		leny= strlen(y);
		COPY(y+leny, y);
		lenx = strlen(x);
		res = 0;
		for (i=0; i<=lenx-leny; ++i) {
			for (j=0; j<leny; ++j) {
				for (k=0; k<leny; ++k) {
					if (x[i+k] != y[j+k]) break;
				}
				if (k == leny) {
					++res;
					break;
				}
			}
		}
		printf("%d\n", res);
	}
	return 0;
}
