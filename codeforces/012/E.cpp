#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 1024;
#define N(x) (((x) == n - 1) ? 1 : ((x) + 1))

int f[MAXN][MAXN];
bool v[MAXN][MAXN];

int main() {
	int n;

	scanf("%d", &n);

	for (int i=0; i<n; ++i) f[0][i] = f[i][0] = i, v[0][i] = v[i][i] = v[i][0] = true;
	for (int i=1; i+1<n; ++i) {
		int a = N(f[i][i-1]), b = N(f[i-1][i+1]);
		if (!v[i][b]) a = b;
		f[i][i+1] = f[i+1][i] = a, v[i][a] = v[i+1][a] = true;
		for (int j=i+2; j<n; ++j) {
			for (int k=f[i][j-1]; ; k=N(k)) {
				if (!v[i][k]) {
					v[i][k] = v[j][k] = true;
					f[i][j] = f[j][i] = k;
					break;
				}
			}
		}
	}
	for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) printf("%d%s", f[i][j], j==n-1?"\n":" ");

	return 0;
}

// 3789653	 May 29, 2013 8:39:09 AM	delta_4d	 E - Start of the session	 GNU C++	Accepted	 250 ms	 5100 KB
