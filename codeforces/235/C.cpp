#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

string s;

int main() {
	int n0, n1;
	cin >> n0 >> n1;
	if (n1 < n0 - 1 || 2*(n0+1) < n1) {
		cout << -1 << endl;
		return 0;
	}
	int r = n1 - n0 + 1, m = max(r, r-4);
	for (int i=0; i<m&&i+1<n0; ++i) s += "011", --r;
	for (int i=m; i+1<n0; ++i) s += "01";
	s += "0";
	if (r == 1) s += "1";
	else if (r == 2) s += "11";
	else if (r == 3) s = "1" + s + "11";
	else if (r == 4) s = "11" + s + "11";
	cout << s << endl;
	return 0;
}

// 6558741	2014-05-05 22:13:11	delta_4d	C - Team	GNU C++0x	Accepted	31 ms	4000 KB
