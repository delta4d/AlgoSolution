#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 64;

char s[MAXN][MAXN];

int main() {
    int i, j, k;
    int m, n;
    int si, ti, sj, tj;
    
    scanf("%d %d", &m, &n);
    for (i=0; i<m; ++i) scanf("%s", s[i]);
    for (si=0; si<m; ++si) {
        for (j=0; j<n; ++j) if (s[si][j] == '*') break;
        if (j < n) break;
    }
    for (ti=m-1; ti>=0; --ti) {
        for (j=0; j<n; ++j) if (s[ti][j] == '*') break;
        if (j < n) break;
    }
    for (sj=0; sj<n; ++sj) {
        for (i=0; i<m; ++i) if (s[i][sj] == '*') break;
        if (i < m) break;
    }
    for (tj=n-1; tj>=0; --tj) {
        for (i=0; i<m; ++i) if (s[i][tj] == '*') break;
        if (i < m) break;
    }
    for (i=si; i<=ti; ++i) {
        for (j=sj; j<=tj; ++j) printf("%c", s[i][j]);
        puts("");
    }
    return 0;
}

// 935517	 Dec 8, 2011 3:39:21 PM	delta_4d	 A - Letter	 GNU C++	Accepted	 30 ms	 1300 KB
