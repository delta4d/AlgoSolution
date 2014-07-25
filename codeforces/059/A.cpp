#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct node {
    char name[20];
    int index;
    int position;
} f[100];

inline bool cmp(const node &a, const node &b) {
    if (a.position != b.position) return a.position < b.position;
    return a.index < b.index;
}

int main() {
    int i, j, k;
    int m, n;
    char s[20];
    //freopen("f:\\in.txt", "r", stdin);
    scanf("%d", &n);
    for (i=0; i<n; ++i) {
        scanf("%s %s", f[i].name, s);
        f[i].index = i;
        if (s[0] == 'r') f[i].position = 1;
        else if (s[0] == 'w' || s[1] == 'h') f[i].position = 2;
        else if (s[0] == 'm') f[i].position = 3;
        else f[i].position = 4;
    }
    sort(f, f+n, cmp);
    for (i=0; i<n; ++i) puts(f[i].name);
    return 0;
}

// 309787	2011-02-28 19:08:03	delta_4d	A - Sinking Ship	GNU C++	Accepted	10 ms	1300 KB
