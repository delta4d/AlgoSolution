#include <cctype>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char s1[111], s2[111], buf[111];

void f(char s[]) {
	gets(buf);
	int k = 0;
	for (int i=0; buf[i]; ++i) if (buf[i] != ' ') s[k++] = tolower(buf[i]);
	sort(s, s+k);
	s[k] = '\0';
}

int main() {
	int tc, cn = 0;
	for (scanf("%d", &tc),gets(buf); tc--; ) {
		f(s1); f(s2);
		if (strcmp(s1, s2) == 0) printf("Case %d: Yes\n", ++cn);
		else printf("Case %d: No\n", ++cn);
	}
	return 0;
}

// 252565	2013-08-17 17:49:21	 1338 - Hidden Secret!	 C++	 0.000	 1088	Accepted
