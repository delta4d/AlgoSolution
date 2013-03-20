#include <map>
#include <set>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

struct node {
	int x, y, c;
	node() {}
	node(int _x, int _y, int _c):x(_x), y(_y), c(_c) {} 
};

vector<node> e;
map<int, int> mp;
vector<int> rv;
set<int> used;
bool cc[8086];

inline void init() {
	e.clear();
	mp.clear();
	rv.clear();
	used.clear();
}

inline void insert(const int x) {
	if (used.find(x) == used.end()) {
		used.insert(x);
		rv.push_back(x);
	}
}

int main() {
	int i, j, k;
	int m, n;
	int x, y;
	int mx;
	int tot, left, right, L, R;
	char c[2];
	
	while (1 == scanf("%d", &n)) {
		init();
		for (i=0; i<n; ++i) {
			scanf("%d %d %s", &x, &y, c);
			e.push_back(node(x, y, c[0]=='w'));
			insert(x);
			insert(y);
		}
		sort(rv.begin(), rv.end());
		for (i=0,mx=rv.size(); i<mx; ++i) if (i>0&&rv[i]>rv[i-1]+1) rv.push_back(rv[i-1]+1);
		sort(rv.begin(), rv.end());
		for (i=0,mx=rv.size(); i<mx; ++i) mp[rv[i]] = i;
		memset(cc, false, sizeof(cc));
		for (i=0; i<e.size(); ++i) {
			x = mp[e[i].x], y = mp[e[i].y];
			for (j=x; j<=y; ++j) cc[j] = e[j].c;
		}
		for (left=tot=-1,i=0; i<mx; ++i) {
			if (cc[i]) {
				if (left == -1) left = i;
				right = i;
			} else {
				right = i;
				if (rv[right] - rv[left] > tot) {
					L = rv[left], R = rv[right], tot = L - R;
				}
				left = -1;
			}
		}
		if (left != -1) if (rv[right] - rv[left] + 1 > tot) {
			L = rv[left], R = rv[right], tot = L - R + 1;
		}
		if (tot != -1) printf("%d %d\n", L, R);
		else puts("Oh, my god");
	}	
	
	return 0;
}