#include <cstdio>
#include <memory>
using namespace std;
typedef long long UI;
inline UI gao(UI n, UI m) {
	UI res(1);
	int i, j, k;
	if (n > m) n ^= m ^= n ^= m;
	for (i=1; i<=n; ++i) {
		res = res * (n + m - i + 1) / i;
	}
	return res;
}

int main() {
	UI n, m;
	//freopen("f:\\in.txt", "r", stdin);
	scanf("%lld %lld", &n, &m);
	while (n != 0 || m != 0) {
		printf("%lld\n", gao(n, m));
		scanf("%lld %lld", &n, &m);
	}
	return 0;
}