#include <cstdio>
using namespace std;

const int MAXN = 1024;

char s[MAXN];

int main() {
	int n;
	int RL = -1, RR = -1, LL = -1, LR = -1;

	scanf("%d%s", &n, s);
	for (int i=0; i<n; ++i) {
		if (s[i] == 'R') RL = RL == -1 ? i + 1 : RL, RR = i + 1;
		if (s[i] == 'L') LL = LL == -1 ? i + 1 : LL, LR = i + 1;
	}
	if (RL == -1 && RR == -1) printf("%d %d\n", LR, LL-1);
	else if (LL == -1 && LR == -1) printf("%d %d\n", RL, RR+1);
	else printf("%d %d\n", RL, RR);

	return 0;
}

// 3583424	 Apr 21, 2013 8:46:33 AM	delta_4d	 A - Snow Footprints	 GNU C++	Accepted	 15 ms	 0 KB
