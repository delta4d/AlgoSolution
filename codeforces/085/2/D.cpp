#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 100086;

vector <int> fac;
//vector <int> f[MAXN];
int f[MAXN];

bool find_one(int L, int R, int v) {
    if (L > R) return false;
    if (f[v] == -1) return false;
    return f[v] >= L;
}

int main() {
    int i, j, k;
    int m, n;
    int cc;
    int x, y;
    
    //freopen("in.txt", "r", stdin);
    memset(f, -1, sizeof(f));
    scanf("%d", &n);
    for (int c=0; c<n; ++c) {
        scanf("%d %d", &x, &y);
        fac.clear();
        cc = 0;
        for (i=1; i*i<=x; ++i) {
            if (x % i == 0) {
                fac.push_back(i);
                if (!find_one(c-y, c-1, i)) ++cc;
                if (i * i != x) {
                    fac.push_back(x / i);
                    if (!find_one(c-y, c-1, x / i)) ++cc;
                }
            }
        }
        for (i=0; i<fac.size(); ++i) {
            f[fac[i]] = c;
        }
        printf("%d\n", cc);
    }
    
    return 0;
}

// 662580	 Sep 3, 2011 5:21:13 PM	delta_4d	 B - Petya and Divisors	 GNU C++	Accepted	 480 ms	 1700 KB
