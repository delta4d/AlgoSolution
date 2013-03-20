#include <cstdio>
#include <vector>
#include <cassert>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1 << 8;

int cnt;
int m, n;
int p[MAXN], f[MAXN], v[MAXN], tree[MAXN][2];
char buff[MAXN];
vector <int> cc, ct;

void dfs(int root) {
	if (tree[root][0] > 0) dfs(root<<1);
	if (tree[root][1] > 0) dfs((root<<1)+1);
	printf("%d%s", v[root], (cnt++)==n-1?"\n":" ");
}

void dfs(int root, int src, int dst) {
	if (src > dst) return;
	if (src == dst) {
		v[root] = f[src];
	} else {
		v[root] = f[src+tree[root][0]];
		dfs(root<<1, src, src+tree[root][0]-1);
		dfs((root<<1)+1, src+tree[root][0]+1, dst);
	}
}

int main() {
	int i, j, k;
	int s, t;
	int l, r;
	char *cp;
	
//	freopen("d:\\in.txt", "r", stdin);
	while (1 == scanf("%d", &n)) {
		for (i=0; i<n; ++i) scanf("%d", f+i);
		sort(f, f+n);
		scanf("%d", &m);
		memset(p, -1, sizeof(p));
		memset(tree, -1, sizeof(tree));
		gets(buff);
		ct.clear();
		ct.push_back(1);
		for (i=1; i<m; ++i) {
			cc = ct;
			ct.clear();
			gets(buff);
			s = 0;
			cp = strtok(buff, " \n");
			while (cp != NULL) {
				sscanf(cp, "%d", &l); cp = strtok(NULL, " \n");
				sscanf(cp, "%d", &r); cp = strtok(NULL, " \n");
				tree[cc[s]][0] = l, tree[cc[s]][1] = r;
				if (l > 1) ct.push_back(cc[s] << 1); 
			//	else tree[cc[s]<<1][0] = tree[cc[s]][1] = 0;
				if (r > 1) ct.push_back((cc[s] << 1) + 1); 
			//	else tree[(cc[s]<<1)+1][0] = tree[(cc[s]<<1)+1][1] = 0;
				++s;
			}
		}
		dfs(1, 0, n-1);
		cnt = 0;
		dfs(1);
	}
	return 0;
}