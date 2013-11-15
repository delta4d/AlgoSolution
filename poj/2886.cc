#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 500000 + 86;
#define LS(x) ((x) << 1)
#define RS(x) (LS(x) ^ 1)

int F[]={0, 1, 2, 3, 4, 6, 8, 9, 10, 12, 16, 18, 20, 24, 30, 32, 36, 40, 48, 60, 64, 72, 80, 84, 90, 96, 100, 108, 120, 128, 144, 160, 168, 180, 192, 200, 216, 224, 240};
int mx[]={0, 1, 2, 4, 6, 12, 24, 36, 48, 60, 120, 180, 240, 360, 720, 840, 1260, 1680, 2520, 5040, 7560, 10080, 15120, 20160, 25200, 27720, 45360, 50400, 55440, 83160, 110880, 166320, 221760, 277200, 332640, 498960, 554400, 665280, 720720}; 

char name[MAXN][12];
int p[MAXN];

struct seg_tree {
	int x[MAXN<<2];	

	void init(int r, int L, int R) {
		x[r] = R - L + 1;	
		if (L == R) return;
		int M = (L + R) >> 1;
		init(LS(r), L, M);
		init(RS(r), M+1, R);
	}

	int update(int r, int L, int R, int k) {
		--x[r];
		if (L == R) return L;
		int M = (L + R) >> 1;
		if (k <= x[LS(r)]) return update(LS(r), L, M, k);
		return update(RS(r), M+1, R, k-x[LS(r)]);
	}
} T;

int main() {
	int n, k;
	while (2 == scanf("%d%d", &n, &k)) {
		T.init(1, 1, n);
		for (int i=1; i<=n; ++i) scanf("%s%d", name[i], p+i);	
		int t;
		for (t=1; mx[t]<=n; ++t); --t;
		int cc = 0, mod = n;
		for (int i=0; i<mx[t]; ++i, --mod) {
//			printf("%d %d %d\n", cc, k, mod);
			if (p[cc] > 0) k = ((k + p[cc] - 2) % mod + mod) % mod + 1;
			else k = ((k + p[cc] - 1) % mod + mod) % mod + 1;
			cc = T.update(1, 1, n, k);
		}
		printf("%s %d\n", name[cc], F[t]);
	}

	return 0;
}
