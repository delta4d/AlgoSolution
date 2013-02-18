/*
ID: delta 4d
PROG: ariprog
LANG: C++
*/

#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

bool visit[150000];
int f[150000];
vector <pair<int, int> > out;

int main() {
	int i, j, k;
	int m, n;
	int len;
	int a, b;
	int MAXN;
	
	freopen("ariprog.in", "r", stdin);
	freopen("ariprog.out", "w", stdout);
	
	memset(visit, false, sizeof(visit));
	scanf("%d %d", &n, &m);
	for (i=0; i<=m; ++i) for (j=i; j<=m; ++j) visit[i*i+j*j] = true;
	MAXN = (m * m) << 1;
	for (len=i=0; i<=MAXN; ++i) if (visit[i]) f[len++] = i;
	for (i=0; i<len; ++i) {
		for (j=i+1; j<len; ++j) {
			a = f[i], b = f[j] - f[i];
			if (a == 63012 && b == 4) {
				int t = 0;
				++t;
			}
			if (a + (n - 1) * b > MAXN) break;
			for (k=0; k<n; ++k) if (!visit[a + k * b]) break;
			if (k == n) out.push_back(make_pair(b, a));
		}
	}
	sort(out.begin(), out.end());
	if (out.empty()) puts("NONE");
	else for (i=0; i<out.size(); ++i) printf("%d %d\n", out[i].second, out[i].first);
	return 0;
}