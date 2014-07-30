#include <bits/stdc++.h>
using namespace std;

char a[20][20] = {"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};
char s[20];
int n;

bool ok(char a[]) {
	if ((int)strlen(a) != (int)strlen(s)) return false;
	for (int i=0; i<n; ++i) {
		if (s[i] == '.') continue;
		if (s[i] != a[i]) return false;
	}
	return true;
}

int main() {
	scanf("%d%s", &n, s);
	for (int i=0; ; ++i) {
		if (ok(a[i])) return puts(a[i]);
	}
	return 0;
}

// 7266832	2014-07-27 22:24:24	delta_4d	A - Eevee	GNU C++0x	Accepted	31 ms	0 KB
