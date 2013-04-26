nclude <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 100086;

char s[MAXN], t[MAXN];
char ss[2][MAXN];

void rev() {
    int i, j, k;
    k = strlen(s);
    for (i=0; i<k; ++i) t[i] = s[k-1-i];
    t[i] = '\0';
}

int main() {
    int i, j, k;
    int m, n;
    bool forward(false), backward(false);
    char *cp;
    
    scanf("%s %s %s", s, ss[0], ss[1]);
    cp = strstr(s, ss[0]);
    if (cp != NULL) cp = strstr(cp+strlen(ss[0]), ss[1]);
    if (cp != NULL) forward = true;
    rev();
    cp = strstr(t, ss[0]);
    if (cp != NULL) cp = strstr(cp+strlen(ss[0]), ss[1]);
    if (cp != NULL) backward = true;
    
    if (forward && backward) puts("both");
    else if (forward) puts("forward");
    else if (backward) puts("backward");
    else puts("fantasy");
    return 0;
}

// 954974	 Dec 14, 2011 1:31:58 PM	delta_4d	 A - Train and Peter	 GNU C++	Accepted	 50 ms	 1700 KB
