#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 201;
char s[MAXN];
int p[MAXN];

int main() {
    int i, j, k;
    int len, n;
    int cp;
    //freopen("in.txt", "r", stdin);
    while (scanf("%s", s) != EOF) {
        len = strlen(s);
        k = 0;
        for (i=0; i<len; ++i) {
            if (s[i] == '@') {
                p[k] = i;
                ++k;
            }
        }
        if (k == 0 || p[0] == 0 || p[k-1] == len - 1) {
            puts("No solution");
            continue;
        }
        for (i=0; i<k-1; ++i) {
            if (p[i+1] - p[i] <= 2) break;
        }
        if (i < k - 1) {
            puts("No solution");
            continue;
        }
        cp = 0;
        for (i=0; i<k-1; ++i) {
            for (j=cp; j<=p[i]+1; ++j) {
                printf("%c", s[j]);
            }
            printf(",");
            cp = j;
        }
        for (j=cp; j<len; ++j) printf("%c", s[j]);
        puts("");
    }
    return 0;
}

// 135742	 Sep 28, 2010 7:46:49 AM	delta_4d	 B - Sysadmin Bob	 GNU C++	Accepted	 30 ms	 1300 KB
