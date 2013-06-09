#include <cstdio>
#include <cstring>
using namespace std;

char a[128], c[128];
int nxt[128], len[128];

int main() {
	int b, d;

	scanf("%d%d%s%s", &b, &d, a, c);
	int la = strlen(a), lc = strlen(c);
	for (int i,j,k=0; k<lc; nxt[k++]=j) {
		for (i=0,j=k; i<la; ++i) if (a[i] == c[j]) j = (j >= lc - 1 ? 0 : j + 1), ++len[k];
	}
	int tot = 0;
	for (int i=0,k=0; i<b; ++i,k=nxt[k]) tot += len[k];
	printf("%d\n", tot/lc/d);

	return 0;
}

// 3847083	 Jun 8, 2013 4:47:19 PM	delta_4d	 B - Sereja and Periods	 GNU C++	Accepted	31 ms	0 KB
