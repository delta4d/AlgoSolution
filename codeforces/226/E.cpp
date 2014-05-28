#include <iostream>
using namespace std;

using ll = long long;
int const N = 6;

void mul(ll n, ll x[][N], ll y[][N], ll M) {
	ll t[N][N] = {0};
	for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) {
		for (int k=0; k<n; ++k) t[i][j] = (t[i][j] + x[i][k] * y[k][j]) % M;
	}
	for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) x[i][j] = (t[i][j] + M) % M;
}

void pow(ll n, ll x[][N], ll e, ll M) {
	ll r[N][N] = {0};
	for (int i=0; i<n; ++i) r[i][i] = 1;
	while (e) {
		if (e & 1) mul(n, r, x, M);
		mul(n, x, x, M);
		e >>= 1;
	}
	for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) x[i][j] = (r[i][j] + M) % M;
}

int main() {
	ios_base::sync_with_stdio(false);
	ll n, x, y, dx, dy, t;
	cin >> n >> x >> y >> dx >> dy >> t;
	ll m[N][N] = {
		{2, 1, 1, 0, 1, 2},
		{1, 2, 0, 1, 1, 2},
		{1, 1, 1, 0, 1, 2},
		{1, 1, 0, 1, 1, 2},
		{0, 0, 0, 0, 1, 1},
		{0, 0, 0, 0, 0, 1},
	};
	pow(6, m, t, n);
	ll tx = x - 1, ty = y - 1;
	x = (m[0][0] * tx + m[0][1] * ty + m[0][2] * dx + m[0][3] * dy + m[0][4] * 0 + m[0][5]) % n;
	y = (m[1][0] * tx + m[1][1] * ty + m[1][2] * dx + m[1][3] * dy + m[1][4] * 0 + m[1][5]) % n;
	if (x < 0) x += n;
	if (y < 0) y += n;
	++x, ++y;
	cout << x << " " << y << endl;
	return 0;
}

// 6729047	 May 28, 2014 6:10:06 PM	delta_4d	 E - Bear in the Field	 GNU C++0x	Accepted	15 ms	4 KB
