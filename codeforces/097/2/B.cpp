#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 16;

int a[MAXN], b[MAXN], c[MAXN];

void to3(int x, int sx[], int &px) {
    int i, j, k;
    px = 0;
    do {
        sx[px++] = x % 3;
        x /= 3;
    } while (x);
    --px;
}

int main() {
    int i, j, k;
    int m, n;
    int pa, pb(0), pc;
    int x, y, z;
    
    scanf("%d %d", &x, &z);
    to3(x, a, pa);
    to3(z, c, pc);
    j = max(pa, pc);
    for (k=0,i=j; i>=0; --i) k = k * 3 + (c[i] - a[i] + 99) % 3;
    printf("%d\n", k);
    return 0;
}

// 948658	 Dec 10, 2011 9:54:19 AM	delta_4d	 B - Ternary Logic	 GNU C++	Accepted	 30 ms	 1300 KB
