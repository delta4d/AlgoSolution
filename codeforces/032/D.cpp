#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 322;
int n, m, index;
char graph[MAXN][MAXN];
struct star {
    int x, y;
    int r;
}f;

inline bool is_star(const int x, const int y, const int k) {
    if (x - k < 1) return false;
    if (x + k > n) return false;
    if (y - k < 1) return false;
    if (y + k > m) return false;
    if (graph[x-k][y] != '*') return false;
    if (graph[x+k][y] != '*') return false;
    if (graph[x][y-k] != '*') return false;
    if (graph[x][y+k] != '*') return false;
    return true;
}

int main() {
    int i, j, k;
    int x, y, r;
    int num, l;
    //freopen("f:\\in.txt", "r", stdin);
    while (scanf("%d %d %d", &n, &m, &index) != EOF) {
        for (i=1; i<=n; ++i) {
            scanf("%s", graph[i]+1);
        }
        //????
        num = 0;
        l = min(m, n);
        for (k=1; k<=l; ++k) {
            for (i=2; i<=n-1; ++i) {
                for (j=2; j<=m-1; ++j) {
                    if (graph[i][j] == '*') {
                        //if (!is_legal(i, j, k)) goto next; 
                        if (is_star(i, j, k)) {
                            f.x = i;
                            f.y = j;
                            f.r = k;
                            ++num;
                            if (num == index) goto done;
                        }
                    }
                }
            }
        }
done:
        if (num < index) {
            puts("-1");
        } else {
            x = f.x, y = f.y, r = f.r;
            printf("%d %d\n", x, y);
            printf("%d %d\n", x-r, y);
            printf("%d %d\n", x+r, y);
            printf("%d %d\n", x, y-r);
            printf("%d %d\n", x, y+r);
        }
    }
    return 0;
}

// 138930	2010-10-02 12:44:18	delta_4d	D - Constellation	GNU C++	Accepted	80 ms	1400 KB
