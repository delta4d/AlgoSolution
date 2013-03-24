#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int f[100000 + 86];

int main() {
	int n;

	scanf("%d", &n);

	if (n % 4 == 0 || n % 4 == 1) {
		for (int i=1; i*2<=n; ++i,++i) {
			int x = i, y = i + 1;
			f[x] = y;
			f[n-y+1] = x;
			f[n-x+1] = n - y + 1;
			f[y] = n - x + 1;
		}	
		if (n % 4 == 1) f[n/2+1] = n/2+1;
		for (int i=1; i<=n; ++i) printf("%d%s", f[i], i==n?"\n":" ");
	} else {
		puts("-1");
	}

	return 0;
}

// 3387784	 Mar 23, 2013 12:42:08 PM	delta_4d	 A - Lucky Permutation	 GNU C++	Accepted	 31 ms	 400 KB
