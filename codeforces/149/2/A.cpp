#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector <pair<int, int> > e;

int main() {
	int x, y, a, b;

	scanf("%d%d%d%d", &x, &y, &a, &b);
	for (int i=b; i<=y; ++i) {
		for (int j=a; j<=x; ++j) {
			if (j > i) e.push_back(make_pair(j, i));
		}
	}	
	sort(e.begin(), e.end());
	printf("%d\n", (int)e.size());
	for (int i=0; i<(int)e.size(); ++i) printf("%d %d\n", e[i].first, e[i].second);

	return 0;
}

// 3998985	 Jul 1, 2013 1:55:01 PM	delta_4d#	 A - Heads or Tails	 GNU C++	Accepted	 15 ms	 100 KB
