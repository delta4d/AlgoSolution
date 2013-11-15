#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 128;
const int two[11] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024};
int g[100][100];
int f[MAXN];
bool visit[MAXN];

void gao(const int x, const int n) {
    int i, j, k;
    int high, low;
    int cnt(0);
    int p(x);
    low = two[n] + 1 - two[f[x]];
//    printf("low: %d\n", low);
    memset(visit, false, sizeof(visit));
    visit[x] = true;
    for (i=1; i<=n; ++i) {
        p = (p + 1) >> 1;
//        printf("p: %d\n", p);
        if (!visit[g[i][p]]) {
            visit[g[i][p]] = true;
            ++cnt;
        }
    }
    high = cnt + 1;
    printf("Player %d can be ranked as high as %d or as low as %d.\n", x, high, low);
}
int main() {
    int i, j, k;
    int m, n;
    int x;
    
    for (i=0; i<10; ++i) g[0][i] = i;
    scanf("%d", &n);
    while (n != 0) {
        memset(f, 0, sizeof(f));
        for (i=1; i<=n; ++i) {
            for (j=1; j<=two[n-i]; ++j) {
                scanf("%d", &x);
//                printf("%d\n", x);
                ++f[x];
//                printf("x:%d f[x]:%d\n", x, f[x]);
                g[i][j] = x;
            }
        }
//        printf("f\n");
//        for (i=0; i<10; ++i) printf("%d %d\n", i, f[i]);
        scanf("%d", &m);
        for (i=0; i<m; ++i) {
            scanf("%d", &x);
            gao(x, n);
        }
        scanf("%d", &n);
        if (n != 0) puts("");
    }

    return 0;
}
