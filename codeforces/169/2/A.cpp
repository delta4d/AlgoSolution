#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;

int main() {
	int n, k;
	int f, t;
	int mx(-INF);

	scanf("%d%d", &n, &k);
	
	while (n--) {
		scanf("%d%d", &f, &t);
		mx = max(mx, t>k?f-(t-k):f);
	}

	printf("%d\n", mx);

	return 0;
}

// 3295481	 Mar 12, 2013 8:00:55 PM	delta_4d	 276A - Lunch Rush	 GNU C++	Accepted	 15 ms	 0 KB
