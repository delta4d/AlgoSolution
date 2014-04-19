#include <cstdio>
using namespace std;

const int MAXN = 111;

bool v[MAXN];
int p[MAXN], c;
int cnt[MAXN];

void init() {
	for (int i=2; i<MAXN; ++i) if (!v[i]) {
		p[c++] = i;
		for (int j=i*i; j<MAXN; j+=i) v[j] = true;
	}
}

int main() {
	init();
	int tc, cn = 0, x;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d", &x);
		printf("Case %d: %d = ", ++cn, x);
		int sz = 0;
		for (int i=0; p[i]<=x; ++i) {
			int xx = x;
			cnt[sz] = 0;
			for (; xx; cnt[sz]+=xx/=p[i]);
			++sz;
		}
		for (int i=0; i<sz; ++i) printf("%d (%d)%s", p[i], cnt[i], i==sz-1?"\n":" * ");
	}
	return 0;
}

// 249386	2013-08-08 22:36:44	 1035 - Intelligent Factorial Factorization	 C++	 0.000	 1088	Accepted 
