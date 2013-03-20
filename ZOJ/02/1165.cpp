#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

bool visit[333][333];

struct node {
	int x, y;

	node(int _x=0, int _y=0):x(_x), y(_y) {}
} p[333];

vector <vector<int> > res;

inline bool cmp(const node &a, const node &b) {
	if (a.x != b.x) return a.x < b.x;
	return a.y < b.y;
}

int xmult(const node &p0, const node &p1, const node &p2) {
	return (p1.x - p0.x) * (p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y);
}

bool gao(int i, int j, int k) {
	return xmult(p[i], p[j], p[k]) == 0;
}

int main() {
	int i, j, k;
	int n;
	
//	freopen("d:\\in.txt", "r", stdin);
	while (scanf("%d %d", &p[0].x, &p[0].y), p[0].x||p[0].y) {
		n = 0;
		while (p[n].x||p[n].y) {
			++n;
			scanf("%d %d", &p[n].x, &p[n].y);
		}
		sort(p, p+n, cmp);
		memset(visit, false, sizeof(visit));
		res.clear();
//		for (i=0; i<n; ++i) printf("%d %d\n", p[i].x, p[i].y);
		for (i=0; i<n; ++i) for (j=i+1; j<n; ++j) {
			if (visit[i][j]) continue;
			vector <int> out;
			out.push_back(i); out.push_back(j);
			for (k=j+1; k<n; ++k) if (gao(i, j, k)) {
				for (int t=0; t<out.size(); ++t) visit[out[t]][k] = true;
				out.push_back(k);
			}
			if (out.size() > 2) res.push_back(out);
		}
		if (res.size()) {
			puts("The following lines were found:");
			for (i=0; i<res.size(); ++i) {
				for (j=0; j<res[i].size(); ++j) {
					printf("(%4d,%4d)%s", p[res[i][j]].x, p[res[i][j]].y, j==res[i].size()-1?"\n":"");
				}
			}
		} else {
			puts("No lines were found");
		}
	}
	return 0;
}