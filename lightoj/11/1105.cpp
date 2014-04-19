#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 45;

int s[N];

void init() {
	s[1] = 1;
	int x0 = 0, x1 = 1, y0, y1;
	for (int i=2; i<N; ++i) {
		y0 = x0 + x1, y1 = x0;
		s[i] = s[i-1] + y0 + y1;
		x0 = y0, x1 = y1;
	}
}

int main() {
	init();
	int tc, cn = 0, n;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d", &n);
		printf("Case %d: ", ++cn);
		int L = lower_bound(s, s+N, n) - s, rem = n;
		for (int i=1; i<=L; ++i) {
			if (s[L-i] < rem && rem <= s[L-i+1]) printf("1"), rem -= s[L-i] + 1;
			else printf("0");
		}
		puts("");
	}
	return 0;
}

// 294648	2013-12-02 20:45:22	 1105 - Fi Binary Number	 C++	 0.016	 1088	Accepted
