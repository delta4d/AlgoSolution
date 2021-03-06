#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 100000 + 86;

char s[MAXN];
unsigned int f[2][MAXN];

int main() {
	int n, m;

	scanf("%d%s", &n, s+1);
	if (n & 1) return puts("0"), 0;
	int c = 0, t = 1;
	m = n >> 1, f[c][0] = 1;
	for (int i=0; i<n; ++i,c=t) {
		t = c ^ 1;
		int k = i > m ? n - i : i;
		for (int j=c; j<=k && j<=m; f[c][j]=0,j+=2) if (f[c][j]) {
			if (s[i+1] == '?') {
				f[t][j+1] += 25 * f[c][j];
				if (j) f[t][j-1] += f[c][j];
			} else {
				f[t][j+1] += f[c][j];
			}
		}
	}
	printf("%u\n", f[t][0]);

	return 0;
}

// 3851331	 Jun 9, 2013 8:05:52 PM	delta_4d	 E - Sereja and Squares	 GNU C++	Accepted	3781 ms	856 KB
