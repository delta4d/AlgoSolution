#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 500005;
const int MAXM = 200005;
int n, m;
int match1[MAXN], match2[MAXN];
int Q[MAXN], D1[MAXN], D2[MAXN];
int x[MAXN], mp[MAXN];
vector <int> E[MAXN];

inline bool bfs () {
	int s = 0, t = 0, u, v;
	memset (D1, -1, sizeof (D1));
	memset (D2, -1, sizeof (D2));
	for (int i = 0; i < n; i++) if (match1[i] == -1) Q[t++] = i, D1[i] = 0;
	while (s != t) if ((u = Q[s++]) != n) for (int i = 0; i < (int) E[u].size (); i++)
		if (D2[v = E[u][i]] == -1)
		{
			D2[v] = D1[u] + 1;
			if (D1[match2[v]] == -1)
				D1[Q[t++] = match2[v]] = D2[v] + 1;
		}
	return D1[n] != -1;
}

bool dfs (int u) {
	for (int i = 0, v; i < (int) E[u].size (); i++)
		if (D2[v = E[u][i]] == D1[u] + 1 && (D2[v] = -1) && (match2[v] == n || dfs (match2[v])))
		{
			match1[u] = v;
			match2[v] = u;
			D1[u] = -1;
			return true;
		}
	D1[u] = -1;
	return false;
}

inline int hopcroft_karp () {
	memset (match1, -1, sizeof (match1));
	for (int i = 0; i < m; i++)
		match2[i] = n;
	int ret = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0, u; j < E[i].size (); j++)
			if (match2[u = E[i][j]] == n)
			{
				match1[i] = u;
				match2[u] = i;
				ret++;
				break;
			}
	while (bfs ())
		for (int i = 0; i < n; i++)
			if (match1[i] == -1 && dfs (i))
				ret++;
	return ret;
}

int main() {
	int tc, cn = 0;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d", &n), m = n;
		memset(mp, -1, sizeof(mp));
		for (int i=0; i<n; ++i) {
			E[i].clear();
			scanf("%d", x+i);
			mp[x[i]] = i;
		}
		for (int i=0; i<n; ++i) {
			int cc = x[i], p[50], c = 0, t = 0;
			for (int k=2; k*k<=cc; ++k) if (cc % k == 0) {
				p[c++] = k, t ^= 1;
				for (cc/=k; cc%k==0; cc/=k, t^=1);
			}
			if (cc != 1) p[c++] = cc, t ^= 1;
			for (int k=0,j; k<c; ++k) if ((j=mp[x[i]/p[k]])!=-1) {
				if (t) E[i].push_back(j);
				else E[j].push_back(i);
			}
		}
		printf("Case %d: %d\n", ++cn, n-hopcroft_karp());
	}
	return 0;
}

// 251680	2013-08-14 22:02:54	 1356 - Prime Independence	 C++	 0.856	 28184	Accepted
