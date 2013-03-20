#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 0x6fffffff;

struct node {
	int x, y;
	bool mark;
	
	node() {}
	node(int _x, int _y, bool _mark):x(_x), y(_y), mark(_mark) {}
};

vector<node> f;
vector<pair<int, int> > out;

inline bool cmp(const node &a, const node &b) {
	if (a.y != b.y) return a.y > b.y;
	if (a.x != b.x) return a.x < b.x;
	return a.mark;
}

int main() {
	int i, j, k;
	int m, n;
	int x, y;
	
	while (2 == scanf("%d %d", &n, &m)) {
		f.clear();
		for (i=0; i<n+m; ++i) {
			scanf("%d %d", &x, &y);
			if (i < n) f.push_back(node(x, y, false));
			else f.push_back(node(x, y, true));
		}
		sort(f.begin(), f.end(), cmp);
		out.clear();
		x = INF;
		for (i=0; i<n+m; ++i) {
			if (f[i].mark) {
				x = min(x, f[i].x);
			} else {
				if (f[i].x < x) out.push_back(make_pair(f[i].x, f[i].y));
			}
		}
		printf("%d\n", out.size());
		sort(out.begin(), out.end());
		for (i=0; i<out.size(); ++i) printf("%d %d\n", out[i].first, out[i].second);
	}
	
	return 0;
}