#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 5555;

struct node {
	int W, L, I;
	node() {}
	node(int W, int L, int I):W(W), L(L), I(I) {}
};

vector <node> f;
vector <int> out;
int x[MAXN], p[MAXN];

inline bool cmp(const node &a, const node &b) {
	return a.W < b.W;
}

int main() {
	int i, j, k;
	int m, n, W, L;

	scanf("%d%d%d", &n, &W, &L);
	for (k=0; k<n; ++k) {
		scanf("%d%d", &i, &j);
		if (i > W && j > L) f.push_back(node(i, j, k+1));
	}
	sort(f.begin(), f.end(), cmp);
//	for (i=0; i<f.size(); ++i) printf("(%d %d %d)", f[i].W, f[i].L, f[i].I); puts("");
	memset(x, -1, sizeof(x));
	memset(p, -1, sizeof(p));
	for (k=i=0; i<f.size(); ++i) {
		int left(1), right(k), mid;
		j = 0;
		while (left <= right) {
			mid = (left + right) >> 1;
			if (f[x[mid]].L < f[i].L) {
				if (f[x[mid]].W != f[i].W) j = mid;
				left = mid + 1;
			} else {
				right = mid - 1;
			}
		}
		p[i] = x[j];
		if (j == k || f[i].L < f[x[j+1]].L) {
			x[j+1] = i, k = max(k, j+1);
		}
	}
//	puts("LIS done");

	i = x[k], j = k;
	while (j--) {
		out.push_back(f[i].I);
		i = p[i];
	}
	printf("%d\n", k);
	for (i=out.size()-1; i>=0; --i) printf("%d%s", out[i], i?" ":"\n");

	return 0;
}

//#	When	Who	Problem	Lang	Verdict	Time	Memory
//2907906	 Jan 12, 2013 5:39:22 PM	delta_4d	 D - Mysterious Present	 GNU C++	Accepted	 15 ms	 200 KB
