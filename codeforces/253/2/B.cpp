#include <bits/stdc++.h>
using namespace std;

string s;

bool ok(string &s1, string &s2) {
	for (int i=(int)s1.length()-1; i>=0; --i) {
		if (s1[i] == '#' || s2[i] == '#') continue;
		if (s1[i] != s2[i]) return false;
	}
	return true;
}

int main() {
	int k, len;
	cin >> s >> k;
	len = (int)s.length();
	s.resize(len+k, '#');
	for (int L=(k+len)/2; L>0; --L) {
		for (int i=0; i+2*L<=len+k; ++i) {
			string s1 = s.substr(i, L), s2 = s.substr(i+L, L);
			if (ok(s1, s2)) {
				cout << L * 2 << endl;
				return 0;
			}
		}
	}
	return 0;
}

// 6925571	 2014-06-20 10:05:23	delta_4d	 B - Kolya and Tandem Repeat	 GNU C++0x	Accepted	31 ms	148 KB
