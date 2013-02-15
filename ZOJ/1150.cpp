#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 8;
const int MAXL = 128;

int order[MAXN];
char s[MAXL+1];
char in[MAXN];

int main() {
	int i, j, k;
	int m, n;
	int cn(0);
	//freopen("f:\\in.txt", "r", stdin);
	scanf("%d", &n);
	while (n != 0) {
		for (i=0; i<n; ++i) {
			scanf("%*[x \n] %d", order+i);
		}
		scanf("%s", s);
		printf("S-Tree #%d:\n", ++cn);
		scanf("%d", &m);
		for (i=0; i<m; ++i) {
			scanf("%s", in);
			k = 0;
			for (j=0; j<n; ++j) {
				k <<= 1;
				k += in[order[j]-1] - '0';
			}
			printf("%c", s[k]);
		}
		puts("\n");
		scanf("%d", &n);
	}
	return 0;
}