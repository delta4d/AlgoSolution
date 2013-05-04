#include <cstdio>
#include <algorithm>
using namespace std;

int gao(int b, int n) {
    int ret(0);
    while (n) {
        ret += n % b;
        n /= b;
    }
    return ret;
}

int main() {
    int i, j, k;
    int m, n;
    int tot(0);
    
    scanf("%d", &n);
    for (i=2; i<n; ++i) tot += gao(i, n);
    k = __gcd(n-2, tot);
    printf("%d/%d\n", tot/k, (n-2)/k);
    
    return 0;
}

// 911397	 Nov 30, 2011 3:31:39 PM	delta_4d	 A - Numbers	 GNU C++	Accepted	 30 ms	 1300 KB
