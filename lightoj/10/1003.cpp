#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 20000 + 86;
#define ID(x) (lower_bound(vs.begin(), vs.end(), (x))-vs.begin())

vector <string> vs;
vector <int> e[N];
string f[N][2];
int v[N];
bool ok;

void gao(int x, int tag) {
	if (!ok) return;
	v[x] = tag;
	for (int i=0; ok&&i<(int)e[x].size(); ++i) {
		int y = e[x][i];
		if (v[y] == tag) {
			ok = false;
			break;
		}
		gao(y, tag);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	int tc, cn = 0, n, m;
	for (cin>>tc; tc--; ) {
		vs.clear();
		cin >> m;
		for (int i=0; i<m; ++i) {
			cin >> f[i][0] >> f[i][1];
			vs.push_back(f[i][0]);
			vs.push_back(f[i][1]);
		}
		sort(vs.begin(), vs.end());
		vs.erase(unique(vs.begin(), vs.end()), vs.end());
		n = (int)vs.size();
		for (int i=0; i<n; ++i) e[i].clear();
		for (int i=0; i<m; ++i) e[ID(f[i][0])].push_back(ID(f[i][1]));
		fill(v, v+n, -1);
		ok = true;
		for (int i=0; ok&&i<n; ++i) if (v[i] == -1) gao(i, i);
		cout << "Case " << ++cn << ": " << (ok ? "Yes" : "No") << endl;
	}
	return 0;
}

// 294657	2013-12-02 21:06:49	 1003 - Drunk	 C++	 0.128	 4144	Accepted
