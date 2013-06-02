#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 100000 + 86;

char s[MAXN];
int f[MAXN];

int main() {
	int n, q;
	scanf("%s", s+1);
	n = strlen(s+1);
	for (int i=1; i<=n; ++i) if (s[i] == s[i+1]) f[i] = 1;
	for (int i=1; i<=n; ++i) f[i] += f[i-1];
	scanf("%d", &q);
	for (int a,b; q--; ) {
		scanf("%d%d", &a, &b);
		int tot = f[b] - f[a-1];
		if (s[b] == s[b+1]) --tot;
		printf("%d\n", tot);
	}

	return 0;
}

// 3795999	 May 30, 2013 7:40:31 PM	* delta_4d	 B - Ilya and Queries	 GNU C++	Accepted	 109 ms	 500 KB
