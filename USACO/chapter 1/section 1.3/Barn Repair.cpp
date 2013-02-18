/*
ID: delta 4d
PROG: barn1
LANG: C++
*/

#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <functional>
using namespace std;

const int INF = 0x3f3f3f3f;

int main() {
	int i, j, k;
	int M, S, C;
	int x, y;
	int s, t;
	int len;
	vector<int> f1, f2;	
	freopen("barn1.in", "r", stdin);
	freopen("barn1.out", "w", stdout);
	while (scanf("%d %d %d", &M, &S, &C) != EOF) {
		f1.clear();
		s = INF;
		t = -INF;
		for (i=0; i<C; ++i) {
			scanf("%d", &x);
			f1.push_back(x);
			s = min(s, x);
			t = max(t, x);
		}
		sort(f1.begin(), f1.end());
		//printf("s: %d, t: %d\n", s, t);
		f2.clear();
		for (i=0; i<C-1; ++i) {
			f2.push_back(f1[i+1]-f1[i]);
		}
		sort(f2.begin(), f2.end(), greater<int>());
		//for (i=0; i!=f1.size(); ++i) printf("%d ", f1[i]); puts("");
		//for (i=0; i!=f2.size(); ++i) printf("%d ", f2[i]); puts("");
		len = 0;
		for (i=0; i<M-1&&i<C-1; ++i) len += f2[i];
		//printf("len: %d\n", len);
		len = t - s + 1 - len + i;
		printf("%d\n", len);
	}
	return 0;
}