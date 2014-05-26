#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <unordered_map>
using namespace std;

int const N = 1e6 + 100;
using ll = long long;

int p[N], R[N], L[N];
bool v[N];
int nl[N], nr[N];
unordered_map <int, int> mp;
vector <pair <int, int>> rm;

struct BIT {
	int x[N+10], n;

	BIT(int n=N):n(n) {
		memset(x, 0, sizeof(x));
	}

	void add(int off, int p) {
		for (int i=p; i<n; i+=i&-i) x[i] += off;
	}

	int sum(int p) {
		int ret = 0;
		for (int i=p; i>0; i-=i&-i) ret += x[i];
		return ret;
	}
} T;

int main() {
	int n, k;
	ll tot = 0;
	scanf("%d%d", &n, &k);
	for (int i=1; i<=n; ++i) scanf("%d", p+i), mp[p[i]] = i;
	for (int i=0,c; i<k; ++i) scanf("%d", &c), mp.erase(mp.find(c));
	for (auto &c: mp) rm.push_back(c), v[c.second] = true;
	nr[n+1] = -1; for (int i=n; i>0; --i) nr[i] = v[i] ? max(i, nr[i+1]) : -1;
	nl[0] = n + 1; for (int i=1; i<=n; ++i) nl[i] = v[i] ? min(i, nl[i-1]) : n + 1;
	for (int i=1; i<=n; ++i) T.add(1, i);
	sort(begin(rm), end(rm));
	R[n] = n+1; for (int i=n-1,j; i>0; R[i--]=j) for (j=i+1; j<=n&&(v[j]||p[j]>=p[i]); j=v[j]?nr[j]+1:R[j]);
	L[1] = 0; for (int i=2,j; i<=n; L[i++]=j) for (j=i-1; j>0&&(v[j]||p[j]>=p[i]); j=v[j]?nl[j]-1:L[j]);
	for (auto &c: rm) {
		int i = c.second, cc = T.sum(R[i]-1) - T.sum(L[i]);
		tot += cc;
		T.add(-1, i);
//		printf("%d %d [%d, %d]\n", i, cc, L[i]+1, R[i]-1);
	}
	printf("%I64d\n", tot);
	return 0;
}

// 6573495	 May 8, 2014 8:37:57 PM	delta_4d	 E - George and Cards	 GNU C++0x	Accepted	 763 ms	 65900 KB
