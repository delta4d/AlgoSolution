nclude <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 128;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
int m, n;
char c[2];
char s[MAXN][MAXN];
bool cnt[26];

inline bool in(const int x, const int y) {
    return 0 <= x && x < m && 0 <= y && y < n;
}

int main() {
    int i, j, k;

    scanf("%d%d%s", &m, &n, c);
    for (i=0; i<m; ++i) scanf("%s", s[i]);
    
    for (i=0; i<m; ++i) for (j=0; j<n; ++j) if (s[i][j] == c[0]) {
        for (k=0; k<4; ++k) {
            int x = i + dx[k], y = j + dy[k];
            if (!in(x, y) || s[x][y] == c[0] || s[x][y] == '.') continue;
            cnt[s[x][y]-'A'] = true;
        }   
    }
    for (i=j=0; i<26; ++i) j += cnt[i];
    printf("%d\n", j);

    return 0;
}

// 3034014	 Jan 29, 2013 7:10:14 PM	delta_4d	 B - President's Office	 GNU C++	Accepted	 15 ms	 0 KB
