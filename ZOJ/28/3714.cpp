#include <cstdio>
using namespace std;

int a[500];

int main() {
	int n, m;

	scanf("%*d");
	while (2 == scanf("%d%d", &n, &m)) {
		int mx = 0, cc = 0;
		for (int i=0; i<n; ++i) scanf("%d", a+i), a[n+i] = a[i];	
		for (int i=0; i<m; ++i) cc += a[i]; mx = cc;
		for (int i=m; i<2*n; ++i) {
			cc += a[i] - a[i-m];
			if (cc > mx) mx = cc;
		}
		printf("%d\n", mx);
	}

	return 0;
}
