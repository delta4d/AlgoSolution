#include <cstdio>
#include <algorithm>
using namespace std;

char s[27];

int main() {
	int tc, cn = 0, n, k;
	for (scanf("%d", &tc); tc--; ) {
		printf("Case %d:\n", ++cn);
		scanf("%d%d", &n, &k);
		for (int i=0; i<n; ++i) s[i] = i + 'A'; s[n] = '\0';
		for (int i=0; i<k; ++i) {
			puts(s);
			if (NULL == next_permutation(s, s+n)) break;
		}
	}
	return 0;
}

// 257670	2013-08-30 20:55:38	 1023 - Discovering Permutations	 C++	 0.000	 1088	Accepted
