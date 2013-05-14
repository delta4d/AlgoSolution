#include <set>
#include <cstdio>
using namespace std;

set <int> s;

int main() {
	int n, tot = 0;
	
	scanf("%d", &n);
	for (int i=1; i<=n; ++i) {
		s.insert(i * i);
		for (int j=1; 2*j*j<=i*i; ++j) {
			int k = i * i - j * j;
			if (s.find(k) != s.end()) ++tot;
		}
	}
	printf("%d\n", tot);

	return 0;
}

// 3720658	 May 14, 2013 7:08:18 PM	delta_4d	 A - Pythagorean Theorem II	 GNU C++	Accepted	2215 ms	400 KB
