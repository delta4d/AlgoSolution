#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char s[8][8];
bool find_one;

bool win(char x) {
    int i, j;
    for (i=0; i<3; ++i) {
        for (j=0; j<3; ++j) if (s[i][j] != x) break;
        if (j == 3) return true;
    }
    for (i=0; i<3; ++i) {
        for (j=0; j<3; ++j) if (s[j][i] != x) break;
        if (j == 3) return true;
    }
    return s[0][0] == s[1][1] && s[1][1] == s[2][2] && s[2][2] == x
        || s[0][2] == s[1][1] && s[1][1] == s[2][0] && s[2][0] == x;
}

int main() {
    int i, j, k;
    int c1(0), c2(0);
    bool w1, w2;

    for (i=0; i<3; ++i) scanf("%s", s[i]);
    for (i=0; i<3; ++i) for (j=0; j<3; ++j) c1 += s[i][j] == 'X', c2 += s[i][j] == '0';
    w1 = win('X'), w2 = win('0');

    if (c1 != c2 && c1 != c2 + 1 || w1 && w2) { puts("illegal"); return 0; }
    if (w1) if (c1 != c2 + 1) { puts("illegal"); return 0; }
    if (w2) if (c1 != c2) { puts("illegal"); return 0; }
    if (w1) puts("the first player won");
    else if (w2) puts("the second player won");
    else if (c1 + c2 == 9) puts("draw");
    else if ((c1 + c2) & 1) puts("second");
    else puts("first");

    return 0;
}


//#		When	Who	Problem	Lang	Verdict	Time	Memory
//2887074	 Jan 8, 2013 7:54:28 PM	delta_4d	 C - Tic-tac-toe	 GNU C++	Accepted	 15 ms	 0 KB
