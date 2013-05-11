#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 100000 + 86;

bool np[MAXN];
int x[MAXN];
vector <int> f[MAXN];
int cc[MAXN];
int mx[MAXN];

void init() {
	for (int i=2; i<MAXN; ++i) if (!np[i]) {
		f[i].push_back(i);
		for (int j=i<<1; j<MAXN; j+=i) {
			np[j] = true;
			f[j].push_back(i);
		}
	}	
}

int main() {
	int n;

	scanf("%d", &n);
	for (int i=0; i<n; ++i) scanf("%d", x+i);
	init();
	for (int i=0; i<n; ++i) {
		cc[i] = 1;
		for (int j=0; j<f[x[i]].size(); ++j) {
			int pp = f[x[i]][j];	
			cc[i] = max(cc[i], mx[pp]+1);
		}	
		for (int j=0; j<f[x[i]].size(); ++j) {
			int pp = f[x[i]][j];	
			mx[pp] = max(mx[pp], cc[i]);
		}	
	}
	int mx = 0;
	for (int i=0; i<n; ++i) mx = max(mx, cc[i]);
	printf("%d\n", mx);

	return 0;
}

// 3699058	 May 10, 2013 3:58:26 PM	delta_4d	 B - Good Sequences	 GNU C++	Accepted	78 ms	5052 KB
