#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int i, j, k;
	int m, n;
	
	scanf("%d %d", &m, &n);
	n = 6 - max(m, n) + 1;
	k = __gcd(n, 6);
	printf("%d/%d\n", n/k, 6/k);
	return 0;
}

// 911391	 Nov 30, 2011 3:27:49 PM	delta_4d	 A - Die Roll	 GNU C++	Accepted	 30 ms	 1300 KB
