#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 20;
const int p3[] = {1, 3, 9, 27, 81, 243, 729, 2187, 6561, 19683, 59049, 177147, 531441, 1594323, 4782969, 14348907, 43046721, 129140163, 387420489, 1162261467};

int f[MAXN];

inline int to3(int n) {
	int k(0);
	memset(f, 0, sizeof(f));
	do {
		f[k++] = n % 3;
		n /= 3;
	} while (n != 0);
	return k;
}

inline void gao(const int len) {
	int i, j, k;
	for (i=0; i<len; ++i) {
		if (f[i] == 3) {
			f[i] = 0;
			++f[i+1];
		} else if (f[i] == 2) {
			f[i] = -1;
			++f[i+1];
		}
	}
}

inline void out(const int len) {
	int i, j, k;
	int tt[MAXN];
	k = 0;
	for (i=0; i<=len; ++i) if (f[i] == -1) tt[k++] = i;
	if (k == 0) puts("-1");
	else for (i=0; i<k; ++i) printf("%d%s", p3[tt[i]], i==k-1?"\n":" ");
	k = 0;
	for (i=0; i<=len; ++i) if (f[i] == 1) tt[k++] = i;
	if (k == 0) puts("-1");
	else for (i=0; i<k; ++i) printf("%d%s", p3[tt[i]], i==k-1?"\n":" ");
	puts("");
}

int main() {
	int i, j, k;
	int m, n;
	//freopen("f:\\in.txt", "r", stdin);
	while (scanf("%d", &n) == 1) {
		k = to3(n);
		gao(k);
		out(k);
	}
	return 0;
}