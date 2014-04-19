#include <cstdio>
#include <cstring>
using namespace std;

int main() {
	int tc, cn = 0;
	char s[20];
	for (scanf("%d", &tc); tc--; ) {
		scanf("%s", s);
		int l = strlen(s), ok = 1;
		for (int i=0; i<l; ++i) if (s[i] != s[l-1-i]) ok = 0;
		printf("Case %d: %s\n", ++cn, ok?"Yes":"No");
	}
	return 0;
}

// 252159	2013-08-16 11:03:03	 1225 - Palindromic Numbers (II)	 C++	 0.016	 1088	Accepted
