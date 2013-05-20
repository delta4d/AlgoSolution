#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

map <long long, long long> c;

int main() {
	ios_base::sync_with_stdio(false);
	
	int n;
	cin >> n;
	for (int i=0,x; i<n; ++i) {
		cin >> x;
		++c[x];
	}
	for (map<long long,long long>::iterator it=c.begin(); it!=c.end(); ++it) {
		long long x = it->second;
		for (int i=1; i<40; ++i) if (x >> i & 1) ++c[(it->first) + i];
		(it->second) &= 1;
	}
	long long mx = 0, tot = 0;
	for (map<long long,long long>::iterator it=c.begin(); it!=c.end(); ++it) {
		if (it->second) ++tot;
		mx = max(mx, it->first);
	}
	cout << mx - tot + 1 << endl;

	return 0;
}

// 3739865	 May 19, 2013 5:39:55 PM	* delta_4d	 C - Ivan and Powers of Two	 GNU C++	Accepted	 62 ms	 4100 KB
