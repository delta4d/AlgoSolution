#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 200000 + 86;

#define lowbit(x) ((x) & -(x))


struct BIT {
	vector <int> a;

	BIT(int sz=0) { a.resize(sz); }
	void init(int sz) { a.resize(sz); }
	void modify(int p, const int off) {
		p = min(p, (int)a.size() - 1);
		for (; p>0; p-=lowbit(p)) a[p] += off;
	}
	int sum(int p) {
		int tot(0);
		for (; p<a.size(); p+=lowbit(p)) tot += a[p];
		return tot;
	}
} T;

int main() {
	int i, j, k;
	int m, n;
	int sz = 1;
	double tot = 0;
	int a, x;

	scanf("%d", &n);
	T.init(n+10086);
	while (n--) {
		scanf("%d", &m);
		if (m == 1) {
			scanf("%d%d", &a, &x);
			T.modify(a, x);
			tot += a * x;
		} else if (m == 2) {
			scanf("%d", &k);
			++sz;
			T.modify(sz, k);
			T.modify(sz-1, -k);
			tot += k;
		} else {
			k = T.sum(sz);
			T.modify(sz, -k);
			T.modify(sz-1, k);
			--sz;
			tot -= k;
		}
//		for (i=1; i<=sz; ++i) printf("%d ", T.sum(i)); puts("");
		printf("%.16lf\n", tot/double(sz));
	}			

	return 0;
}

// 3333484	 Mar 17, 2013 7:51:47 PM	delta_4d	 A - Cows and Sequence	 GNU C++	Accepted	 468 ms	
