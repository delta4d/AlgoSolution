#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 5000 + 86;
typedef long long LL;

LL x[MAXN], p2[MAXN], odd[MAXN], dp[MAXN];

inline bool ok(int i, int j) {
	return odd[i] % odd[j] == 0 && (p2[i] + j - i == p2[j] || p2[j] <= j - i - 1);	
}

int main() {
	int n;

	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> x[i];
		odd[i] = x[i];
		for (; odd[i]%2==0; odd[i]>>=1, ++p2[i]);
	}
	fill(dp, dp+n, 1);
	for (int i=1; i<n; ++i) {
		for (int j=0; j<i; ++j) if (ok(j, i)) dp[i] = max(dp[i], dp[j]+1);
	}
	cout << n - *max_element(dp, dp+n) << endl;

	return 0;
}

// 3353104	 Mar 18, 2013 9:04:25 PM	delta_4d	 283D - Cows and Cool Sequences	 GNU C++	Accepted	390 ms	200 KB
