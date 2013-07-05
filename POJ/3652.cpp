#include <set>
#include <bitset>
#include <cstdio>
#include <memory>
#include <iostream>
using namespace std;

#define INIT for (i=0; i<16; ++i) res[i] = p[i]
#define MIXED -1
const int MAXN = 16;
int res[MAXN];
int A, B, C, S;

void gao() {
	int i, j, k(0);
	int pre(S), cur((A*S+B)%C);
	bitset<MAXN> p(pre);
	bitset<MAXN> c(cur);
	INIT;
	while (++k <= C) {
		p = pre;
		c = cur;
		for (i=0; i<16; ++i) {
			if (p[i] != c[i]) res[i] = MIXED;
		}
		pre = cur;
		cur = (A * cur + B) % C;
	}
	for (i=15; i>=0; --i) {
		if (res[i] != MIXED) printf("%d", res[i]);
		else printf("%c", '?');
	}
	puts("");
}

int main() {
	int i, j, k;
	//freopen("f:\\in.txt", "r", stdin);
	scanf("%d", &A);
	while (A != 0) {
		scanf("%d %d %d", &B, &C, &S);
		gao();
		scanf("%d", &A);
	}
	return 0;
}