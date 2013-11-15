#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;

const int INF = 0x3f3f3f3f;

struct segment {
	int x1, y1;
	int x2, y2;
	int xmin, xmax;
	int ymin, ymax;
	
	void input() {
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		xmin = min(x1, x2);
		xmax = max(x1, x2);
		ymin = min(y1, y2);
		ymax = max(y1, y2);
	}
	
	bool intersect(segment &a) {
		return ymin <= a.y1 && a.y1 <= ymax && a.xmin <= x1 && x1 <= a.xmax;
	}
	
	bool vertical() {
		return x1 == x2;
	}
} tt;

vector<segment> h;
vector<segment> v;

int main() {
	int i, j, k;
	int ii, jj, kk;
	int m, n;
	int tc;
	int tot;
	int nv, nh;
	
	//freopen("c:\\in.txt", "r", stdin);
	
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d", &n);
		h.clear();
		v.clear();
		for (i=0; i<n; ++i) {
			tt.input();
			if (tt.vertical()) v.push_back(tt);
			else h.push_back(tt);
		}
		tot = 0;
		nv = v.size();
		nh = h.size();
		for (i=0; i<nv; ++i) {
			for (j=i+1; j<nv; ++j) {
				for (ii=0; ii<nh; ++ii) {
					for (jj=ii+1; jj<nh; ++jj) {
						tot += v[i].intersect(h[ii]) && v[i].intersect(h[jj]) && v[j].intersect(h[ii]) && v[j].intersect(h[jj]);
					}
				}
			}
		}
		printf("%d\n", tot);
	}

	return 0;
}