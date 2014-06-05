#include <cstdio>
#include <vector>
#include <unordered_set>
using namespace std;

unordered_set <int> e[30];
vector <int> o;
bool ok;

bool _dfs(int n) {
	if (!e[n].empty()) {
		o.push_back(*e[n].begin());
		e[n].erase(e[n].begin());
		return true;
	}
	if (!n) {
		if (e[n].empty()) return false;
		o.push_back(*e[n].begin());
		e[n].erase(e[n].begin());
		return true;
	}
	return _dfs(n-1) && _dfs(n-1);
}

void dfs(int n) {
	if (!n) {
		ok = true;
		return;
	}
	if (!_dfs(__builtin_ctz(n))) return;
	dfs(n&(n-1));
}

int main() {
	int s, n;
	scanf("%d%d", &s, &n);
	for (int i=1; i<=n; ++i) e[__builtin_ctz(i)].insert(i);
	dfs(s);
	if (!ok) return puts("-1"), 0;
	printf("%d\n", (int)o.size());
	for (auto c: o) printf("%d ", c);
	return 0;
}

// 6779147	 2014-06-02 08:28:29	delta_4d	 B - The Child and Set	 GNU C++0x	Accepted	 31 ms	 2400 KB
