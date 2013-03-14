#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define lowbit(x) ((x) & -(x))

struct BIT {
	vector <int> a;

	BIT(int sz=0) { a.resize(sz); }
	void modify(int p, const int off) {
		p = min(p, (int)a.size() - 1);
		for (; p>0; p-=lowbit(p)) a[p] += off;	
	}
	int sum(int p) {
		int tot(0);
		for (; p<a.size(); p+=lowbit(p)) tot += a[p];
		return tot;
	}
};

int ROOT;
vector <int> dep, idx;
vector <BIT> t;
vector <vector<int> > tr;

void dfs(int root, int d, int p, const int ii) {
	t[ii].a.push_back(0);
	dep[root] = d, idx[root] = ii;
	for (int i=0; i<tr[root].size(); ++i) {
		if (tr[root][i] != p) dfs(tr[root][i], d+1, root, ii);
	}
}

int main() {
	int n, q;
	int a, b;
	int k;
	int p, v, x, d;

	scanf("%d%d", &n, &q);
	tr.resize(n + 1); idx.resize(n + 1); dep.resize(n + 1);
	for (int i=1; i<n; ++i) {
		scanf("%d%d", &a, &b);
		tr[a].push_back(b);
		tr[b].push_back(a);
	}
	k = tr[1].size();
	t.resize(k + 1);
	for (int i=0; i<tr[1].size(); ++i) {
		t[i].a.push_back(0);
		dfs(tr[1][i], 1, 1, i);
	}
	t[k].a.resize(n + 1);
	while (q--) {
		scanf("%d", &p);
		if (p) {
			scanf("%d", &v);	
			if (v - 1) printf("%d\n", t[idx[v]].sum(dep[v])+t[k].sum(dep[v]));
			else printf("%d\n", ROOT);
		} else {
			scanf("%d%d%d", &v, &x, &d);
			if (v - 1) {
				if (d >= dep[v]) {
					ROOT += x;
					t[k].modify(d-dep[v], x);
					t[idx[v]].modify(d-dep[v], -x);
				} else {
					t[idx[v]].modify(dep[v]-d-1, -x);
				}
				t[idx[v]].modify(d+dep[v], x);
			} else {
				ROOT += x;
				t[k].modify(d, x);
			}
		}
	}

	return 0;
}

// 3315982	 Mar 14, 2013 3:19:07 PM	delta_4d	 276E - Little Girl and Problem on Trees	 GNU C++	Accepted	218 ms	12300 KB
