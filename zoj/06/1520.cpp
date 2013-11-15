#include <cstdio>
#include <memory>
using namespace std;
const int MAXN = 2002;
int c[MAXN];
bool v[MAXN];

int main() {
	int m, n, l;
	int i, j, k;
	int tot, sum, cnt;
	//freopen("f:\\in.txt", "r", stdin);
	scanf("%d %d", &m, &l);
	while (m != 0 || l != 0) {
		scanf("%d", &n);
		sum = 0;
		for (i=1; i<=n; ++i) {
			scanf("%d", c+i);
			sum += c[i];
		}
		if (sum > m + l) {
			puts("Impossible to distribute");
			goto next;
		}
		for (i=1; i<=n; ++i) {
			tot = 0;
			cnt = 0;
			memset(v, false, sizeof(v));
			for (j=i; j<=n; ++j) {
				if (tot + c[j] <= m) {
					tot += c[j];
					v[j] = true;
					++cnt;
				}
			}
			if (tot + l >= sum) break;
		}
		if (i == n + 1) {
			puts("Impossible to distribute");
			goto next;
		}
		printf("%d", cnt);
		for (i=1; i<=n; ++i) if (v[i]) printf(" %d", i);
		puts("");
	next:
		scanf("%d %d", &m, &l);
	}
	return 0;
}
