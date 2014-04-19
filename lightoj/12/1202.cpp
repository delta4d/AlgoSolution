#include <cstdio>
using namespace std;

int main() {
	int tc, cn = 0;
	for (scanf("%d", &tc); tc--; ) {
		int x, y, tx, ty;
		scanf("%d%d%d%d", &x, &y, &tx, &ty);
		x -= tx, y -= ty;
		if (x < 0) x = -x;
		if (y < 0) y = -y;
		printf("Case %d: ", ++cn);
		if ((x + y) & 1) puts("impossible");
		else printf("%d\n", x==y?1:2);
	}
	return 0;
}

// 252291	2013-08-16 20:26:51	 1202 - Bishops	 C++	 0.012	 1088	Accepted
