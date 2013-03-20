#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;
typedef vector <LL> VLL;
typedef map <LL, VLL> MLV;

const int MAXN = 200000 + 86;
const LL INF = 0x3f3f3f3f;

int n;
MLV mp[2];
LL f[MAXN][2];
bool v[MAXN][2];
LL a[MAXN];


void dfs(LL x, LL y, LL op) {
	if (v[x][op]) return; 			
	v[x][op] = true;
	f[x][op] = y;
	LL np = op ^ 1;
	for (int i=0; i<(int)mp[np][x].size(); ++i) {
		LL tx = mp[np][x][i];
		dfs(tx, y+a[tx], np);
	}
}

int main() {

	cin >> n;
	for (int i=2; i<=n; ++i) {
		cin >> a[i];
		mp[0][i+a[i]].push_back(i);
		mp[1][i-a[i]].push_back(i);
		f[i][0] = f[i][1] = INF;
	}
	for (int i=2; i<=n; ++i) {
		if (i - a[i] <= 0) dfs(i, a[i], 1);
		if (i + a[i] > n) dfs(i, a[i], 0);
	}
//	for (int i=2; i<=n; ++i) cout << i << ": " << f[i][0] << ' ' << f[i][1] << endl;
	for (int i=1; i<n; ++i) {
		if (f[i+1][1] == INF) cout << -1 << endl;
		else cout << f[i+1][1] + i << endl;
	}

	return 0;
}

// 3351935	 Mar 18, 2013 6:02:22 PM	delta_4d	 283B - Cow Program	 GNU C++	Accepted	 1156 ms	 64200 KB
