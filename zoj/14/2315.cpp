#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

typedef vector<int> VI;

const int MAXN = 500001;
const int INF = 0x3f3f3f3f;
VI f[MAXN], out;
int sel[MAXN];
int mem[MAXN];
int m, n;

int gao(int root) {
	int i, j, k;
	int temp, sum;
	int ret, idx;
	int choose_one, choose_none;
	int new_root;

	if (mem[root] != -1) return mem[root];
	if (f[root].size() == 0) {
		sel[root] = -1;
		return mem[root] = 0;
	}
	sum = 0;
	for (i=0; i!=f[root].size(); ++i) sum += gao(f[root][i]);
	choose_none = sum;
	choose_one = -INF;
	for (i=0; i!=f[root].size(); ++i) {
		new_root = f[root][i];
		temp = sum - mem[new_root] + 1;
		for (j=0; j!=f[new_root].size(); ++j) {
			temp += gao(f[new_root][j]);
		}
		if (temp > choose_one) {
			choose_one = temp;
			idx = new_root;
		}
	}

	if (choose_one > choose_none) {
		ret = choose_one;
		sel[root] = idx;
	} else {
		ret = choose_none;
		sel[root] = -1;
	}
	return mem[root] = ret;
}

void gao() {
	int i, j, k;
	out.clear();
	for (i=1; i<=n; ++i) if (sel[i] != -1) out.push_back(sel[i]);
	sort(out.begin(), out.end());
}

int main() {
	int i, j, k;
	int tc;

	scanf("%d", &tc);
	while (tc--) {
		scanf("%d", &n);	
		for (i=1; i<=n; ++i) f[i].clear();
		for (i=1; i<n; ++i) {
			scanf("%d", &k);
			f[k].push_back(i+1);
		}
		memset(mem, -1, sizeof(mem));
		gao(1);
		gao();
		//for (i=1; i<=n; ++i) printf("%d -- ", mem[i]); puts("");
		//for (i=1; i<=n; ++i) printf("%d ++ ", sel[i]); puts("");
		printf("%d\n", mem[1]*1000);
		for (i=0; i!=out.size(); ++i) printf("%d%s", out[i], i==out.size()-1?"\n":" ");
		if (tc) puts("");
	}

	return 0;
}
