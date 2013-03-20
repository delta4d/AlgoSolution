#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;

int main() {
	char s[3];
	LL w, wb;
	LL x;
	int m, n;
	int i, j, k;
	//freopen("f:\\in.txt", "r", stdin);
	while (scanf("%d", &n) != EOF) {
		w = wb = 0;
		for (i=0; i<n; ++i) {
			scanf("%s %lld", s, &x);
			if (strcmp(s, "b") == 0) {
				w -= x;
			} else if (strcmp(s, "w") == 0) {
				w += x;
			} else if (strcmp(s, "bb") == 0) {
				w -= (x << 1);
			} else if (strcmp(s, "ww") == 0) {
				w += (x << 1);
			} else if (strcmp(s, "bw") == 0) {
				wb -= x;
			} else if (strcmp(s, "wb") == 0) {
				wb += x;
			} else {
				throw "input error !";
			}
		}
		if (w >= 0) {
			if ((w << 1) > wb) printf("win "); else printf("lose ");
			if ((w << 1) >= wb) printf("win\n"); else printf("lose\n");
		} else {
			w *= -1, wb *= -1;
			if ((w << 1) < wb) printf("win "); else printf("lose ");
			if ((w << 1) <= wb) printf("win\n"); else printf("lose\n");
		}
	}
	return 0;
}