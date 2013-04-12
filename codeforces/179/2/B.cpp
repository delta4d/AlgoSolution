#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 100000 + 86;
const int MOD = 1000000007;

char s[MAXN], w[MAXN];
int dp[2][4];

int main() {
	ios_base::sync_with_stdio(false);

	int n;
	int c = 0, p = 0;

	cin >> n;
	cin >> s >> w;
	dp[c][0] = 1;
	for (int i=0; i<n; ++i, c=p) {
		p = c ^ 1;
		if (s[i] == '?') {
			if (w[i] == '?') {
				dp[p][0] = (10ll * dp[c][0]) % MOD;	
				dp[p][1] = (45ll * dp[c][0] + 55ll * dp[c][1]) % MOD;
				dp[p][2] = (45ll * dp[c][0] + 55ll * dp[c][2]) % MOD;
				dp[p][3] = (100ll * dp[c][3] + 45ll * dp[c][2] + 45ll * dp[c][1]) % MOD;
			} else {
				int k = w[i] - '0';
				dp[p][0] = dp[c][0];	
				dp[p][1] = ((9ll - k) * dp[c][0] + (9ll - k + 1ll) * dp[c][1]) % MOD;
				dp[p][2] = ((k - 0ll) * dp[c][0] + (k - 0ll + 1ll) * dp[c][2]) % MOD;
				dp[p][3] = (10ll * dp[c][3] + (9ll - k) * dp[c][2] + (k - 0ll) * dp[c][1]) % MOD;
			}
		} else {
			int k = s[i] - '0';
			if (w[i] == '?') {
				dp[p][0] = dp[c][0];	
				dp[p][1] = ((k - 0ll) * dp[c][0] + (k - 0ll + 1ll) * dp[c][1]) % MOD;
				dp[p][2] = ((9ll - k) * dp[c][0] + (9ll - k + 1ll) * dp[c][2]) % MOD;
				dp[p][3] = (10ll * dp[c][3] + (k - 0ll) * dp[c][2] + (9ll - k) * dp[c][1]) % MOD;
			} else {
				if (s[i] == w[i]) {
					dp[p][0] = dp[c][0];
					dp[p][1] = dp[c][1];
					dp[p][2] = dp[c][2];
					dp[p][3] = dp[c][3];
				} else if (s[i] < w[i]) {
					dp[p][0] = dp[p][1] = 0;
					dp[p][2] = (dp[c][0] + dp[c][2]) % MOD,
					dp[p][3] = (dp[c][3] + dp[c][1]) % MOD;
				} else {
					dp[p][0] = dp[p][2] = 0;
					dp[p][1] = (dp[c][0] + dp[c][1]) % MOD;
					dp[p][3] = (dp[c][3] + dp[c][2]) % MOD;
				}
			}
		}
	}
	cout << dp[p][3] << endl;	

	return 0;
}

//3516548	 Apr 12, 2013 12:30:03 PM	delta_4d	 296B - Yaroslav and Two Strings	 GNU C++	Accepted	 15 ms	 200 KB
