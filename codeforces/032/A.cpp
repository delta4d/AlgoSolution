#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 1001;
int f[MAXN];

inline int fabs(const int x, const int y) {
    int t(x-y);
    return t >= 0 ? t : -t;
}

int main() {
    int n, d;
    int i, j, k;
    int res;
    //freopen("f:\\in.txt", "r", stdin);
    while (scanf("%d %d", &n, &d) != EOF) {
        for (i=0; i<n; ++i) scanf("%d", f+i);
        res = 0;
        for (i=0; i<n; ++i) {
            for (j=i+1; j<n; ++j) {
                k = fabs(f[i], f[j]);
                if (k <= d) {
                    ++res;
                    ++res;
                }
            }
        }
        printf("%d\n", res);
    }
    return 0;
}

// 137664	2010-10-02 11:08:43	delta_4d	A - Reconnaissance	GNU C++	Accepted	30 ms	1300 KB
