#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 101;

char f[MAXN][MAXN];
int s[26];
int col, row;
int a, b, c, d;

inline void move_right(int &x, int &y) {
    ++y;
}

inline void move_left(int &x, int &y) {
    --y;
}

inline void move_down(int &x, int &y) {
    ++x;
}

inline void move_up(int &x, int &y) {
    --x;
}

inline bool in(int x, int y) {
    return x >= 0 && x < b && y >= 0 && y < a || x >= 0 && x < d && y >= a && y < a + c;
}

inline bool right(int x, int y) {
    return in(x, y+1);
}

inline bool down(int x, int y) {
    return in(x+1, y);
}

inline bool left(int x, int y) {
    return in(x, y-1);
}

inline bool up(int x, int y) {
    return in(x-1, y);
}

int main() {
    int i, j, k;
    int n;
    int x, y;
    int kaka;
    //freopen("f:\\in.txt", "r", stdin);
    //freopen("f:\\out.txt", "w", stdout);
    while (scanf("%d %d %d %d %d", &a, &b, &c, &d, &n) == 5) {
        col = a + c, row = max(b, d);
        for (i=0; i<n; ++i) scanf("%d", s+i);
        if (b >= d) {
            memset(f, '\0', sizeof(f));
            for (i=d; i<b; ++i) for (j=0; j<c; ++j) f[i][a+j] = '.';
            if (c % 2 == 0) {
                x = 0, y = a + c - 1;
                kaka = 0;
                for (k=0; k<n; ++k) {
                    for (i=0; i<s[k]; ++i) {
                        if (kaka == 0) {
                            f[x][y] = k + 'a';
                            if (!down(x, y)) {move_left(x, y); kaka^=1;}
                            else move_down(x, y);
                        } else {
                            f[x][y] = k + 'a';
                            if (!up(x, y)) {move_left(x, y); kaka^=1;}
                            else move_up(x, y);
                        }
                    }
                }
            } else {
                x = d - 1, y = a + c - 1;
                kaka = 0;
                for (k=0; k<n; ++k) {
                    for (i=0; i<s[k]; ++i) {
                        //printf("%d %d %c\n", x, y, k+'a');
                        if (kaka == 1) {
                            f[x][y] = k + 'a';
                            if (!down(x, y)) {move_left(x, y); kaka^=1;}
                            else move_down(x, y);
                        } else {
                            f[x][y] = k + 'a';
                            if (!up(x, y)) {move_left(x, y); kaka^=1;}
                            else move_up(x, y);
                        }
                    }
                }
            }
        } else {
            memset(f, '\0', sizeof(f));
            for (i=b; i<d; ++i) for (j=0; j<a; ++j) f[i][j] = '.';
            if (a % 2 == 0) {
                x = 0, y = 0;
                kaka = 0;
                for (k=0; k<n; ++k) {
                    for (i=0; i<s[k]; ++i) {
                        if (kaka == 0) {
                            f[x][y] = k + 'a';
                            if (!down(x, y)) {move_right(x, y); kaka^=1;}
                            else move_down(x, y);               
                        } else {
                            f[x][y] = k + 'a';
                            if (!up(x, y)) {move_right(x, y); kaka^=1;}
                            else move_up(x, y);
                        }
                    }
                }
            } else {
                x = b - 1, y = 0;
                kaka = 0;
                for (k=0; k<n; ++k) {
                    for (i=0; i<s[k]; ++i) {
                        if (kaka == 1) {
                            f[x][y] = k + 'a';
                            if (!down(x, y)) {move_right(x, y); kaka^=1;}
                            else move_down(x, y);
                        } else {
                            f[x][y] = k + 'a';
                            if (!up(x, y)) {move_right(x, y); kaka^=1;}
                            else move_up(x, y);                         
                        }
                    }
                }
            }
        }
        puts("YES");
        for (i=0; i<max(b, d); ++i) {
            puts(f[i]);
            //printf("%d\n", strlen(f[i]));
        }
    }
    return 0;
}

// 312824	2011-03-01 05:31:41	delta_4d	D - Dividing Island	GNU C++	Accepted	30 ms	1300 KB
