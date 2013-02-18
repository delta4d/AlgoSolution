#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 32;

int x[MAXN], y[MAXN];
int d[MAXN];

int main() {
    int i, j, k;
    int m, n;
    int xx = 0, yy = 0;
    
    scanf("%d %d", &m, &n);
    for (i=0; i<m; ++i) {
        scanf("%d %d", x+i, y+i);
        xx += x[i], yy += y[i];
    }
    if (xx <= n && n <= yy) {
        puts("YES");
        for (i=0; i<m; ++i) d[i] = x[i];
        n -= xx;
        while (n) {
            for (i=0; i<m; ++i) if (d[i] < y[i]) {
                ++d[i], --n;
                break;
            }
        }
        for (i=0; i<m; ++i) printf("%d ", d[i]);
    } else {
        puts("NO");
    }
    
    return 0;
}

//#	When	Who	Problem	Lang	Verdict	Time	Memory
//912362	 Dec 1, 2011 10:52:49 AM	delta_4d	 B - Before an Exam	 GNU C++	Accepted	 10 ms	 1300 KB
