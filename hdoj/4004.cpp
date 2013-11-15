#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 500111;

int L, n, m;
int f[MAXN];

bool gao(int step) {
	int i, j, k;
	int cc(0), sum;
	
	for (i=0; i<n+1; ++cc) {
		for (j=0; i+j<n+2&&f[i+j]-f[i]<=step; ++j);
		if (j == 1) return false;
		i += j - 1;
	}
	return cc <= m;
}

int main() {
	int i, j, k;
	int left, right, mid, res;
	
	//freopen("in.txt", "r", stdin);
	while (3 == scanf("%d %d %d", &L, &n, &m)) {
		for (i=1; i<=n; ++i) scanf("%d", f+i);
		f[0] = 0, f[i] = L;
		sort(f, f+n+2);
		left = 0, right = L;
		while (left <= right) {
			mid = (left + right) >> 1;
			if (gao(mid)) res = mid, right = mid - 1;
			else left = mid + 1;
		}
		printf("%d\n", res);
	}
	return 0;
}