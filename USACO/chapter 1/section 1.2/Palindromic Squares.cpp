/*
ID: delta 4d
PROG: palsquare
LANG: C++
*/

#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 21;
const int MAXL = 32;
vector<int> out[MAXN];
int buff[MAXL];
char fout[MAXL];

inline bool gao(const int base, const int a) {
	int i, j, k(0);
	int x(a*a);
	do {
		buff[k] = x % base;
		x /= base;
		++k;
	} while (x != 0);
	for (i=0; i<k; ++i) if (buff[i] != buff[k-1-i]) return false;
	return true;
}

inline void gao() {
	int i, j, k;
	int base, x;
	for (base=2; base<=20; ++base) {
		for (x=1; x<=300; ++x) {
			if (gao(base, x)) out[base].push_back(x);
		}
	}
}

inline void tran(const int base, int x) {
	int i, j, k(0);
	char temp[MAXL];
	do {
		i = x % base;
		if (i >= 0 && i <= 9) temp[k] = i + '0';
		else temp[k] = 'A' + i - 10;
		x /= base;
		++k;
	} while (x != 0);
	for (i=0; i<k; ++i) fout[i] = temp[k-1-i];
	fout[i] = '\0';
	printf("%s", fout);
}

int main() {
	int i, j, k;
	int n;
	gao();
	freopen("palsquare.in", "r", stdin);
	freopen("palsquare.out", "w", stdout);
	while (scanf("%d", &n) != EOF) {
		for (i=0; i!=out[n].size(); ++i) {
			tran(n, out[n][i]); printf(" "); tran(n, out[n][i]*out[n][i]);
			puts("");
		}
	}
	return 0;
}