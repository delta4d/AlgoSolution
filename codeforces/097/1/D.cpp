#include <set>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1024;
const int dx[] = {-1, 0, 1, 0, -1, 1, 1, -1};
const int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};

#define MP(x, y) make_pair((x), (y))

char s[MAXN][MAXN];
int m, n;
int res;
int tot;
int cc;
int sx, sy;
bool two;
int mark[MAXN][MAXN];
int val(2);
bool edge;

inline bool in(const int x, const int y) {
    return 0 <= x && x < m && 0 <= y && y < n;
}

void bfs(int x, int y) {
    int i, j, k;
    int tx, ty;
    
    if (x == 0 || x == m - 1 || y == 0 || y == n - 1) edge = true;
    s[x][y] = 'z';
    for (k=0; k<8; ++k) {
        tx = x + dx[k], ty = y + dy[k];
        if (!in(tx, ty)) continue;
        if (s[tx][ty] == '0') {
            bfs(tx, ty);
        } else if (s[tx][ty] == '1' && mark[tx][ty] != val) {
            ++cc, sx = tx, sy = ty;
            mark[tx][ty] = val;
        }
    }
}

void gao(int x, int y) {
    int i, j, k;
    int tx, ty;
    int cnt(0);
    
    ++tot;
    --mark[x][y];
    for (k=0; k<4; ++k) {
        tx = x + dx[k], ty = y + dy[k];
        if (!in(tx, ty)) continue;
        if (mark[tx][ty] == val || mark[tx][ty] + 1 == val) ++cnt;
        if (mark[tx][ty] == val) gao(tx, ty);
    }
    two &= (cnt == 2);
//  if (cnt != 2) printf("%d %d\n", x, y);
}

bool ok(int x, int y) {
    tot = 0, two = true;
    gao(x, y);
    return cc == tot && two;
}

int main() {
    int i, j, k;
    bool zero(false);
    
//  freopen("in.txt", "r", stdin);
    scanf("%d %d", &m, &n);
    for (i=0; i<m; ++i) scanf("%s", s[i]);
    for (i=0; i+1<m; ++i) for (j=0; j+1<n; ++j) if (s[i][j] == '1') {
        if (s[i][j+1]=='1' && s[i+1][j] == '1' && s[i+1][j+1]=='1') {
            res = 4;
            goto NEXT;
        }
    }
    NEXT:
    for (i=0; i<m; ++i) for (j=0; j<n; ++j) if (s[i][j] == '0') {
        zero = true;
        cc = 0;
        edge = false;
        bfs(i, j);
        if (!edge && ok(sx, sy)) res = max(res, cc);
        ++val, ++val;
    }
    if (zero) printf("%d\n", res);
    else printf("%d\n", m>1&&n>1?4:0);
    return 0;
}

// 948455	 Dec 10, 2011 8:44:37 AM	delta_4d	 D - Cycle	 GNU C++	Accepted	 110 ms	 53300 
