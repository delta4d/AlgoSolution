#include <set>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef set<int> SI;
typedef SI::iterator SII;

const int MAXN = 100001;

int a[MAXN], b[MAXN];
SI res1, res2;

int main() {
    int i, j, k;
    int m, n;
    int diff;
    //freopen("f:\\in.txt", "r", stdin);
    scanf("%d", &n);
    for (i=0; i<n; ++i) scanf("%d", a+i);
    for (i=0; i<n; ++i) scanf("%d", b+i);
    a[n] = a[0], b[n] = b[0];
    diff = 0;
    for (i=0; i<n; ++i) {
        if (diff < 0) {
            res1.clear();
            diff = 0;
        }
        if (diff == 0) {
            res1.insert(i);
        }
        diff += a[i] - b[i];
    }
    diff = 0;
    for (i=n; i>0; --i) {
        if (diff < 0) {
            res2.clear();
            diff = 0;
        }
        if (diff == 0) {
            res2.insert(i==n?0:i);
        }
        diff += a[i] - b[i-1];
    }
    res1.insert(res2.begin(), res2.end());
    printf("%d\n", res1.size());
    k = 1;
    for (SII it=res1.begin(); it!=res1.end(); ++it) {
        printf("%d%s", *it+1, k==res1.size()?"\n":" ");
        ++k;
    }
    return 0;
}

// 331007	 Mar 11, 2011 7:01:00 PM	delta_4d	 E - Petya and Post	 GNU C++	Accepted	 170 ms	 5300 
