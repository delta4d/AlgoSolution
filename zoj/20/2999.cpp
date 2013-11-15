#include <map>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
using namespace  std;

const int MAXL = 256;
const int MAXN = 30001;

int tot;
int f[MAXN];
char buff[MAXL], child[MAXL], parent[MAXL];
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

inline bool gao(int cid, int pid) {
	int i, j, k;
	if (cid == pid) return true;
	while (f[cid] >= 0) {
		if (f[cid] == pid) return true;
		cid = f[cid];
	}
	return false;
}

int main() {
	int i, j, k;
	int cn(0);
	int m, n;
	int cid, pid;
	//freopen("f:\\in.txt", "r", stdin);
	scanf("%s %d", buff, &n);
	while (true) {
		ta.clear();
		ta.insert(make_pair(string(buff), 0));
		tot = 1;
		memset(f, -1, sizeof(f));
		for (i=0; i<n; ++i) {
			scanf("%s %s", child, parent);
			cid = gao(child);
			pid = gao(parent);
			f[cid] = pid;
		}
		printf("Project %d\n", ++cn);
		scanf("%d", &m);
		for (i=0; i<m; ++i) {
			scanf("%s %s", child, parent);
			printf("%s\n", gao(gao(child), gao(parent))?"Yes":"No");
		}
		if (scanf("%s %d", buff, &n) == EOF) break;
		puts("");
	}
	return 0;
}