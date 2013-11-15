#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 10086;

bool is_p[MAXN];
int p[MAXN], pn;

struct node {
	int cnt[MAXN];
	
	void gao(int n) {
		memset(cnt, 0, sizeof(cnt));
		for (int i=0; i<pn; ++i) if (n % p[i] == 0) {
			do {++cnt[i]; n /= p[i]; } while (n % p[i] == 0);
		}
		if (n != 1) {
			for (int i=0; i<pn; ++i) if (p[i] == n) {++cnt[i]; break; }
		}
	}
	bool divide(const int m, const node &a) {
		for (int i=0; i<pn; ++i) if (cnt[i] * m < a.cnt[i]) return false;
		return true;
	}
} a, b;

void gen() {
	memset(is_p, true, sizeof(is_p));
	for (int i=2; i<MAXN; ++i) {
		if (is_p[i]) {
			p[pn++] = i;
			for (int j=i<<1; j<MAXN; j+=i) is_p[j] = false;
		}
	}
	//printf("%d\n", pn);
}

int main() {
	int i, j, k;
	int m, n;
	int tot(0);
	int x;
	
	gen();
	scanf("%d %d %d", &n, &m, &k);
	b.gao(k);
	while (n--) {
		scanf("%d", &x);
		a.gao(x);
		tot += a.divide(m, b);
	}
	printf("%d\n", tot);
	
	return 0;
}