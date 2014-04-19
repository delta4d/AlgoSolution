#include <cstdio>
using namespace std;

int main() {
	int tc, cn = 0, m;
	int x1, y1, x2, y2, x, y;

	for (scanf("%d", &tc); tc--; ) {
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		scanf("%d", &m);
		printf("Case %d:\n", ++cn);
		while (m--) {
			scanf("%d%d", &x, &y);
			if (x1 <= x && x <= x2 && y1 <= y && y <= y2) puts("Yes");
			else puts("No");
		}
	}

	return 0;
}

// [252184	2013-08-16 13:51:01	 1107 - How Cow	 C++	 0.000	 1088	Accepted
