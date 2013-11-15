#include <set>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;

set<int> p;
vector<int> s1, s2;
int n, f[34];
bool visit[34];

inline int abs(const int x) {
	return x > 0 ? x : -x;
}

void dfs(int d, const int x, const int y, const int len, int sum, int tot, vector<int> &s) {
	int i, j, k;
	if (d == len) {
		k = abs(tot-(sum<<1));
		if (p.find(k) == p.end()) {
			//printf("######  %d\n", k);
			//for (i=0; i<n; ++i) if (visit[i]) printf("%d ", i); puts("");
			p.insert(k);
			s.push_back(k);
		}
		return;
	}
	for (i=x; i<y; ++i) {
		if (!visit[i]) {
			visit[i] = true;
			dfs(d+1, x, y, len, sum+f[i], tot, s);
			visit[i] = false;
		}
	}
}

void gao(int x, int y, vector<int> &s) {
	int i, j, k((y-x)>>1);
	int tot(0);
	p.clear();
	s.clear();
	for (i=x; i<y; ++i) tot += f[i];
	for (i=0; i<=k; ++i) {
		memset(visit, false, sizeof(visit));
		dfs(0, x, y, i, 0, tot, s);
	}
	sort(s.begin(), s.end());
}

inline int find_diff() {
	int i, j, k;
	int left, right, mid;
	int diff;
	diff = INF;
	for (i=0; i!=s1.size(); ++i) {
		left = 0, right = s2.size() - 1;
		while (left <= right) {
			mid = (left + right) >> 1;
			if (s2[mid] <= s1[i]) left = mid + 1;
			else right = mid - 1;
		}
		for (k=-2; k<=2; ++k) {
			j = k + mid;
			if (j >= 0 && j < s2.size()) {
				diff = min(diff, abs(s1[i]-s2[j]));
				if (diff == 0) return 0;
			}
		}
	}
	return diff;
}

int main() {
	int i, j, k;
	int tc;
	int tot;
	freopen("f:\\in.txt", "r", stdin);
	//freopen("f:\\out.txt", "w", stdout);
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d", &n);
		for (i=0; i<n; ++i) scanf("%d", f+i);
		if (n > 1) {
			gao(0, n>>1, s1);
			gao(n>>1, n, s2);
			printf("%d\n", find_diff());
		} else {
			printf("%d\n", f[0]);
		}
	}
	return 0;
}