#include <cstdio>
#include <cstring>
using namespace std;

inline bool gao(int m, int n) {
	int i, j, k;
	int tm, tn;
	int t;
	if (m == 0) return false;
	if (m <= n) return true;
	for (i=2; i*i<=m; ++i) {
		if (m % i == 0) {
			tm = 0;
			while (m % i == 0) {
				m /= i;
				++tm;
			}
			t = n, tn = 0;
			while (t != 0) {
				tn += t / i;
				t /= i;
			}
			if (tm > tn) return false;
		}
	}
	if (m != 1) return n >= m;
	return true;
}

int main() {
	int m, n;
	int i, j, k;
	//freopen("f:\\in.txt", "r", stdin);
	while (scanf("%d %d", &n, &m) != EOF) {
		printf("%d %s %d!\n", m, gao(m, n)?"divides":"does not divide", n);
	}
	return 0;
}