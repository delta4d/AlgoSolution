#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 5001;
int d[MAXN];
int s[MAXN], t[MAXN];
bool graph[MAXN][MAXN];

inline bool r(const int x, const int y) {
    if (t[x] <= t[y] && t[x] > s[y]) return true;
    if (t[y] <= t[x] && t[y] > s[x]) return true;
    return false;
}

int main() {
    int i, j, k;
    int n, e;
    int res;
    //freopen("in.txt", "r", stdin);
    while (scanf("%d", &n) != EOF) {
        for (i=1; i<=n; ++i) {
            scanf("%d %d", s+i, t+i);
        }
        memset(graph, false, sizeof(graph));
        memset(d, 0, sizeof(d));
        e = k = res = 0;
        for (i=1; i<=n; ++i) {
            for (j=i+1; j<=n; ++j) {
                if (r(i, j)) {
                    ++d[i], ++d[j];
                    ++e;
                    graph[i][j] = graph[j][i] = true;
                }
            }
        }
        if (e == 0) {
            printf("%d\n", n);
            printf("%d", 1);
            for (i=2; i<=n; ++i) {
                printf(" %d", i);
            }
            puts("");
        } else {
            for (i=1; i<=n; ++i) {
                if (d[i] == e) {
                    if (e == 1) {
                        for (j=1; j<=n; ++j) {
                            if (graph[i][j]) {
                                puts("2");
                                printf("%d %d\n", i, j);
                                goto done;
                            }
                        }
                    } else {
                        puts("1");
                        printf("%d\n", i);
                        goto done;
                    }
                }
            }
            if (i == n + 1) puts("0");
        }
    done:;
    }
    return 0;
}

// 134501	 Sep 27, 2010 8:10:24 PM	delta_4d	 C - Schedule	 GNU C++	Accepted	 90 ms	 25800 KB
