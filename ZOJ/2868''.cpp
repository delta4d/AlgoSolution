#include <set>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef vector<int> VI;
typedef set<int> SI;
typedef SI::iterator SII;

const int INF = 0x3f3f3f3f;

int f[34];
SI s, temp;
VI v1, v2;

inline int abs(const int x) {
	return x >= 0 ? x : -x;
}

void gao(int x, int y, VI &v) {
	int i, j, k;
	SII it;
	v.clear();
	s.clear();
	s.insert(0);
	for (i=x; i<y; ++i) {
		temp.clear();
		for (it=s.begin(); it!=s.end(); ++it) {
			temp.insert((*it)+f[i]);
			temp.insert(abs(f[i]-(*it)));
		}
		s = temp;
	}
	for (it=s.begin(); it!=s.end(); ++it) v.push_back(*it);
}

int find_diff() {
	int i, j, k;
	int left, right, mid;
	int diff;
	diff = INF;
	for (i=0; i!=v1.size(); ++i) {
		left = 0, right = v2.size() - 1;
		while (left <= right) {
			mid = (left + right) >> 1;
			if (v2[mid] <= v1[i]) left = mid + 1;
			else right = mid - 1;
		}
		for (k=-1; k<=1; ++k) {
			j = k + mid;
			if (j >= 0 && j < v2.size()) {
				diff = min(diff, abs(v1[i]-v2[j]));
				if (diff == 0) return 0;
			}
		}
	}
	return diff;
}

int main() {
	int tc;
	int m, n;
	int i, j, k;
	//freopen("f:\\in.txt", "r", stdin);
	//freopen("f:\\out.txt", "w", stdout);
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d", &n);
		for (i=0; i<n; ++i) scanf("%d", f+i);
		gao(0, n>>1, v1);
		gao(n>>1, n, v2);
		printf("%d\n", find_diff());
	}
	return 0;
}