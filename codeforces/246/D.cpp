#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int const N = 1e5 + 10;

char s[N];
int pi[N], cnt[N];
vector <pair<int, int>> out;

int main() {
	scanf("%s", s);
	int n = strlen(s);
	pi[0] = -1;
	for (int i=1,j; i<n; ++i) {
		for (j=pi[i-1]; j>=0&&s[j+1]!=s[i]; j=pi[j]);
		pi[i] = s[j+1] == s[i] ? j + 1 : -1;
		if (pi[i] >= 0) ++cnt[pi[i]];
	}
	cnt[n-1] = 1;
	for (int i=n-1; i>=0; --i) if (pi[i] >= 0) cnt[pi[i]] += cnt[i];
	for (int i=pi[n-1]; i>=0; i=pi[i]) out.push_back(make_pair(i+1, cnt[i]));
	out.push_back(make_pair(n, 1));
	sort(begin(out), end(out));
	printf("%d\n", (int)out.size());
	for (auto &p: out) printf("%d %d\n", p.first, p.second);
	return 0;
}

// 6721842	 May 27, 2014 5:47:35 PM	delta_4d	 D - Prefixes and Suffixes	 GNU C++0x	Accepted	 93 ms	 2900 KB
