#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 501;
int m, k;
int book[MAXN];
int sum[MAXN];
bool divide[MAXN];
bool td[MAXN];

inline bool	gao(const int lim) {
	int i, num(0);
	int c(m);
	memset(td, false, sizeof(td));
	for (i=m-1; i>=0; --i) {
		if (sum[c] - sum[i] > lim) {
			if (c == i + 1) return false;
			c = i + 1;
			++num;
			td[c] = true;
			++i;
		}
	}
	int r(k-num), t(0);
	for (i=1; i<=m; ++i) {
		if (r <= 0) break;
		if (t == r) break;
		if (!td[i]) {
			td[i] = true;
			++t;
		}
	}
	return num > k ? false : true;
}

void gao() {
	int i, j;
	int left(1), right(sum[m]), mid;
	memset(divide, false, sizeof(divide));
	while (left <= right) {
		mid = (left + right) >> 1;
		if (gao(mid)) {
			memcpy(divide, td, sizeof(td));
			right = mid - 1;
		} else {
			left = mid + 1;
		}
	}
	for (i=1; i<=m; ++i) {
		printf("%d ", book[i]);
		if (divide[i]) printf("/ ");
	}
	puts("");
}

int main() {
	int i, j;
	int tc;
	//freopen("f:\\in.txt", "r", stdin);
	//freopen("f:\\out.txt", "w", stdout);
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d %d", &m, &k);
		memset(sum, 0, sizeof(sum));
		--k;
		for (i=1; i<=m; ++i) {
			scanf("%d", book+i);
			sum[i] = sum[i-1] + book[i];
		}
		gao();
	}
	return 0;
}