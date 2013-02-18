#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 1024;

int p[] = {2, 5};
int f[MAXN][MAXN], dp[MAXN][MAXN];
bool R[MAXN][MAXN];
vector <char> path;

inline int fcnt(int x, int y) {
	int ret(0);
	for (; x%y==0; ++ret,x/=y);
	return ret;
}

int main() {
	int i, j, k;
	int x, y;
	int zf(0), zx, zy;
	int m, n;

	scanf("%d", &n);
	for (i=0; i<n; ++i) for (j=0; j<n; ++j) {
		scanf("%d", f[i]+j);
		if (f[i][j] == 0) f[i][j] = 10, zf = 1, zx = i, zy = j;
	}
	for (m=INF,k=0; k<2; ++k) {
		for (dp[0][0]=fcnt(f[0][0], p[k]),i=1; i<n; ++i) dp[0][i] = dp[0][i-1] + fcnt(f[0][i], p[k]), R[0][i] = true;
		for (dp[0][0]=fcnt(f[0][0], p[k]),i=1; i<n; ++i) dp[i][0] = dp[i-1][0] + fcnt(f[i][0], p[k]), R[i][0] = false;
		for (i=1; i<n; ++i) for (j=1; j<n; ++j) {
			if (dp[i-1][j] < dp[i][j-1]) {
				dp[i][j] = dp[i-1][j] + fcnt(f[i][j], p[k]);
				R[i][j] = false;
			} else {
				dp[i][j] = dp[i][j-1] + fcnt(f[i][j], p[k]);
				R[i][j] = true;
			}
		}
		if (dp[n-1][n-1] < m) {
			path.clear();
			m = dp[n-1][n-1];
			x = n - 1, y = n - 1;
			while (true) {
				if (R[x][y]) {
					path.push_back('R');
					--y;
				} else {
					path.push_back('D');
					--x;
				}
				if (!x && !y) break;
			}
		}
	}	
	if (zf && m > 1) {
		m = 1;
		path.clear();
		for (i=n-1; i>zy; --i) path.push_back('R');
		for (i=n-1; i>0; --i) path.push_back('D');
		for (i=zy; i>0; --i) path.push_back('R');
	}
	printf("%d\n", m);
	for (i=path.size()-1; i>=0; --i) printf("%c", path[i]); puts("");

	return 0;
}

//#		When						Who			 Problem					 Lang		Verdict		Time	Memory
//2902754	 Jan 10, 2013 7:10:59 PM	delta_4d	 B - The least round way	 GNU C++	Accepted	703 ms	9236 KB
