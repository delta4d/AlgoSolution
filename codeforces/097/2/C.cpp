#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 100086;

int f[MAXN];

int main() {
	int i, j, k;
	int m, n;
	
	scanf("%d", &n);
	for (k=i=0; i<n; ++i) {
		scanf("%d", f+i);
		if (f[i] != 1) k = 1;
	}
	sort(f, f+n);
	if (k) f[n-1] = 1;
	else f[n-1] = 2;
	sort(f, f+n);
	for (i=0; i<n; ++i) printf("%d%c", f[i], i==n-1?'\n':' ');
	return 0;
}

// 938469	 Dec 9, 2011 7:12:02 PM	delta_4d	 A - Replacement	 GNU C++	Accepted	 130 ms	 1700 
