#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const double eps = 1e-10;
const int MAXN = 10086;

vector <int> f[MAXN];
double E[MAXN], K[MAXN];
double a[MAXN], b[MAXN], c[MAXN];

bool gao(int parent, int root) {
    int i, j, k;
    int cnt(0);
    double sa(0), sb(0), sc(0);
    
    for (i=0; i<f[root].size(); ++i) {
        if (f[root][i] == parent) continue;
        k = f[root][i], ++cnt;
        if (!gao(root, k)) return false;
        sa += a[k], sb += b[k], sc += c[k] + 1;
    }
    double p = (1 - K[root] - E[root]) / (cnt + (parent != -1));
    if (cnt == 0) {
        a[root] = K[root];
        b[root] = p;
        c[root] = p;
    } else {
        sb = 1 - sb * p;
        if (fabs(sb) < eps) return false;
        a[root] = (sa * p + K[root]) / sb;
        b[root] = (p / sb) * (parent != -1);
        c[root] = (sc * p + p * (parent != -1)) / sb;
    }
    return true;
}

int main() {
    int i, j, k;
    int m, n;
    int tc, cn(0);
    int x, y;
    
//  freopen("in.txt", "r", stdin);
    scanf("%d", &tc);    
    while (tc--) {
        scanf("%d", &n);
        for (i=0; i<n; ++i) f[i].clear();
        for (i=1; i<n; ++i) {
            scanf("%d %d", &x, &y);
            --x, --y;
            f[x].push_back(y);
            f[y].push_back(x);
        }
        for (i=0; i<n; ++i) scanf("%lf %lf", K+i, E+i), K[i] /= 100, E[i] /= 100;
        printf("Case %d: ", ++cn);
        if (!gao(-1, 0) || fabs(a[0] - 1) < eps) puts("impossible");
        else printf("%lf\n", c[0] / (1 - a[0]));
    }
    return 0;
}