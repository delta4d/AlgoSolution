#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 200000 + 86;

typedef long long LL;

LL x[MAXN], c[MAXN];

int main() {
	int n, q;
	int L, R;
	LL tot = 0;

	cin >> n >> q;
	
	for (int i=1; i<=n; ++i) cin >> x[i];
	for (int i=0; i<q; ++i) cin >> L >> R, --c[L-1], ++c[R];
	for (int i=n-1; i>0; --i) c[i] += c[i+1];
	sort(x+1, x+n+1);
	sort(c+1, c+n+1);
	for (int i=1; i<=n; ++i) tot += c[i] * x[i];
	cout << tot << endl;

	return 0;
}

// 3299018	 Mar 13, 2013 6:16:38 PM	delta_4d	 276C - Little Girl and Maximum Sum	 GNU C++	Accepted	750 ms	3100 KB
