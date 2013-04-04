#include <string>
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int n, k;

	scanf("%d%d", &n, &k);

	if (k == 1) {
		if (n == 1) puts("a");
		else puts("-1");
	} else if (k > n) {
		puts("-1");
	} else {
		int x = (n - (k - 2)) / 2;
		for (int i=0; i<x; ++i) printf("ab");
		if (n - 2 * x > k - 2) {
			printf("a");	
		}
		for (int i=0; i<k-2; ++i) printf("%c", i+'c');
		puts("");
	}

	return 0;
}

// 3454508	 Apr 2, 2013 7:41:37 PM	delta_4d	 A - Polo the Penguin and Strings	 GNU C++	Accepted	 93 ms	 0 KB
