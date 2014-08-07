#include <bits/stdc++.h>
using namespace std;

int const N = 1e5 + 10;
struct Q {
	int l, r, x;
	Q(int _l=0, int _r=0, int _x=0):l(_l), r(_r), x(_x) {}
	bool operator<(const Q &rhs) const {
		return r < rhs.r;
	}
};
struct BIT {
	int n;
	vector <int> x;
	BIT(int _n=N):n(_n), x(_n, 0) {}
	void add(int p, int o) {
		for (int i=p; i<n; i+=i&-i) x[i] += o;
	}
	int sum(int p) {
		int ret = 0;
		for (int i=p; i>0; i-=i&-i) ret += x[i];
		return ret;
	}
} T1, T2;
int a[N], o[N], last[N], v[N], d[N];
vector <Q> query;

int main() {
	int n, q;
	scanf("%d", &n);
	memset(v, -1, sizeof(v));
	for (int i=0; i<n; ++i) {
		scanf("%d", a+i);
		last[i] = v[a[i]], v[a[i]] = i;
	}
	scanf("%d", &q);
	for (int i=0,l,r; i<q; ++i) {
		scanf("%d%d", &l, &r), --l, --r;
		query.push_back({l, r, i});
	}
	memset(d, -1, sizeof(d));
	sort(begin(query), end(query));
	for (int i=0,k=0; i<q; ++i) {
		int l = query[i].l, r = query[i].r, x = query[i].x;
		for (; k<=r; ++k) {
			int j = last[k];
			T1.add(k+1, 1);
			if (j != -1) T1.add(j+1, -1);
			if (j != -1) {
				int step = k - j;
				if (last[j] != -1) {
					if (step != j - last[j]) {
						T2.add(last[j]+1, 1);
						if (d[a[k]] != -1) T2.add(d[a[k]]+1, -1);
						d[a[k]] = last[j];
					}
				}
			}
		}
		int diff_num = T1.sum(r+1) - T1.sum(l), diff_step = T2.sum(r+1) - T2.sum(l);
		o[x] = diff_num + (diff_num == diff_step);
	}
	for (int i=0; i<q; ++i) printf("%d\n", o[i]);
	return 0;
}

// 7364960	2014-08-07 09:37:10	delta_4d	D - Jeff and Removing Periods	GNU C++0x	Accepted	186 ms	5300 KB
