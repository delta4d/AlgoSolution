#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;

const LL MAXN = 100086;
const LL INF = 0x3f3f3f3f3f3f3f3fll;

LL tx[MAXN], ty[MAXN];
LL x[MAXN], y[MAXN];
LL sx[MAXN], sy[MAXN];
LL m, n;
LL nx, ny;
LL mn;

inline LL ABS(const LL x) {
	return x < 0 ? -x : x;
}

LL gao(LL tx[], LL x[], LL sx[]) {
	LL i, j, k;
	LL ret(0);
	sort(tx, tx+n);
	tx[n] = -1;
	k = 1;
	for (i=0; i<n; ++i) {
		if (tx[i] != tx[i+1]) {
			x[ret++] = k * m;
			k = 1;
		} else {
			++k;
		}
	}
	for (sx[0]=0,i=0; i<ret; ++i) sx[i+1] = sx[i] + x[i];
	return ret + 1;
}

void dfs(LL d, LL st, LL sum, LL sx[], const LL nx) {
//	printf("%lld ", st);
	if (d == m - 1) {
//		puts("");
		if (st < nx) sum += ABS(sx[nx-1] - sx[st-1] - n);
		else sum += n;
		mn = min(mn, sum);
		return;
	}
	if (st >= nx) {
		dfs(d+1, st, sum+n, sx, nx);
	} else {
		LL left, right, mid, idx;
		left = st, right = nx - 1, idx = st;
		while (left <= right) {
			mid = (left + right) >> 1;
			if (sx[mid] - sx[st-1] <= n) left = mid + 1, idx = mid;
			else right = mid - 1;
		}
/**		
		if (sx[idx] - sx[st-1] == n) {
			dfs(d+1, idx+1, sum, sx, nx);
		} else {
			dfs(d+1, idx+1, sum+ABS(sx[idx]-sx[st-1]-n), sx, nx);
			if (idx + 1 < nx) dfs(d+1, idx+2, sum+ABS(sx[idx+1]-sx[st-1]-n), sx, nx);
		}
**/		
		for (int i=-1; i<=1; ++i) if (st <= idx + i && idx + i < nx) {
			dfs(d+1, idx+i+1, sum+ABS(sx[idx+i]-sx[st-1]-n), sx, nx);
		}
	}
}

int main() {
	LL i, j, k;
	LL cn(0);
	
//	freopen("in.txt", "r", stdin);
	while (scanf("%lld %lld", &n, &m), n||m) {
		for (i=0; i<n; ++i) scanf("%lld%lld", tx+i, ty+i);
		nx = gao(tx, x, sx);
		ny = gao(ty, y, sy);
		mn = INF;
		dfs(0, 1, 0, sx, nx);
		dfs(0, 1, 0, sy, ny);
		k = __gcd(mn, m*m);
		printf("%lld. ", ++cn);
		if (mn == 0) puts("0/1");
		else printf("%lld/%lld\n", mn/k, m*m/k);
	}

	return 0;
}