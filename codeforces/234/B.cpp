#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

char s[1000][1001];
vector <int> d;

int main() {
	int m, n;
	scanf("%d%d", &m, &n);
	for (int i=0; i<m; ++i) {
		scanf("%s", s[i]);
		for (int j=0,p=-1; j<n; ++j) if (s[i][j] != '*') {
			if (s[i][j] == 'S') {
				if (p == -1) return puts("-1"), 0;
				d.push_back(j-p);
			}
			if (s[i][j] == 'G') p = j;
		}
	}
	sort(begin(d), end(d));
	printf("%d\n", unique(begin(d), end(d))-begin(d));
	return 0;
}

// 6561505	 May 6, 2014 2:02:33 PM	delta_4d	 B - Inna and New Matrix of Candies	 GNU C++0x	Accepted	 31 ms	 1000 KB
