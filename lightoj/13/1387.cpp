#include <cstdio>
using namespace std;

typedef long long ll;
char op[10];

int main() {
	int tc, cn = 0, n;
	for (scanf("%d", &tc); tc--; ) {
		printf("Case %d:\n", ++cn);
		scanf("%d", &n);
		ll tot = 0, x;
		while (n--) {
			scanf("%s", op);
			if (op[0] == 'r') printf("%d\n", tot);
			else scanf("%d", &x), tot += x;
		}
	}
	return 0;
}

// 252269	2013-08-16 19:26:53	 1387 - Setu	 C++	 0.004	 1088	Accepted
