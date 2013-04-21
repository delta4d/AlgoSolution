#include <cstdio>
using namespace std;

const int MAXN = 1024;

char a[MAXN], b[MAXN];

int main() {
	scanf("%s%s", a, b);	
	int na = 0, nb = 0;
	for (int i=0; a[i]; ++i) na += a[i] - '0';
	for (int i=0; b[i]; ++i) nb += b[i] - '0';
	na = (na + 1) / 2 * 2;
	if (na >= nb) puts("YES");
	else puts("NO");

	return 0;
}

// 3579930	 Apr 20, 2013 2:15:52 PM	delta_4d	 297A - Parity Game	 GNU C++	Accepted	15 ms	0 KB
