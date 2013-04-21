#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 100000 + 86;

vector <pair<int, int> > x;
vector <pair<int, int> > a, b;
int aa[MAXN], bb[MAXN];

int main() {
	int n, k;

	scanf("%d", &n);
	for (int i=0; i<n; ++i) {
		scanf("%d", &k);
		x.push_back(make_pair(k, i));
	}
	sort(x.begin(), x.end());
	int cc = (x[x.size()-1].first * 2 + 2) / 3;
	for (int i=x.size()-1; i>=0; --i) {
		if (x[i].first < cc) {
			cc = (x[i].first * 2 + 2) / 3;	
			if ((n - i) & 1) cc = x[i].first - cc;
		}
		a.push_back(make_pair(cc, x[i].second));	
		b.push_back(make_pair(x[i].first-cc, x[i].second));
		cc = x[i].first - cc;
	}
	for (int i=0; i<n; ++i) aa[a[i].second] = a[i].first;
	for (int i=0; i<n; ++i) bb[b[i].second] = b[i].first;
	puts("YES");
	for (int i=0; i<n; ++i) printf("%d%s", aa[i], i==n-1?"\n":" ");
	for (int i=0; i<n; ++i) printf("%d%s", bb[i], i==n-1?"\n":" ");

	return 0;
}

// 3575118	 Apr 19, 2013 9:23:44 PM	delta_4d	 C - Splitting the Uniqueness	 GNU C++	Accepted	 171 ms	 4400 KB
