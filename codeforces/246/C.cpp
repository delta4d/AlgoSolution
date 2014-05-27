#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int const N = 1e5 + 10;
using pii = pair <int, int>;
vector <pii> a, op;
vector <int> p;
int f[N], ed[N], c[N];
bool isp[N];

void init() {
	for (int i=2; i<N; ++i) if (!isp[i]) {
		p.push_back(i);
		for (int j=i<<1; j<N; j+=i) isp[j] = true;
	}
	for (int i=2; i<N; ++i) {
		if (!isp[i]) {
			f[i] = i;
		} else {
			for (int j=0; j<(int)p.size()&&p[j]<i; ++j) {
				if (!isp[p[j]] && !isp[i-p[j]]) {
					f[i] = p[j];
					break;
				}
			}
		}
	}
//	puts("done");
}

int main() {
	init();
	int n;
	scanf("%d", &n);
	for (int i=0,k; i<n; ++i) {
		scanf("%d", &k);
		a.push_back(make_pair(k, i));
		c[i] = i;
	}
	stable_sort(begin(a), end(a));
	for (int i=0; i<n; ++i) ed[a[i].second] = i;
	for (bool ff=true; ff; ) {
		ff = false;
		for (int i=0; i<n; ++i) if (ed[c[i]] != i) {
			int x = i, y = ed[c[i]];
			if (x > y) swap(x, y);
			ff = true;
			int d = y - x + 1;
			if (!isp[d]) {
				op.push_back(make_pair(x+1, y+1));
				swap(c[x], c[y]);
			} else {
				auto mv = [&](int &x, int &y) {
					op.push_back(make_pair(x+1, y+1));
					swap(c[x], c[y]);
					swap(x, y);
				};
				int t1 = x + f[d] - 1, t2 = t1 + 1;
				if (!f[d]) t1 = x + f[d-1] - 1, t2 = t1 + 2;
				mv(x, t1), mv(x, t2), mv(x, y), mv(t2, y), mv(t1, y);
			}
		}
	}
	printf("%d\n", (int)op.size());
	for (auto &p: op) printf("%d %d\n", p.first, p.second);
	return 0;
}

// 6721553	 May 27, 2014 5:02:49 PM	delta_4d	 C - Prime Swaps	 GNU C++0x	Accepted	 467 ms	 9100 KB
