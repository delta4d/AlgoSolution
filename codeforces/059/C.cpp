#include <cstdio>
#include <cstring>
using namespace std;

char buff[10];
char s[10][10];
int x[10], y[10];
int n;

inline bool right() {
    int i, j, k;
    int xx, yy;
    int index[2][10];
    bool visit[2][10];
    for (i=0; i<4; ++i) {
        for (j=0; j<4; ++j) {
            if (i == j) continue;
            if (buff[i] == buff[j]) return false;
        }
    }
    for (k=0; k<n; ++k) {
        xx = 0, yy = 0;
        memset(visit, false, sizeof(visit));
        for (i=0; i<4; ++i) {
            visit[0][s[k][i]-'0'] = true;
            index[0][s[k][i]-'0'] = i;
            visit[1][buff[i]-'0'] = true;
            index[1][buff[i]-'0'] = i;
        }
        for (i=0; i<10; ++i) {
            if (visit[0][i] && visit[1][i]) {
                if (index[0][i] == index[1][i]) ++xx;
                else ++yy;
            }
        }
        if (xx != x[k] || yy != y[k]) return false;
    }
    return true;
}

int main() {
    int i, j, k;
    int m;
    int cnt;
    //freopen("f:\\in.txt", "r", stdin);
    while (scanf("%d", &n) == 1) {
        for (i=0; i<n; ++i) scanf("%s %d %d", s[i], x+i, y+i);
        cnt = 0;
        for (i=0; i<10000; ++i) {
            sprintf(buff, "%04d", i);
            if (right()) m = i, ++cnt;
            if (cnt >= 2) break;
        }
        if (cnt >= 2) puts("Need more data");
        else if (cnt == 1) printf("%04d\n", m);
        else puts("Incorrect data");
    }
    return 0;
}

// 311382	2011-02-28 19:59:00	delta_4d	C - Bulls and Cows	GNU C++	Accepted	30 ms	1300 KB
