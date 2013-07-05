#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 4100;
const int MAXV = 50000;
const int INF = 0x3f3f3f3f;

int L[MAXV+1], R[MAXV+1], U[MAXV+1], D[MAXV+1];
int C[MAXV+1], H[MAXN], S[MAXN];
int mp[MAXV+1];
int out[MAXN];
int tot;

char s[32][32];

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

char getc(const int x) {
	return ((x - 1) & 0xf) + 'A';
}

bool dfs(int d) {
//	printf("--- %d\n", d);
	if (R[0] == 0) {
		sort(out, out+d);
		for (int i=0; i<16; ++i) {
			for (int j=0; j<16; ++j) printf("%c", getc(out[i*16+j]));
			puts("");
		}
		return true;
	}
	int mn(INF), idx;
	for (int i=R[0]; i; i=R[i]) if (S[i] < mn) mn = S[i], idx = i;
	remove(idx);
	for (int i=D[idx]; i!=idx; i=D[i]) {
		out[d] = mp[i];
		for (int j=R[i]; j!=i; j=R[j]) remove(C[j]);
		if (dfs(d + 1)) return true;
		for (int j=L[i]; j!=i; j=L[j]) resume(C[j]);
	}
	resume(idx);
	return false;
}

int getb(int i, int j) {
	int r((i - 1) >> 2), c((j - 1) >> 2);
	return (r << 2) + c;
}

void add(int i, int j, int k) {
	int r(((i - 1) << 8) + ((j - 1) << 4) + k);
	connect(r, ((i - 1) << 4) + j);
	connect(r, 256 + ((i - 1) << 4) + k);
	connect(r, 512 + ((j - 1) << 4) + k);
	connect(r, 768 + (getb(i, j) << 4) + k);
}

bool input() {
	for (int i=1; i<=16; ++i) if (1 != scanf("%s", s[i] + 1)) return false;
	return true;
}

int main() {
	int i, j, k;
	int x, y;
	int m, n;
	
//	freopen("d:\\in.txt", "r", stdin);
//	freopen("d:\\out.txt", "w", stdout);
	input();
	while (true) {
		init(1<<10);
		for (i=1; i<=16; ++i) {
			for (j=1; j<=16; ++j) {
				if (s[i][j] != '-') add(i, j, s[i][j]-'A'+1);
				else for (k=1; k<=16; ++k) add(i, j, k);
			}
		}
		dfs(0);
		if (!input()) break;
		puts("");
	}
	return 0;
}