#include <bits/stdc++.h>
using namespace std;

int const N = 1 << 11;

char buf[N];
struct BigInt {
	int d[N], n;

	void readin() {
		scanf("%s", buf);
		n = (int)strlen(buf);
		for (int i=0; i<n; ++i) d[i] = buf[n-1-i] - '0';
	}

	void writeout() {
		for (int i=0; i<n; ++i) printf("%d", d[n-1-i]);
		puts("");
	}

	void div2() {
		for (int i=n-1,cc=0; i>=0; --i) {
			cc = cc * 10 + d[i];
			d[i] = cc >> 1, cc &= 1;
		}
		if (!d[n-1]) --n;
	}

	void minus(int y) {
		d[0] -= y;
		for (int i=0; i<n; ++i) {
			if (d[i] < 0) d[i] += 10, --d[i+1];
		}
		if (!d[n-1]) --n;
	}

	bool odd() {
		return d[0] & 1;
	}
} x;

int main() {
#ifdef ONLINE_JUDGE
	freopen("china.in", "r", stdin);
	freopen("china.out", "w", stdout);
#endif
	x.readin();
	if (x.odd()) {
		x.div2();
	} else {
		x.div2();
		if (x.odd()) x.minus(2);
		else x.minus(1);
	}
	x.writeout();
	return 0;
}

// 6958851	 2014-06-25 20:10:31	delta_4d	 A - Chinese Girls' Amusement	 GNU C++0x	Accepted	60 ms	196 KB
