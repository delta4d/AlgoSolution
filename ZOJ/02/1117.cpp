#include <queue>
#include <cstdio>
#include <vector>
#include <utility>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int MAXL = 80;
const int MAXN = 27;

struct node {
	int cnt;
	int index;
	bool child[MAXN];
	node(int cnt=0, int index=-1):cnt(cnt), index(index) {
		memset(child, false, sizeof(child));
		if (index != -1) child[index] = true;
	}
};

priority_queue<node> q;
int p[MAXN];
int c[MAXN];
char buff[MAXL];

bool operator<(const node &a, const node &b) {
	return a.cnt > b.cnt;
}

int gao() {
	int i, j, k(0);
	node e1, e2;
	
	memset(c, 0, sizeof(c));
	if (q.size() == 1) c[q.top().index] = 1;
	while (!q.empty()) {
		if (q.size() < 2) break;
		e1 = q.top(); q.pop();
		e2 = q.top(); q.pop();
		node cc;
		cc.cnt = e1.cnt + e2.cnt;
		for (i=0; i<MAXN; ++i) {
			if (e1.child[i]) {
				++c[i];
				cc.child[i] = true;
			}
			if (e2.child[i]) {
				++c[i];
				cc.child[i] = true;
			}
		}
		q.push(cc);
	}
	for (i=0; i<MAXN; ++i) k += p[i] * c[i];
	return k;
}

int main() {
	int len, t;
	int i, j, k;
	//freopen("f:\\in.txt", "r", stdin);
	scanf("%s", buff);
	while (strcmp(buff, "END") != 0) {
		len = strlen(buff);
		memset(p, 0, sizeof(p));
		for (i=0; i<len; ++i) ++p[buff[i]=='_'?MAXN-1:buff[i]-'A'];
		while (!q.empty()) q.pop();
		for (i=0; i<MAXN; ++i) {
			if (p[i] != 0) {
				q.push(node(p[i], i));
			}
		}
		t = len << 3, k = gao();
		printf("%d %d %.1lf\n", t, k, (double)t/k);
		scanf("%s", buff);
	}
	return 0;
}