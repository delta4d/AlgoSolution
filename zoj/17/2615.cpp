#include <cstdio>
using namespace std;

const int MAXN = 300001;
const int MAXNN = 30000000;

int n;
int p[MAXN], e[MAXN], on[MAXN];
int in[MAXNN], out[MAXNN];

void gao() {
	int ip(0), op(0);
	int top(1);
	p[1] = 0;
	
	while (top) {
		nextw: in[p[top]] = ++ip;
		for (on[top]=e[p[top]]; on[top]<e[p[top]+1]; ++on[top]) {
			if (on[top] < n) {
				p[top+1] = on[top];
				++top;
				goto nextw;
			} else {
				in[on[top]] = ++ip;
				out[on[top]] = ++op;
			}
			nextf:;
		}
		out[p[top]] = ++op;
		if (--top) goto nextf;
	}
}

int main() {
	int i, j, k(0);
	int x, y;
	int t, tc, q;
	e[0] = 1;
	//freopen("f:\\in.txt", "r", stdin);
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d", &n);
		for (i=0; i<n; ++i) {
			scanf("%d", &t);
			e[i+1] = e[i] + t;
		}
		gao();
		printf("Case %d:\n", ++k);
		scanf("%d", &q);
		for (i=0; i<q; ++i) {
			scanf("%d %d", &x, &y);
			if (in[x] < in[y] && out[x] > out[y]) puts("Yes");
			else puts("No");
		}
		if (tc) puts("");
	}
	return 0;
}