#include <cstdio>
#include <algorithm>
using namespace std;

struct node {
	char name[30];
	int v;

	bool operator<(const node &a) const {
		return v < a.v;
	}
	void read() {
		int a, b, c;
		scanf("%s%d%d%d", name, &a, &b, &c);
		v = a * b * c;
	}
} f[111];

int main() {
	int tc, cn = 0, n;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d", &n);
		for (int i=0; i<n; ++i) f[i].read();
		sort(f, f+n);
		printf("Case %d: ", ++cn);
		if (f[0].v == f[n-1].v) puts("no thief");
		else printf("%s took chocolate from %s\n", f[n-1].name, f[0].name);
	}
	return 0;
}

// 252606	2013-08-17 20:21:17	 1249 - Chocolate Thief	 C++	 0.004	 1096	Accepted
