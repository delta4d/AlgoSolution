#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 128;

int f[MAXN<<1];
int t[MAXN], w[MAXN];

int main() {
	int n, st = 0, sw = 0;

	scanf("%d", &n);
	for (int i=0; i<n; ++i) scanf("%d%d", t+i, w+i), st += t[i], sw += w[i];
	memset(f, -1, sizeof(f));
	f[0] = 0;
	for (int i=0; i<n; ++i) {
		for (int j=st; j>=0; --j) if (f[j] != -1 && j + t[i] <= st) {
			int k = j + t[i];
			if (f[k] == -1) f[k] = f[j] + w[i];
			else f[k] = max(f[k], f[j] + w[i]);
		}
	}
	for (int i=0; i<=st; ++i) if (sw - f[i] <= i) {
		printf("%d\n", i);
		break;
	}

	return 0;
}

// 3497319	 Apr 9, 2013 8:42:08 PM	delta_4d	 294B - Shaass and Bookshelf	 GNU C++	Accepted	15 ms	0 KB
