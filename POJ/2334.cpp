#include <cstdio>
#include <cstring>
using namespace std;

const int MAXL = 256;
char cur[MAXL], pre[MAXL];

int main() {
	int m, n;
	int i, j, k;
	int sum, tc;
	//freopen("f:\\in.txt", "r", stdin);
	while (scanf("%d", &n) != EOF) {
		scanf("%s", pre);
		sum = strlen(pre);
		for (i=1; i<n; ++i) {
			scanf("%s", cur);
			k = 0;
			while (cur[k] == pre[k] && cur[k] && pre[k]) ++k;
			sum += strlen(cur) - k + 1;
			strcpy(pre, cur);
		}
		printf("%d\n", sum);
		if (tc != 0) puts("");
	}
	return 0;
}