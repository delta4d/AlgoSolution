#include <iostream>
using namespace std;

int main() {
	long long n, k;

	cin >> n >> k;
	
	if (n == 1) { cout << 0 << endl; return 0; }
	if (k * (k - 1) < (n - 1) * 2) { cout << -1 << endl; return 0; }

	long long left = 1, right = k - 1, mid;
	while (left <= right) {
		mid = (left + right) >> 1;
		if (n - 1 <= (mid + k - 1) * (k - mid) / 2) left = mid + 1;
		else right = mid - 1;
	}
	cout << k - right << endl;

	return 0;
}

// 3400263	 Mar 24, 2013 5:11:22 PM	delta_4d	 287B - Pipeline	 GNU C++	Accepted	 15 ms	 0 KB
