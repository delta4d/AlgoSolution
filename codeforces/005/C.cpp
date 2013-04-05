#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1000086;

char s[MAXN];
int h[MAXN];
int L[MAXN];

void gao(const int n, int &mx, int &tot) {
    if (n < mx) return;
    for (int i=0; i<n; ++i) L[i] = i;
    for (int i=0; i<n; ++i) {
        while (L[i] >= 1 && h[L[i]-1] >= h[i]) L[i] = L[L[i] - 1];
        int cc = i - L[i] + (h[i] != h[L[i]]);
        if (cc && cc % 2 == 0) {
            if (cc > mx) mx = cc, tot = 1;
            else if (cc == mx) ++tot;
        }
    }
}

int main() {
    int i, j, k;
    int m, n;
    int L, R, mx, tot;

    scanf("%s", s);

    for (tot=1,L=R=mx=i=n=0; s[i]; ++i) {
        s[i] == '(' ? ++L : ++R;
        if (L < R) {
            gao(n, mx, tot);
            L = R = n = 0;
        } else {
            h[n++] = L - R;
        }
    }   
    if (n) gao(n, mx, tot);
    printf("%d %d\n", mx, tot);

    return 0;
}

// 2910260	 Jan 13, 2013 10:48:33 AM	delta_4d	 C - Longest Regular Bracket Sequence	 GNU C++	Accepted	 46 ms	 8800 KB
