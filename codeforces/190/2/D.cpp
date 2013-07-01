#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
const int MAXN = 100000 + 86;

struct card {
	ll t, y;
	card(int _t=0, ll _y=0):t(_t), y(_y) {}
	bool operator<(const card &a) const {
		if (t != a.t) return t < a.t;
		return y < a.y;
	}
	void read() {
		char s[5];
		cin >> s >> y;
		t = !(s[0] == 'A');
	}
} a[MAXN];
ll b[MAXN];
bool v[MAXN];
int n, m;

ll gao1() {
	ll ret = 0;
	for (int i=m-1; i>=0; --i) {
		if (m - i > n) return ret;
		ll cc = 0;
		for (int j=0,k=i; k<m; ++j,++k) {
			if (a[j].t) return ret;
			if (a[j].y > b[k]) return ret;
			cc += b[k] - a[j].y;
		}
		ret = max(ret, cc);
	}
	return ret;
}

ll gao2() {
	ll ret = 0;
	if (m <= n) return ret;
	bool ok = true;
	for (int i=0,j=0; i<n; ++i) {
		if (a[i].t == 0) continue;
		for (; j<m&&b[j]<=a[i].y; ++j);
		if (j >= m) {
			ok = false;
			break;
		}
		v[j] = true;
		++j;
	}
	if (!ok) return ret;
	for (int i=0,j=0; i<n; ++i) {
		if (a[i].t == 1) break;
		for (; j<m&&(b[j]<a[i].y||v[j]); ++j);
		if (j >= m) {
			ok = false;
			break;
		}
		++j;
	}
	if (!ok) return ret;
	for (int i=0; i<m; ++i) if (!v[i]) ret += b[i];
	for (int i=0; i<n; ++i) if (a[i].t == 0) ret -= a[i].y;
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for (int i=0; i<n; ++i) a[i].read(); sort(a, a+n);
	for (int i=0; i<m; ++i) cin >> b[i]; sort(b, b+m);
	cout << max(gao1(), gao2()) << endl;
	return 0;
}

// 3989703	 Jun 29, 2013 10:55:47 AM	delta_4d	 B - Ciel and Duel	 GNU C++	Accepted	 15 ms	 2500 KB
