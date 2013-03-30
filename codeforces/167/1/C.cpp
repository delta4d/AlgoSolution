#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 300000 + 86;

vector <int> T[MAXN];
int colo[MAXN];

int main() {
	int n, m;
	int a, b;

	scanf("%d%d", &n, &m);
	for (int i=0; i<m; ++i) {
		scanf("%d%d", &a, &b); --a, --b;
		T[a].push_back(b);
		T[b].push_back(a);
	}
	while (true) {
		bool ff=false;
		for (int i=0; i<n; ++i) {
			int cc=0;
			for (int j=0; j<(int)T[i].size(); ++j) cc += colo[T[i][j]] == colo[i];
			if (cc > 1) colo[i] ^= 1, ff = true;
		}
		if (!ff) break;
	}
	for (int i=0; i<n; ++i) printf("%d", colo[i]); puts("");

	return 0;
}

// 3381283	 Mar 22, 2013 6:47:51 PM	delta_4d	 273C - Dima and Horses	 GNU C++	Accepted	578 ms	10300 KB
