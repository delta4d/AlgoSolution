#include <map>
#include <set>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using namespace  std;

const int MAXL = 256;
const int MAXN = 30001;

int tot;
int timestamp[MAXN];
char buff[MAXL], child[MAXL], parent[MAXL];
vector<int> tree[MAXN];
map<string, int> ta;

inline int gao(char s[]) {
	map<string, int>::iterator it;
	it = ta.find(string(s));
	if (it == ta.end()) {
		ta.insert(make_pair(string(s), tot));
		return tot++;
	}
	return (*it).second;
}

void dfs(int root, int &rank) {
	int child;
	int i, j, k;
	timestamp[root] = rank;
	for (i=0; i!=tree[root].size(); ++i) {
		dfs(tree[root][i], ++rank);
	}
}

int main() {
	int i, j, k;
	int cn(0);
	int m, n;
	int cid, pid;
	int rank;
	//freopen("f:\\in.txt", "r", stdin);
	scanf("%s %d", buff, &n);
	while (true) {
		ta.clear();
		ta.insert(make_pair(string(buff), 0));
		tot = 1;
		for (i=0; i<=n; ++i) tree[i].clear();
		for (i=0; i<n; ++i) {
			scanf("%s %s", child, parent);
			cid = gao(child);
			pid = gao(parent);
			tree[pid].push_back(cid);
		}
		memset(timestamp, -1, sizeof(timestamp));
		rank = 0;
		dfs(0, rank);
		printf("Project %d\n", ++cn);
		scanf("%d", &m);
		for (i=0; i<m; ++i) {
			scanf("%s %s", child, parent);
			printf("%s\n", timestamp[gao(child)]>=timestamp[gao(parent)]?"Yes":"No");
		}
		if (scanf("%s %d", buff, &n) == EOF) break;
		puts("");
	}
	return 0;
}