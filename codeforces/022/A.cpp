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
    for (i=0; i<n; ++i) scanf("%d", f+i);
    sort(f, f+n);
    for (i=1; i<n; ++i) if (f[i] > f[0]) break;
    if (i < n) printf("%d\n", f[i]);
    else puts("NO");
    return 0;
}

// 912726	 Dec 1, 2011 3:46:00 PM	delta_4d	 A - Second Order Statistics	 GNU C++	Accepted	 30 ms	 1300 KB
