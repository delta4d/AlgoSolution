#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

map <int, int> cc;

int f(int x) {
	if (x == 0) return 0;
	return x & 1 ? f(x>>1) + 1 : f(x>>1);
}

int main() {
	int n, x;

	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> x;
		++cc[f(x)];
	}

	long long tot = 0;
	for (map<int, int>::iterator it=cc.begin(); it!=cc.end(); ++it) {
		tot += (long long)(it->second) * (it->second - 1) >> 1;
	}
	cout << tot << endl;

	return 0;
}

// 3416395	 Mar 28, 2013 8:18:35 PM	delta_4d	 272B - Dima and Sequence	 GNU C++	Accepted	187 ms	100 KB
