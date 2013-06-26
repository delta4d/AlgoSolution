#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

const int MAXN = 101;
int x[MAXN];


int main() {
	int i, j, k;
	int n;
	int a, b, c;
	bool find;
	//freopen("in.txt", "r", stdin);
	while (scanf("%d", &n) != EOF) {
		find = false;
		for (i=1; i<=n; ++i) scanf("%d", x+i);
		//qsort(x+1, n, sizeof(x[0]), cmp);
		for (i=1; i<=n; ++i) {
			for (j=1; j<=n; ++j) {
				if (j == i) continue;
				for (k=1; k<=n; ++k) {
					if (k == i || k == j) continue;
					if (x[i] == x[j] + x[k]) {
						c = i, a = j, b = k;
						find = true;
						goto done;
					}
				}
			}
		}
	done:
		if (find) printf("%d %d %d\n", c, a, b);
		else puts("-1");	
	}
	return 0;
}

// 132944	 Sep 27, 2010 7:10:03 PM	delta_4d	 A - Worms Evolution	 GNU C++	Accepted	 30 ms	 1300 KB
