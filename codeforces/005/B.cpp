nclude <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1024;

char s[MAXN][MAXN];

inline void ps(int x, char c, bool ee) {
	while (x--) printf("%c", c);
	if (ee) puts("");
}

int main() {
	int i, j, k;
	int m, n(0);
	int len(0);
	int o1, o2;
	int turn(0);
	
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
	
	while (gets(s[n++])); --n;
	for (i=0; i<n; ++i) len = max(len, (int)strlen(s[i]));
	ps(len+2, '*', true);
	for (i=0; i<n; ++i) {
		ps(1, '*', false);
		k = len - strlen(s[i]);
		if (k & 1) {
			if (turn) o2 = k >> 1, o1 = k - o2;
			else o1 = k >> 1, o2 = k - o1;
			turn ^= 1;
		} else {
			o1 = k >> 1, o2 = k - o1;
		}
		ps(o1, ' ', false);
		printf("%s", s[i]);
		ps(o2, ' ', false);
		ps(1, '*', true);
	}
	ps(len+2, '*', true);
	return 0;
}

// 964968	 Dec 17, 2011 10:40:20 AM	delta_4d	 B - Center Alignment	 GNU C++	Accepted	 60 ms	 2400 KB
