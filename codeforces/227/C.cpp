#include <string>
#include <iostream>
using namespace std;

string s, cc, pre, x;

int main() {
	ios_base::sync_with_stdio(false);
	cin >> s;
	int tot = 1, sz = (int)s.length();
	for (int i=0; i<sz; ++i) {
		cc = cc + s[i];
		if (s[i] == '0') {
			x += '0';
		} else {
			x = s[i];
		}
		if (s[i+1] != '0') {
			int lx = (int)x.length(), lp = (int)pre.length();
			if (lx < lp || lx == lp && x <= pre) {
				tot = tot + 1;
			} else {
				tot = 1;
			}
			pre = cc;
		}
	}
	cout << tot << endl;
	return 0;
}

// 6572774	 May 8, 2014 6:11:55 PM	delta_4d	 C - George and Number	 GNU C++0x	Accepted	 654 ms	 1700 KB
