#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;

const int MAXN = 100000 + 86;

int a[MAXN];

int main() {
	int n;
	LL cc=0;
	int w, h, tw=0, th=0;

	cin >> n;
	for (int i=0; i<n; ++i) cin >> a[i];
	cin >> n;
	while (n--) {
		cin >> w >> h;
		cc = max(cc+th, (LL)a[w-1]);
		tw = w, th = h;
		cout << cc << endl;
	}

	return 0;
}

// 3374339	 Mar 21, 2013 8:57:56 PM	delta_4d	 A - Dima and Staircase	 GNU C++	Accepted	531 ms	400 KB
