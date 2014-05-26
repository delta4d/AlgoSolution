#include <cstdio>

int main() {
	int n, t, c, tot = 0, i, j, x;
	scanf("%d%d%d", &n, &t, &c);
	for (i=-1,j=0; j<n; ++j) {
		scanf("%d", &x);
		if (x > t) {
			if (i != -1 && j - i >= c) tot += j - i - c + 1;
			i = -1;
		} else if (i == -1) {
			i = j;
		}
	}
	if (x <= t && i != -1 && j - i >= c) tot += j - i - c + 1; 
	printf("%d\n", tot);
	return 0;
}

// 6536666	 May 3, 2014 11:12:52 AM	delta_4d	 B - Prison Transfer	 GNU C++0x	Accepted	 61 ms	 0 KB
