#include <bits/stdc++.h>
using namespace std;

char s[1<<10];

bool ok(int p, char c) {
	if (p > 0 && s[p-1] == c) return false;
	if (p > 1 && s[p-2] == c) return false;
	return true;
}

int main() {
	int n, p;
	scanf("%d%d%s", &n, &p, s);
	for (int i=n-1; i>=0; --i) {
		for (char c=s[i]+1; c<'a'+p; ++c) {
			if (!ok(i, c)) continue;
			s[i] = c;
			for (int j=i+1; j<n; ++j) for (s[j]='a'; !ok(j,s[j])&&s[j]<'a'+p; ++s[j]);
			return puts(s), 0;
		}
	}
	puts("NO");
	return 0;
}

// 7715585	2014-09-07 23:47:12	delta_4d	A - No to Palindromes!	GNU C++0x	Accepted	31 ms	0 KB
