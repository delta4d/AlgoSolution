#include <cstdio>
using namespace std;

const int MAXN = 1000000 + 86;

char s[MAXN], t[MAXN];

int main() {
	int i, c[2][2]={0};
	scanf("%s%s", s, t);
	for (i=0; s[i]; ++i) {
		++c[s[i]-'0'][t[i]-'0'];
		if (!t[i]) { puts("NO"); return 0; }
	}
	if (t[i]) { puts("NO"); return 0; }
	if (!c[0][1] && c[1][0] && !c[1][1] || c[0][1] && !c[1][0] && !c[1][1]) puts("NO");
	else puts("YES");
	return 0;
}

// 3317229	 Mar 14, 2013 8:21:35 PM	delta_4d	 282C - XOR and OR	 GNU C++	Accepted	 46 ms	 1900 KB
