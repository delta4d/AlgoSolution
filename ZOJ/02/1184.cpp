#include <cstdio>
#include <memory>
using namespace std;

const int MAXN = 13;
const char s[2][6] = {"heavy", "light"};
int w[MAXN];
struct node {
	char s1[MAXN];
	char s2[MAXN];
	char r[MAXN];
}f[3];

inline bool gao() {
	int i, j, k;
	int sum1, sum2;
	int len;
	for (i=0; i<3; ++i) {
		len = strlen(f[i].s1);
		sum1 = 0, sum2 = 0;
		for (j=0; j<len; ++j) {
			sum1 += w[f[i].s1[j]-'A'];
			sum2 += w[f[i].s2[j]-'A'];
		}
		if (strcmp(f[i].r, "even") == 0) {
			if (sum1 != sum2) return false;
		} else if (strcmp(f[i].r, "up") == 0) {
			if (sum1 <= sum2) return false;
		} else if (sum1 >= sum2) {
			return false;
		}
	}
	return true;
}

int main() {
	int i, j, k, t;
	int tc;
	int index;
	//freopen("f:\\in.txt", "r", stdin);
	//freopen("f:\\out.txt", "w", stdout);
	scanf("%d", &tc);
	for (t=0; t<tc; ++t) {
		for (i=0; i<3; ++i) scanf("%s %s %s", f[i].s1, f[i].s2, f[i].r);
		for (i=0; i<12; ++i) {
			memset(w, 0, sizeof(w));
			w[i] = -1;
			if (gao()) {
				index = i;
				k = 1;
				break;
			}
			w[i] = 1;
			if (gao()) {
				index = i;
				k = 0;
				break;
			}
		}
		printf("%c is the counterfeit coin and it is %s.\n", index+'A', s[k]);
	}
	return 0;
}
