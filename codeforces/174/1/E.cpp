#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;

const int MAXN = 100000 + 86;

inline int LS(const int x) { return x << 1; }
inline int RS(const int x) { return LS(x) ^ 1; }

struct node {
	int one;
	bool flip;

	node(int _one=0, bool _flip=false):one(_one), flip(_flip) {}
} T[MAXN*3];

vector <int> q[MAXN], rq[MAXN];
int s[MAXN];

int bsearch(const int x, const int n) {
	int left = 0, right = n - 1, mid;
	while (left <= right) {
		mid = (left + right) >> 1;
		if (x <= s[mid]) right = mid - 1;
		else left = mid + 1;
	}
	return right + 1;
}

void flip(const int r, const int L, const int R) {
	T[r].flip = !T[r].flip;	
	T[r].one = R - L + 1 - T[r].one;
}

void flip(int r, int a, int b, int L, int R) {
//	cout << r << ' ' << a << ' ' << b << ' ' << L << ' ' << R << endl;
	if (a <= L && R <= b) {
		flip(r, L, R);
		return;
	}	
	int ls = LS(r), rs = RS(r), mid = (L + R) >> 1;
	if (T[r].flip) {
		T[r].flip = false;
		flip(ls, L, mid);
		flip(rs, mid+1, R);
	}
	if (a <= mid) flip(ls, a, b, L, mid);
	if (b > mid) flip(rs, a, b, mid+1, R);
	T[r].one = T[ls].one + T[rs].one;
}

int sum(int r, int a, int b, int L, int R) {
//	cout << r << ' ' << a << ' ' << b << ' ' << L << ' ' << R << endl;
	if (a > b) return 0;
	if (a <= L && R <= b) return T[r].one;	
	int ls = LS(r), rs = RS(r), mid = (L + R) >> 1;
	if (T[r].flip) {
		T[r].flip = false;
		flip(ls, L, mid);
		flip(rs, mid+1, R);
	}
	int tot = 0;
	if (a <= mid) tot += sum(ls, a, b, L, mid);
	if (b > mid) tot += sum(rs, a, b, mid+1, R);
	return tot;
}

int main() {
	int n, k;
	int a, b;
	
	cin >> n >> k;
	for (int i=0; i<n; ++i) cin >> s[i];
	sort(s, s+n);
	for (int i=0; i<k; ++i) {
		cin >> a >> b;
		if (b < s[0] || a > s[n-1]) continue;
		a = bsearch(a, n), b = bsearch(b+1, n) - 1;
		q[a].push_back(b); rq[b].push_back(a);
	}
	LL tot = (LL)n * (n - 1) * (n - 2) / 6;
	for (int i=0; i<n; ++i) {
		for (int j=0; j<(int)q[i].size(); ++j) flip(1, i, q[i][j], 0, n-1);
		int w = i - sum(1, 0, i-1, 0, n-1) + sum(1, i+1, n-1, 0, n-1);	
		tot -= (LL)w * (w - 1) >> 1;
		for (int j=0; j<(int)rq[i].size(); ++j) flip(1, rq[i][j], i, 0, n-1);
	}
	cout << tot << endl;

	return 0;
}

// 3359369	 Mar 20, 2013 9:08:59 AM	delta_4d	 283E - Cow Tennis Tournament	 GNU C++	Accepted	718 ms	7200 KB
