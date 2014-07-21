#include <bits/stdc++.h>
using namespace std;

int const N = 1e5 + 10;
using ll = long long;
ll const INF = 0x3f3f3f3f3f3f3f3fll;

struct edge {
	ll to, cost, id;
	edge(ll to=0, ll cost=0, ll id=0):to(to), cost(cost), id(id) {}
};

vector <edge> e[N];
ll d[N];
vector <ll> p[N];
ll n, m, k;
queue <ll> q;
bool inq[N];
bool v[N];
bool can_change[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> m >> k;
	for (ll i=0,u,v,w; i<m; ++i) {
		cin >> u >> v >> w;
		e[u].push_back(edge(v, w, i+1));
		e[v].push_back(edge(u, w, i+1));
	}
	for (ll i=0,s,y; i<k; ++i) {
		cin >> s >> y;
		e[1].push_back(edge(s, y, m+i+1));
		e[s].push_back(edge(1, y, m+i+1));
	}
	memset(d, 0x3f, sizeof(d));
	memset(can_change, true, sizeof(can_change));
	d[1] = 0;
	q.push(1);
	inq[1] = true;
	while (!q.empty()) {
		ll x = q.front(); q.pop();
		inq[x] = false;
		for (auto &ed: e[x]) {
			ll y = ed.to, w = ed.cost, id = ed.id;
			if (d[y] > d[x] + w) {
				d[y] = d[x] + w;
				p[y].clear();
				if (id > m) {
					can_change[y] = true;
					p[y].push_back(id);
				} else {
					can_change[y] = false;
				}
				if (!inq[y]) {
					inq[y] = true;
					q.push(y);
				}
			} else if (d[y] == d[x] + w) {
				if (id > m) {
					if (can_change[y]) p[y].push_back(id);
				} else {
					can_change[y] = false;
					p[y].clear();
				}
			}
		}
	}
//	for (ll i=1; i<=n; ++i) cout << d[i] << " "; cout << endl;
	for (ll i=1; i<=n; ++i) if (!p[i].empty()) {
		bool skip = false;
		for (auto id: p[i]) {
			if (v[id-m]) {
				skip = true;
				break;
			}
		}
		if (!skip) v[p[i].front()-m] = true;
	}
	ll cnt = 0;
//	for (ll i=1; i<=k; ++i) if (!v[i]) cout << m+i << " "; cout << endl;
	for (ll i=1; i<=k; ++i) if (!v[i]) ++cnt;
	cout << cnt << endl;
	return 0;
}

// 7171643	2014-07-19 18:42:30	delta_4d	B - Jzzhu and Cities	GNU C++0x	Accepted	295 ms	42400 KB
