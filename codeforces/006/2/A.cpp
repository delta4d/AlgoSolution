nclude <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int x[4];

int main() {
    int i, j, k;
    int m, n;
    int s[3];
    bool tri(false), seg(false);
    
    for (i=0; i<4; ++i) scanf("%d", x+i);
    sort(x, x+4);
    for (i=0; i<4; ++i) {
        for (k=j=0; j<4; ++j) {
            if (j == i) continue;
            s[k++] = x[j];
        }
        if (s[0] + s[1] > s[2]) tri = true;
        else if (s[0] + s[1] == s[2]) seg = true;
    }
    if (tri) puts("TRIANGLE");
    else if (seg) puts("SEGMENT");
    else puts("IMPOSSIBLE");
    
    return 0;
}

// 912380	 Dec 1, 2011 11:08:10 AM	delta_4d	 A - Triangle	 GNU C++	Accepted	 30 ms	 1300 KB
