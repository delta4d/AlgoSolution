#include <cstdio>
#include <vector>
using namespace std;

vector <int> c[5];

int main() {
	int n;

	scanf("%d", &n);
	for (int i=0,x; i<n; ++i) {
		scanf("%d", &x);
		if (x == 0) c[0].push_back(x);
		else if (x == 100) c[1].push_back(x);
		else if (x % 10 == 0) c[2].push_back(x);
		else if (x < 10) c[3].push_back(x);
		else c[4].push_back(x);
	}
	int t = 0, s = 0;
	for (int i=0; i<4; ++i) if (c[i].size()) ++t;
	if (c[2].empty() && c[3].empty() && c[4].size()) ++t, ++s;
	printf("%d\n", t);
	for (int i=0; i<5; ++i) if (i == 4 && s || i < 4 && c[i].size()) printf("%d ", c[i][0]);

	return 0;
}

// 3746057	 May 19, 2013 8:02:21 PM	delta_4d	 A - Strange Addition	 GNU C++	Accepted	 15 ms	 100 KB
