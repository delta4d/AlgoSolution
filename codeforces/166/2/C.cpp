#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 1000000 + 86;

vector <int> u[MAXN];
int out[MAXN];

int main() {
	int n, k;

	scanf("%d%d", &n, &k);

	if (k == 1 || n < k * 3) {
		puts("-1");
	} else {
		int i, j;
		for (i=0,j=1; i+1<k; i+=2,j+=6) {
			u[i].push_back(j); u[i].push_back(j+1); u[i].push_back(j+3);
			u[i+1].push_back(j+2); u[i+1].push_back(j+4); u[i+1].push_back(j+5);
		}
		if (i < k) {
			u[k-1].push_back(j), u[k-1].push_back(j+1);
			if (j + 3 <= n) u[k-1].push_back(j+3);
			else u[k-1].push_back(j+2), swap(u[k-1][u[k-1].size()-1], u[0][u[0].size()-1]);
		}
		for (int c=0,off=1,p=j; j<=n; ++j) {
			if (i < k && p + 3 <= n && j != p && j != p + 1 && j != p + 3) u[c].push_back(j);	
			if (i >= k) u[c].push_back(j);
			c += off;
			if (c < 0 || c >= k - 1) off = -off, c += off; 
		}
//		for (i=0; i<k; ++i) {
//			printf("%d: ", i);
//			for (j=0; j<u[i].size(); ++j) printf("%d ", u[i][j]);
//			puts("");
//		}
		for (i=0; i<k; ++i) for (j=0; j<u[i].size(); ++j) out[u[i][j]] = i + 1;
		for (i=1; i<=n; ++i) printf("%d%s", out[i], i==n?"\n":" ");
	}

	return 0;
}

// 3475541	 Apr 5, 2013 10:43:44 AM	delta_4d	 271C - Secret	 GNU C++	Accepted	 531 ms	 23600 KB
