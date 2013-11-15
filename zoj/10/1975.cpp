#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const char top[] = " /\\";
const char bottom[] = "/__\\";
const char blank[] = "    ";
const int n2[] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048};

char f[512][512];

inline void gao() {
	int i, j, k;
	for (i=0; i<512; ++i) f[i][0] = f[i][i] = 1;
	for (i=1; i<512; ++i) for (j=1; j<i; ++j) f[i][j] = f[i-1][j] ^ f[i-1][j-1];
}

inline void print(const int n, const char x) {
	for (int i=0; i<n; ++i) printf("%c", x);
}

void draw(const int n) {
	int i, j, k;
	int tot(n2[n]-2);
	for (k=0; k<n2[n-1]; ++k) {
		print(tot, ' ');
		for (i=0; i<=k; ++i) {
			if (f[k][i]) {
				printf("%s", top);
				if (i < k) printf(" ");
			} else {
				printf("%s", blank);
			}
		}
		puts("");
		print(tot, ' ');
		for (i=0; i<=k; ++i) {
			if (f[k][i]) printf("%s", bottom);
			else printf("%s", blank);
		}
		puts("");
		tot -= 2;
	}
	puts("");
}

int main() {
	int n;
	gao();
	//freopen("f:\\in.txt", "r", stdin);
	//freopen("f:\\out.txt", "w", stdout);
	while (scanf("%d", &n), n) draw(n);
	return 0;
}