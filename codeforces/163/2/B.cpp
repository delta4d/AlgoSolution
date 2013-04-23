#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int n, t;
	char s[64];

	scanf("%d%d%s", &n, &t, s);
	for (int i=0; i<t; ++i) {
		for (int j=0; j<n; ++j) if (j + 1 < n && s[j] == 'B' && s[j+1] == 'G') {
			swap(s[j], s[j+1]);
			++j;
		}
	}
	puts(s);

	return 0;
}

// 3600270	 Apr 22, 2013 2:06:50 PM	delta_4d	 266B - Queue at the School	 GNU C++	Accepted	15 ms	0 KB
