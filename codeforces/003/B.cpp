#include <set>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 100086;
const int w[] = {0, 1, 2};

struct node {
	int idx, type, v;
	node() {}
	node(int idx, int type, int v):idx(idx), type(type), v(v) {};
} f[MAXN];
vector <int> out;
set <int> ss;

inline bool cmp(const node &a, const node &b) {
	return (a.type == 1 ? a.v << 1 : a.v) > (b.type == 1 ? b.v << 1 : b.v);
}

int main() {
	int i, j, k;
	int m, n, v;
	
	scanf("%d%d", &n, &v);
	for (i=0; i<n; ++i) {
		scanf("%d%d", &f[i].type, &f[i].v);
		f[i].idx = i + 1;
	}
	sort(f, f+n, cmp);
	for (i=j=k=0; i<n; ++i) {
//		printf("-- %d %d\n", f[i].type, f[i].v);
		if (w[f[i].type] + j > v) continue;
//		puts("*");
		j += w[f[i].type], k += f[i].v;
		out.push_back(i);
	}	
	if (j != v) do {
		if (out.size() == n) break;
		for (i=out.size()-1; i>=0&&f[out[i]].type==2; --i);
		if (i < 0) break;
		for (j=out.size()-1; j>=0; --j) ss.insert(out[j]);
		for (j=0; j<n; ++j) if (f[j].type == 2 && ss.find(j) == ss.end()) break;
		if (j >= n) break;
		out[i] = j;
		k += f[j].v - f[i].v;
	} while (false);
	printf("%d\n", k);
	for (i=0; i<out.size(); ++i) printf("%d%s", f[out[i]].idx, i==out.size()-1?"\n":" ");

	return 0;
}

//#			 When	Who	Problem	Lang	Verdict	Time	Memory
//2906890	 Jan 12, 2013 10:52:22 AM	delta_4d	 B - Lorry	 GNU C++	Accepted	 109 ms	 2200 KB
