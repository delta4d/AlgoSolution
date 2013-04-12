#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;

const LL MAXN = 512;

LL t[MAXN][MAXN];
LL out[MAXN];
int x[MAXN];

int main() {
	ios_base::sync_with_stdio(false);

	int n;

	cin >> n;
	for (int i=1; i<=n; ++i) {
		for (int j=1; j<=n; ++j) {
			cin >> t[i][j];
		}
	}
	for (int i=1; i<=n; ++i) cin >> x[i];
	for (int k=n; k>=1; --k) {
		int c = x[k];
		for (int i=k+1; i<=n; ++i) {
			int a = x[i];
			for (int j=k; j<=n; ++j) {
				int b = x[j];
				t[c][a] = min(t[c][a], t[c][b] + t[b][a]);
				t[a][c] = min(t[a][c], t[a][b] + t[b][c]);
			}
		}
		for (int i=k; i<=n; ++i) {
			int a = x[i];
			for (int j=k; j<=n; ++j) {
				int b = x[j];
				if (a == b) continue;
				t[a][b] = min(t[a][b], t[a][c] + t[c][b]);
			}
		}	
		for (int i=k; i<=n; ++i) {
			int a = x[i];
			for (int j=k; j<=n; ++j) {
				int b = x[j];
				out[k] += t[a][b];
			}
		}
	}
	for (int i=1; i<=n; ++i) {
		cout << out[i];
		if (i == n) cout << endl;
		else cout << ' ';
	}

	return 0;
}

// 3511005	 Apr 11, 2013 8:57:10 PM	delta_4d	 295B - Greg and Graph	 GNU C++	Accepted	 1140 ms	 2100 KB
