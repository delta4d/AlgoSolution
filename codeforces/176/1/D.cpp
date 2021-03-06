#include <map>
#include <set>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 200000 + 86;

#define MP(x, y) make_pair((x), (y))
#define PB push_back
#define F first
#define S second
#define SZ(x) ((int)x.size())

typedef long long LL;
typedef pair <int, bool> PIB;
typedef multimap <int, PIB> MMIP;
typedef MMIP::iterator MMIPI;
typedef multiset <int> MI;

MMIP seg;
MI T;
int sz=1;
int L[MAXN], R[MAXN], sl[MAXN], sr[MAXN];

int main() {
	int n, m;
	int l, r, t;

	scanf("%d%d", &n, &m);
	for (int i=0; i<m; ++i) {
		scanf("%d%d%d", &l, &r, &t);	
		seg.insert(MP(l, MP(t, true)));
		seg.insert(MP(r, MP(t, false)));
	}
	int pre = -1;
	for (MMIPI it=seg.begin(); it!=seg.end(); ++it) {
		int cc = it->F;
		if (pre != -1 && pre != cc && SZ(T))	{
			int t = *T.begin();	
			L[sz] = t - pre, R[sz++] = t - cc;
		}
		pre = cc;
		if (it->S.S) T.insert(it->S.F);
		else T.erase(T.lower_bound(it->S.F));
	}
	sort(L+1, L+sz);
	sort(R+1, R+sz);
	for (int i=1; i<sz; ++i) sl[i] = sl[i-1] + L[i], sr[i] = sr[i-1] + R[i];
	
//	for (int i=0; i<sz; ++i) printf("%d ", L[i]); puts("");
//	for (int i=0; i<sz; ++i) printf("%d ", R[i]); puts("");

	int q;
	while (n--) {
		scanf("%d", &q);
		l = lower_bound(L+1, L+sz, q) - L - 1;
		r = lower_bound(R+1, R+sz, q) - R - 1;
//		printf("L: %d R: %d\n", l, r);
		int tot = (LL)(r - l) * q - (LL)sr[r] + sl[l];
		printf("%d\n", tot);
	}

	return 0;
}

// 3404376	 Mar 25, 2013 5:21:56 PM	delta_4d	 286D - Tourists	 GNU C++	Accepted	375 ms	14300 KB
