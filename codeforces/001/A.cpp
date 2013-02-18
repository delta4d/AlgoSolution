#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	long long n, m, a;

	cin >> n >> m >> a;
	
	if (m > n) swap(m, n);
	if (m == 1) cout << (n + a - 1) / a << endl;
	else cout << ((n + a - 1) / a) * ((m + a - 1) / a) << endl;

	return 0;
}

//#          When	                    Who	         Problem	         Lang	    Verdict	    Time	Memory
//2849687	 Dec 28, 2012 7:23:55 PM	delta_4d	 A - Theater Square	 GNU C++	Accepted	15 ms	4 KB
