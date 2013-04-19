#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 128;

int f[MAXN];

int main() {
    int i, j, k;
    int m, n;
    
    scanf("%d", &n);
    for (i=1; i<=n; ++i) scanf("%d", &k), f[k] = i;
    for (i=1; i<=n; ++i) printf("%d ", f[i]);
    return 0;
}

// 948593	 Dec 10, 2011 9:31:58 AM	delta_4d	 A - Presents	 GNU C++	Accepted	 30 ms	 1300 KB
