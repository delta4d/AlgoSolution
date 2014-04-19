#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 333;

vector <string> name;
char s[MAXN][15], t[MAXN][15];
int nxt[MAXN], d[MAXN];
#define ID(x) (lower_bound(name.begin(), name.end(), (x))-name.begin())

int main() {
	int tc, cn = 0, n;
	for (scanf("%d", &tc); tc--; ) {
		name.clear();
		memset(d, 0, sizeof(d));
		memset(nxt, -1, sizeof(nxt));
		scanf("%d", &n);
		for (int i=0; i+1<n; ++i) {
			scanf("%s%s", s[i], t[i]);
			name.push_back(s[i]), name.push_back(t[i]);
		}
		sort(name.begin(), name.end());
		name.erase(unique(name.begin(), name.end()), name.end());
		for (int i=0; i+1<n; ++i) {
			int a = ID(s[i]), b = ID(t[i]);
			++d[b], nxt[a] = b;
		}
		printf("Case %d:\n", ++cn);
		for (int i=0; i<(int)name.size(); ++i) if (!d[i]) {
			for (int j=i; j!=-1; j=nxt[j]) printf("%s\n", name[j].c_str());
			break;
		}
		puts("");
	}
	return 0;
}

// 320763	2014-02-06 01:02:15	 1075 - Finding Routes	 C++	 0.016	 1264	Accepted
