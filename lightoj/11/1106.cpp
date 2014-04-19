#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 30;
const int T = 16 * 60 / 5 + 86;

vector <int> tr[N][T];
int dp[N][T], p[N][T];
int f[N], d[N], t[N];
int n, h;

bool L(vector<int> &a, vector<int> &b) {
	for (int i=0; i<(int)a.size(); ++i) if (a[i] != b[i]) return a[i] > b[i];
	return false;
}

int main() {
	int tc, cn = 0;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d%d", &n, &h);
		h *= 12;
		for (int i=0; i<n; ++i) scanf("%d", f+i);
		for (int i=0; i<n; ++i) scanf("%d", d+i);
		for (int i=0; i+1<n; ++i) scanf("%d", t+i);
		for (int i=0; i<n; ++i) for (int j=0; j<=h; ++j) tr[i][j]=vector<int>(n, 0);
		memset(dp, -1, sizeof(dp));
		for (int i=0,sum=0,rem=f[0]; i<=h; ++i,sum+=rem,rem=max(0,rem-d[0])) {
			dp[0][i] = sum;
			tr[0][i][0] = i;
		}
		for (int i=1; i<n; ++i) {
			int co = t[i-1];
			for (int j=0; j<=h; ++j) {
				for (int k=0,sum=0,rem=f[i]; k+co<=j; ++k,sum+=rem,rem=max(0,rem-d[i])) {
					if (dp[i-1][j-k-co] == -1) continue;
					int cc = dp[i-1][j-k-co] + sum;
					vector<int> tmp = tr[i-1][j-k-co];
					tmp[i] = k;
					if (dp[i][j] < cc || dp[i][j] == cc && L(tmp, tr[i][j])) {
						dp[i][j] = cc;
						tr[i][j] = tmp;
					}
				}
			}
		}
		int mx = 0;
		vector <int> out(n, 0);
		for (int i=0; i<n; ++i) {
			if (dp[i][h] > mx || dp[i][h] == mx && L(tr[i][h], out)) {
				mx = dp[i][h];
				out = tr[i][h];
			}
		}
		printf("Case %d:\n", ++cn);
		for (int i=0; i<n; ++i) printf("%d%s", out[i]*5, i==n-1?"\n":", ");
		printf("Number of fish expected: %d\n", mx);
	}
	return 0;
}

// 297328	2013-12-09 23:57:13	 1106 - Gone Fishing	 C++	 0.044	 1904	Accepted
