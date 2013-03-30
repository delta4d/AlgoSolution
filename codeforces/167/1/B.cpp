#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;
typedef pair <int, int> PII;
typedef vector <PII> VPII;
#define MP(x, y) make_pair((x), (y))

const int MAXN = 100000 + 86;

VPII x;
LL r[MAXN<<1], cc[MAXN<<1];

inline LL P(LL x, LL e, const LL m) {
	LL ret = 1;
	while (e) {
		if (e & 1) ret = ret * x % m;
		x = x * x % m;
		e >>= 1;
	}
	return ret;
}

void init(const LL n, const LL m) {
	for (LL c=1,i=1; i<=n; ++i) {
		LL k = i;
		for (; k%2==0; ++cc[i],k>>=1);
		c = r[i] = c * k % m;
		cc[i] += cc[i-1];
	}	
}

int main() {
	LL tot = 1;
	LL n, m;

	cin >> n;
	for (int i=0; i<2*n; ++i) {
		int a;
		cin >> a;
		x.push_back(MP(a, i%n));
	}
	sort(x.begin(), x.end());
	cin >> m;
	init(2*n+10, m);
	for (int i=0,j=0,sz=(int)x.size(); i<sz; i=j) {
		int p2 = 0;
		for (j=i; j<sz&&x[j].first==x[i].first; ++j) p2 += (j + 1 < sz && x[j+1] == x[j]);
//		cout << x[i].first << ' ' << j - i << ' ' << p2 << ' ' << r[j-i] << ' ' << cc[j-i] << endl;
		tot = (tot * r[j-i] % m) * P(2, cc[j-i]-p2, m) % m;
	}
	cout << tot << endl;

	return 0;
}

// 3379071	 Mar 22, 2013 12:49:25 PM	delta_4d	 273B - Dima and Two Sequences	 GNU C++	Accepted	375 ms	6800 KB
