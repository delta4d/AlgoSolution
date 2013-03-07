#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 900;
const int MAXV = 5000;
const int INF = 0x3f3f3f3f;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

int L[MAXV], R[MAXV], U[MAXV], D[MAXV];
int C[MAXV], H[MAXN], S[MAXN];
int mp[MAXV];
int out[MAXN], res[MAXN];
int tot;

int cnt;
bool dd[16][16][4];
int id[16][16];
int s[16][16];

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

void dfs(int d) {
	if (cnt > 1) return;
	if (R[0] == 0) {
		++cnt;
		for (int i=0; i<d; ++i) res[i] = out[i];
		return;
	}
	int mn(INF), idx;
	for (int i=R[0]; i; i=R[i]) if (S[i] < mn) mn = S[i], idx = i;
	remove(idx);
	for (int i=D[idx]; i!=idx; i=D[i]) {
		out[d] = mp[i];
		for (int j=R[i]; j!=i; j=R[j]) remove(C[j]);
		dfs(d + 1);
		if (cnt > 1) return;
		for (int j=L[i]; j!=i; j=L[j]) resume(C[j]);
	}
	resume(idx);
}

void floodfill(int x, int y, const int num) {
	int i, j, k;
	int tx, ty;
	
	id[x][y] = num;
	for (k=0; k<4; ++k) {
		if (!dd[x][y][k]) continue;
		tx = x + dx[k], ty = y + dy[k];
		if (id[tx][ty] != -1) continue;
		if (1 <= tx && tx <= 9 && 1 <= ty && ty <= 9) floodfill(tx, ty, num);
	}
}

void add(int i, int j, int k) {
	int r((i - 1) * 81 + (j - 1) * 9 + k);
	connect(r, (i - 1) * 9 + j);
	connect(r, 81 + (i - 1) * 9 + k);
	connect(r, 162 + (j - 1) * 9 + k);
	connect(r, 243 + (id[i][j] - 1) * 9 + k);
}

int main() {
	int i, j, k;
	int tc, cn(0);
	int x, y;
	int num;

//	freopen("d:\\in.txt", "r", stdin);
//	freopen("d:\\out.txt", "w", stdout);
	scanf("%d", &tc);
	while (tc--) {
		memset(dd, true, sizeof(dd));
		for (i=1; i<=9; ++i) {
			for (j=1; j<=9; ++j) {
				scanf("%d", &x);
				s[i][j] = x & 0xf;
				for (k=4; k<=7; ++k) if (x & (1 << k)) dd[i][j][k-4] = false;
			}
		}
		memset(id, -1, sizeof(id));
		for (num=0,i=1; i<=9; ++i) for (j=1; j<=9; ++j) if (id[i][j] == -1) floodfill(i, j, ++num);
		init(324);
		for (i=1; i<=9; ++i)  for (j=1; j<=9; ++j) {
			if (s[i][j]) add(i, j, s[i][j]);
			else for (k=1; k<=9; ++k) add(i, j, k);
		}
		cnt = 0;
		dfs(0);
		printf("Case %d:\n", ++cn);
		if (cnt == 0) {
			puts("No solution");
		} else if (cnt > 1) {
			puts("Multiple Solutions");
		} else {
			sort(res, res+81);
			for (i=0; i<9; ++i) {
				for (j=0; j<9; ++j) printf("%d", ((res[i*9+j]-1)%9)+1);
				puts("");
			}
		}
	}
	return 0;
}