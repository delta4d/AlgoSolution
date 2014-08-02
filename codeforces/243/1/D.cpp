#include <bits/stdc++.h>
using namespace std;

int const N = 1e5 + 10;
int const B = 333;

vector <int> e[N];

bool f(int x, int y) {
	if (x > N || y > N) return false;
	return binary_search(begin(e[x]), end(e[x]), y);
}

int main() {
	int n, tot = 0;
	scanf("%d", &n);
	for (int i=0,x,y; i<n; ++i) scanf("%d%d", &x, &y), e[x].push_back(y);
	for (int i=0; i<N; ++i) sort(begin(e[i]), end(e[i]));
	for (int k=0; k<N; ++k) {
		int sz = (int)e[k].size();
		if (sz <= B) {
			for (int i=0; i<sz; ++i) for (int j=i+1; j<sz; ++j) {
				int x = k, y = e[k][i], d = e[k][j] - y;
				tot += f(x+d, y) && f(x+d, y+d);
			}
		} else {
			for (int i=k+1; i<N; ++i) for (int j=0; j<(int)e[i].size(); ++j) {
				int x = k, y = e[i][j], d = i - k;
				tot += f(x, y) && f(x, y+d) && f(x+d, y+d);
			}
		}
	}
	printf("%d\n", tot);
	return 0;
}

// 7303864	2014-08-01 07:58:00	delta_4d	D - Sereja and Squares	GNU C++0x	Accepted	514 ms	2896 KB
