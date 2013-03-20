#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 10086;

char s[MAXN], end_c[MAXN];
int ts[MAXN];

int main() {
	int i, j, k;
	int m, n;
	int tc;
	int x, y;
	int len;
	int cnt;
	int col;

	scanf("%d", &tc);
	gets(s);
	while (tc--) {
		gets(s);
		k = 7;
		for (n=0; ; ++n) {
			if (sscanf(s+k, "%d[, ]", &m) != 1) break;
			ts[n] = m;
			len = 0;
			do {
				m /= 10;
				++len;
			} while (m);
			k += len + 1;
		}
		for (i=0; s[i]; ++i) {
			if (s[i] == '<' && s[i+1] == '<') break;
		}
		strcpy(end_c, s+i+2);
		if (n == 1) {
			for (i=1; i<MAXN; ++i) ts[i] = ts[i-1] + ts[0];
		} else {
			sort(ts, ts+n);
			for (i=n; i<MAXN; ++i) ts[i] = ts[i-1] + 1;
		}
		//printf("%s\n", end_c);
		//for (i=0; i<n; ++i) printf("%d ", ts[i]); puts("");
		gets(s);

		//puts(s);

		while (strcmp(s, end_c) != 0) {
			col = 0;
			for (i=0; s[i]; ++i) {
				if (s[i] == '\t') {
					for (j=0; j<MAXN; ++j) if (ts[j] > col) break;
					for (k=col; k<ts[j]; ++k) printf(" ");
					col = ts[j];
				} else {
					printf("%c", s[i]);
					++col;
				}
			}
			puts("");
			gets(s);
		}
		if (tc == 0) {
			puts("");
			break;
		}	
		gets(s);
		puts("");
	}

	return 0;
}
