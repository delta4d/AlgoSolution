#include <queue>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;
const LL MAXN = 50000 + 86;
const LL INF = 0x3f3f3f3f3f3f3f3fll;

struct task {
	LL t, s, p, id;
	task(LL _t=0, LL _s=0, LL _p=0, LL _id=0):t(_t), s(_s), p(_p), id(_id) {}
	bool operator<(const task &a) const {
		return p < a.p;
	}
};

inline bool cmp(const task &a, const task &b) {
	return a.t < b.t;
}

vector <LL> pr, pp;
vector <task> tsk, cc;
priority_queue <task> q;
LL out[MAXN];

LL gao(const LL n, const LL k) {
	cc = tsk;
	sort(cc.begin(), cc.end(), cmp);

	for (LL i=0,j; i<n; i=j) {
		for (j=i; j<n&&cc[j].t==cc[i].t; ++j) q.push(cc[j]);
		LL ct = cc[i].t, nt = (j >= n ? INF : cc[j].t);
		while (!q.empty() && ct < nt) {
			task tt = q.top();
			q.pop();
			if (ct + tt.s - 1 < nt) ct += tt.s, out[tt.id] = ct;
			else tt.s -= nt - ct, q.push(tt), ct = nt;
		}
	}
//	for (LL i=0; i<n; ++i) printf("%d ", out[i]); puts("");
	return out[k];
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	ios_base::sync_with_stdio(false);
	LL n;
	LL tl, k(-1);

	cin >> n;
	for (LL i=0,t,s,p; i<n; ++i) {
		cin >> t >> s >> p;
		if (p != -1) pr.push_back(p);
		else k = i;
		tsk.push_back(task(t, s, p, i));
	}
	pr.push_back(0), pr.push_back(INF);
	sort(pr.begin(), pr.end());
	for (LL i=0; i<=n; ++i) if (pr[i] + 1 != pr[i+1]) pp.push_back(pr[i] + 1);

	cin >> tl;
	LL left = 0, right = pp.size() - 1, mid = -1;
	while (left <= right) {
		mid = (left + right) >> 1;	
		tsk[k].p = pp[mid];
		LL cc = gao(n, k);
		if (cc == tl) {
			cout << pp[mid] << endl;
			for (LL i=0; i<n; ++i)	cout << out[i] << (i == n - 1 ? "\n" : " ");
			break;
		}
		if (cc < tl) right = mid - 1;
		else left = mid + 1;
	}

	return 0;
}

// 3826822	 Jun 6, 2013 11:11:39 AM	delta_4d	 E - Printer	 GNU C++	Accepted	1218 ms	8844 KB
