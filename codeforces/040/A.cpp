#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 128;

char s[MAXN], t[MAXN];

int main() {
    int i, j, k;
    int m, n;
    int ls, lt;
    
    scanf("%s %s", s, t);
    ls = strlen(s), lt = strlen(t);
    if (ls != lt) { puts("NO"); return 0; } 
    for (i=0; i<ls; ++i) if (s[i] != t[ls-i-1]) break;
    puts(i<ls?"NO":"YES");

    return 0;
}

// 908726	2011-11-28 17:07:04	delta_4d	A - Translation	GNU C++	Accepted	30 ms	1300 KB
