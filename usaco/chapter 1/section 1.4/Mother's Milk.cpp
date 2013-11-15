/*
ID: delta 4d
PROG: milk3
LANG: C++
*/

#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 222222;

bool visit[MAXN];

queue <int> q;
vector <int> out;

int main() {
	int i, j, k;
	int s, t;
	int v[3];
	int w[3];
	int x[3];
	
	freopen("milk3.in", "r", stdin);
	freopen("milk3.out", "w", stdout);
	
	for (i=0; i<3; ++i) scanf("%d", v+i);
	memset(visit, false, sizeof(visit));
	visit[s = v[2]] = true;
	q.push(s);
	while (!q.empty()) {
		s = q.front();
		q.pop();
		w[2] = s % 100, s /= 100, w[1] = s % 100, w[0] = s / 100;
		if (w[0] == 0) out.push_back(w[2]);
		for (i=0; i<3; ++i) for (j=0; j<3; ++j) {
			if (j == i) continue;
			k = min(w[i], v[j]-w[j]);
			for (t=0; t<3; ++t) x[t] = w[t];
			x[i] -= k, x[j] += k;
			t = (x[0] * 100 + x[1]) * 100 + x[2];
			if (!visit[t]) {
				visit[t] = true;
				q.push(t);
			}
		}
	}
	sort(out.begin(), out.end());
	unique(out.begin(), out.end());
	for (i=0; i<out.size(); ++i) printf("%d%c", out[i], i==out.size()-1?'\n':' ');
	return 0;
}