#include <set>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

typedef set<int> SI;
typedef vector<int> VI;

const int INF = 0x3f3f3f3f;

SI p;
VI s1, s2;
int f[34], n;
int cnt;
bool visit[34];

inline int abs(const int x) {
	return x > 0 ? x : -x;
}

void dfs(int d, int a, int b, int len, int sum, int tot, VI &s) {
	int i, j, k;
	if (d > len) return;
	k = abs(tot-(sum<<1));
	if (p.find(k) == p.end()) {
		p.insert(k);
		s.push_back(k);
	}
	for (i=a; i<b; ++i) {
		if (!visit[i]) {
			visit[i] = true;
			dfs(d+1, i+1, b, len, sum+f[i], tot, s);
			visit[i] = false;
		}
	}
}

void gao(int a, int b, VI &s, bool haha) {
	int i, j, k;
	int tot(0);
	for (i=a; i<b; ++i) tot += f[i];
	p.clear();
	s.clear();
	cnt = 0;
	memset(visit, false, sizeof(visit));
	dfs(0, a, b, (b-a)>>1, 0, tot, s);
	if (haha) sort(s.begin(), s.end());
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
		for (k=-1; k<=1; ++k) {
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
	//freopen("f:\\in.txt", "r", stdin);
	//freopen("f:\\out.txt", "w", stdout);
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d", &n);
		for (i=0; i<n; ++i) scanf("%d", f+i);
		gao(0, n>>1, s1, false);
		gao(n>>1, n, s2, true);
		printf("%d\n", find_diff());
	}
	return 0;
}