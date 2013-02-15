#include <cstdio>
#include <cstring>
using namespace std;

const int MAXNL = 10000;
int f[3][MAXNL];
int offset[MAXNL];
char buff[MAXNL], out[MAXNL];

inline int find(const int pos, const int key, const int n) {
	int i, j, k, t;
	for (i=0; i<n; ++i) {
		k = i - offset[pos];
		k = k < 0 ? k + n : k;
		t = f[pos][k] + i;
		if (t < 0) t += n;
		if (t >= n) t -= n;
		if (t == key) return i;
	}
}

inline void update_offset(int c, const int n) {
	int i, j, k;
	offset[0] = c % n;
	offset[1] = c / n;
	offset[1] %= n;
	offset[2] = c / (n * n);
	offset[2] %= n;
}

void gao(const int n) {
	int i, j, k;
	int c, r, s, t;
	int len(strlen(out)), num;
	memset(offset, 0, sizeof(offset));
	for (k=len-1; k>=0; --k) {
		update_offset(k, n);
		for (i=2; i>=0; --i) {
			t = find(i, out[k]-'A', n);
			out[k] = t + 'A';
		}
	}
	for (i=0; i<len; ++i) out[i] = out[i] - 'A' + 'a';
	out[i] = '\0';
}

int main() {
	int m, n, cn(0);
	int i, j, k;
	//freopen("f:\\in.txt", "r", stdin);
	//freopen("f:\\out.txt", "w", stdout);
	scanf("%d", &n);
	while (true) {
		for (i=0; i<3; ++i) {
			scanf("%s", buff);
			for (k=0; k<n; ++k) f[i][k] = buff[k] - 'A' - k;
		}
		printf("Enigma %d:\n", ++cn);
		scanf("%d", &m);
		for (i=0; i<m; ++i) {
			scanf("%s", out);
			gao(n);
			puts(out);
		}
		scanf("%d", &n);
		if (n == 0) break;
		puts("");
	}
	return 0;
}