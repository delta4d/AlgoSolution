#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;

int main() {
    int i, j, k;
    LL n, x, y, z;
    
    scanf("%I64d %I64d %I64d", &n, &x, &y);
    if (y < n) {
        puts("-1");
    } else {
        z = y - (n - 1);
        if (z * z + n - 1 >= x) {
            for (i=0; i<n-1; ++i) printf("1\n");
            printf("%I64d\n", z);
        } else {
            puts("-1");
        }
    }
    
    return 0;
}

// 657801	 Sep 3, 2011 4:06:31 PM	delta_4d	 A - Petya and Inequiations	 GNU C++	Accepted	 50 ms	 1300 KB
