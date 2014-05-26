#include <cstdio>

int main() {
	int n, tot = 0;
	scanf("%d", &n);
	for (int x,i=0,sum=0; i<n; ++i) {
		scanf("%d", &x);
		sum += x;
		if (sum < 0) ++tot, sum = 0;
	}
	printf("%d\n", tot);
	return 0;
}

// 6536498	 May 3, 2014 10:45:08 AM	delta_4d	 A - Police Recruits	 GNU C++0x	Accepted	 31 ms	 0 KB
