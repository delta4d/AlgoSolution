#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 16;

char bx[MAXN], by[MAXN];
int x[MAXN], y[MAXN];

int gao(char buf[], int x[]) {
	int len = strlen(buf);
	memset(x, 0, sizeof(int)*MAXN);
	for (int i=0; i<len; ++i) x[i] = buf[len-1-i] - '0';
}

int main() {
	int i, j, k;

	while (scanf("%s %s", bx, by), bx[0]!='0'||by[0]!='0') {
		gao(bx, x);
		gao(by, y);
		k = 0;
		for (i=0; i<MAXN; ++i) x[i] += y[i];
		for (i=0; i+1<MAXN; ++i) {
			if (x[i] >= 10) {
				++k;
				x[i+1] += x[i] / 10;
				x[i] %= 10;
			}
		}
		if (k == 0) puts("No carry operation.");
		else if (k == 1) printf("%d carry operation.\n", k);
		else printf("%d carry operations.\n", k);
	}
	return 0;
}