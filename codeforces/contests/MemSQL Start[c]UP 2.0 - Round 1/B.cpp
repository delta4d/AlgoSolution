#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;

	scanf("%d%d", &n, &m);
	if (n == 0) {
		printf("0 %d\n", 1);
		printf("0 %d\n", m);
		printf("0 %d\n", 0);
		printf("0 %d\n", m-1);
	} else if (m == 0) {
		printf("%d 0\n", 1);
		printf("%d 0\n", n);
		printf("%d 0\n", 0);
		printf("%d 0\n", n-1);
	} else {
		if (m > n) {
			double d1 = 2*sqrt(m*m+n*n)+m;
			double d2 = sqrt(m*m+n*n)+2*sqrt((n-1)*(n-1)+m*m);
			if (d2 > d1) {
				printf("%d %d\n", 1, 0);
				printf("%d %d\n", n, m);
				printf("%d %d\n", 0, 0);
				printf("%d %d\n", n-1, m);
			} else {
				printf("%d %d\n", 0, 0);
				printf("%d %d\n", n, m);
				printf("%d %d\n", n, 0);
				printf("%d %d\n", 0, m);
			}
		} else {
			double d1 = 2*sqrt(m*m+n*n)+n;
			double d2 = sqrt(m*m+n*n)+2*sqrt((m-1)*(m-1)+n*n);
			if (d2 > d1) {
				printf("%d %d\n", 0, 1);
				printf("%d %d\n", n, m);
				printf("%d %d\n", 0, 0);
				printf("%d %d\n", n, m-1);
			} else {
				printf("%d %d\n", 0, 0);
				printf("%d %d\n", n, m);
				printf("%d %d\n", 0, m);
				printf("%d %d\n", n, 0);
			}
		}
	}

	return 0;
}

// 7266295	2014-07-27 22:15:31	delta_4d	B - 4-point polyline	GNU C++0x	Accepted	15 ms	0 KB
