#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <functional>
using namespace std;

const int MAXN = 10086;

bool is_p[MAXN];
int p[MAXN], pn(1);
int sp[MAXN], spn;

struct node {
	int len;
	vector<int> out;
	
	node() {len=-1;}
	void output() {
		printf("%d\n", len==-1?0:len-1);
		if (len > 0) sort(out.begin(), out.end(), greater<int>());
		for (int i=0; i+1<len; ++i) printf("%d%s", out[i], i+1==len?"\n":" ");
	}
} f[MAXN];

void gen() {
	int i, j, k;
	
	memset(is_p, true, sizeof(is_p));
	for (i=2; i<MAXN; ++i) {
		if (is_p[i]) {
			p[pn++] = i;
			for (j=i<<1; j<MAXN; j+=i) is_p[j] = false;
		}
	}
	for (i=2; i<pn; ++i) {
		if (is_p[i]) sp[spn++] = p[i];
	}
	//printf("%d\n", spn);
	//for (i=0; i<spn; ++i) printf("%d ", sp[i]);
}

void gao(const int n) {
	int i, j, k, t;
	
	f[0].len = 1, f[0].out.push_back(0);
	for (i=spn-1; i>=0; --i) {
		//if (sp[i] > n) break;
		for (j=0; j<=n; ++j) {
			t = j + sp[i];
			if (t > n) break;
			if (f[j].len != -1) {
				if (f[t].len == -1 || f[t].len > f[j].len + 1) {
					f[t].len = f[j].len + 1;
					//for (k=0; k<f[j].len; ++k) f[t].out[k] = f[j].out[k];
					f[t].out = f[j].out;
					f[t].out.push_back(sp[i]);
				} 
			}
		}
	}
}

int main() {
	int i, j, k;
	int m, n;
	
	gen();
	scanf("%d", &n);
	gao(n);
	f[n].output();
	
	return 0;
}