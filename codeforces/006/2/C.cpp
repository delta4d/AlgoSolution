nclude <cstdio>
using namespace std;

const int MAXN = 100086;

int x[MAXN];

int main() {
    int i, j, k;
    int m, n;
    int a, b;
    int pa, pb;
    int sa, sb;

    scanf("%d", &n);
    for (i=0; i<n; ++i) scanf("%d", x+i);
    pa = 0, pb = n - 1, sa = false, sb = false;
    while (pa < pb) {
        if (sa <= sb) sa += x[pa], ++pa;
        else sb += x[pb], --pb;
    }
    if (pa == pb) {
        if (sa <= sb) ++pa;
        else --pb;
    }
    a = pa, b = n - pb - 1;
    printf("%d %d\n", a, b);

    return 0;
}

// 3034216	 Jan 29, 2013 8:00:44 PM	delta_4d	 C - Alice, Bob and Chocolate	 GNU C++	Accepted	 46 ms	 400 KB
