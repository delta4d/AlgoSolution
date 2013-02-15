#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 512;
const int MAXV = 900000;
const int INF = 0x3f3f3f3f;

int L[MAXV], R[MAXV], U[MAXV], D[MAXV];
int C[MAXV], H[MAXN], S[MAXN];
int mp[MAXV];
int out[MAXN];
int tot, res;

inline void init(const int n) {
	memset(H, -1, sizeof(H));
	for (int i=0; i<=n; ++i) {
		L[i] = (i == 0 ? n : i - 1);
		R[i] = (i == n ? 0 : i + 1);
		U[i] = D[i] = C[i] = i;
		S[i] = 0;
	}
	tot = n + 1;
}

void connect(const int x, const int y) {
	C[tot] = y, ++S[y];
	D[U[C[y]]] = tot, U[tot] = U[C[y]];
	D[tot] = C[y], U[C[y]] = tot;
	if (H[x] == -1) {
		H[x] = R[tot] = L[tot] = tot;
	} else {
		R[L[H[x]]] = tot, L[tot] = L[H[x]];
		R[tot] = H[x], L[H[x]] = tot;
	}
	mp[tot++] = x;
}

void remove(const int y) {
	R[L[y]] = R[y], L[R[y]] = L[y];
	for (int i=D[y]; i!=y; i=D[i]) {
		for (int j=R[i]; j!=i; j=R[j]) {
			U[D[j]] = U[j], D[U[j]] = D[j];
			--S[C[j]];
		}
	}
}

void resume(const int y) {
	for (int i=U[y]; i!=y; i=U[i]) {
		for (int j=L[i]; j!=i; j=L[j]) {
			U[D[j]] = j, D[U[j]] = j;
			++S[C[j]];
		}
	}
	R[L[y]] = y, L[R[y]] = y;
}

void dfs(int d, int cc) {
	if (cc > res) return;
	if (R[0] == 0) {
		res = min(res, cc);
		return;
	}
	int mn(INF), idx;
	for (int i=R[0]; i; i=R[i]) if (S[i] < mn) mn = S[i], idx = i;
	remove(idx);
	for (int i=D[idx]; i!=idx; i=D[i]) {
		out[d] = mp[i];
		for (int j=R[i]; j!=i; j=R[j]) remove(C[j]);
		dfs(d + 1, cc + 1);
		for (int j=L[i]; j!=i; j=L[j]) resume(C[j]);
	}
	resume(idx);
}

int main() {
	int i, j, k;
	int x, y;
	int m, n, p;
	int tc;
	int x1, y1, x2, y2;
	int t;
	
//	freopen("d:\\in.txt", "r", stdin);
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d %d %d", &n, &m, &p);
		init(n*m);
		for (i=1; i<=p; ++i) {
			scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
			for (j=y1; j<y2; ++j) for (k=x1; k<x2; ++k) {
				t = j * n + k + 1;
			//	printf("%d %d\n", i, t);
				connect(i, t);
			}
		}
		res = INF;
		dfs(0, 0);
		printf("%d\n", res==INF?-1:res);
	}
	return 0;
}
