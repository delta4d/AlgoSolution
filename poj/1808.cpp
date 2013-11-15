#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

int gao(int x, int e, const int m) {
	int r = 1;
	for (x%=m; e; e>>=1,x=(ll)x*x%m) if (e & 1) r = (ll)r * x % m;
	if (r < 0) r += m;
	return r == 1 ? 1 : -1;
}

int main() {
	int tc;
	scanf("%d", &tc);
	for (int a, p, cn=0; cn<tc; ++cn) {
		scanf("%d%d", &a, &p);
		printf("Scenario #%d:\n", cn+1);
		printf("%d\n\n", gao(a, (p-1)/2, p));
	}
	return 0;
}
