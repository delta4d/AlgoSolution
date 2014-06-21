#include <bits/stdc++.h>
using namespace std;

int const N = 1e6 + 100;

struct T {
	int mx1, mx2, from1, from2;
	T(int mx1=0, int mx2=0, int f1=0, int f2=0):mx1(mx1), mx2(mx2), from1(f1), from2(f2) {}
	T upd(int k, const T &a) {
		int x1 = mx1, x2 = mx2, f1 = from1, f2 = from2, x = max(a.mx1, a.mx2+1);
		if (x > x1) x2 = x1, f2 = f1, x1 = x, f1 = k;
		else if (x > x2 && f1 != k) x2 = x, f2 = k;
		return T(x1, x2, f1, f2);
	}
	bool operator==(const T &rhs) const {
		return mx1 == rhs.mx1 && mx2 == rhs.mx2;
	}
} f[N];
int p[N];

void upd(int x) {
	if (x == 1) return;
	int y = p[x];
	T cc = f[y].upd(x, f[x]);
	if (f[y] == cc) return;
	f[y] = cc;
	upd(y);
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i=2,c; i<=n+1; ++i) {
		scanf("%d", &c);
		p[i] = c;
		upd(i);
		printf("%d ", f[1].mx1);
	}
	return 0;
}

// 6935577	 2014-06-21 12:09:58	delta_4d	 D - Adam and Tree	 GNU C++0x	Accepted	 530 ms	 50800 KB
