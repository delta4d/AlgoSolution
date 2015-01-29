/**************************************************************
    Problem: 3295
    User: delta
    Language: C++
    Result: Accepted
    Time:5160 ms
    Memory:119960 kb
****************************************************************/
 
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
 
int const N = 1e5 + 10;
 
int n, q, next_node = 1;
int a[N], p[N], inv[N];
struct node {
    int sum, left, right;
    node(int s=0, int l=0, int r=0):sum(s), left(l), right(r) {}
} f[N*100];
struct FenwickTree {
    int a[N];
    void init() { memset(a, 0, sizeof(a)); }
    void add(int p) { for (int i=p; i<=n; i+=i&-i) ++a[i]; }
    int sum(int p) { int r = 0; for (int i=p; i>0; i-=i&-i) r += a[i]; return r; }
} ft;
struct FenwickSegmentTree {
    int root[N];
    void add(int r, int p, int x) {
        for (int i=r; i<=n; i+=i&-i) root[i] = insert(root[i], 1, n, p, x);
    }
    int sum(int r1, int r2, int a, int b) {
        int ret = 0;
        for (int i=r1,j=r2; i>0||j>0; i-=i&-i,j-=j&-j) ret += query(root[i], root[j], 1, n, a, b);
        return ret;
    }
    int insert(int r, int L, int R, int p, int x) {
        if (R < p || L > p || L > R) return r;
        int cur = next_node++;
        f[cur] = f[r];
        if (L == R) {
            f[cur].sum += x;
        } else {
            int M = L + (R - L) / 2;
            f[cur].left = insert(f[r].left, L, M, p, x);
            f[cur].right = insert(f[r].right, M+1, R, p, x);
            f[cur].sum = f[f[cur].left].sum + f[f[cur].right].sum;
        }
        return cur;
    }
    int query(int r1, int r2, int L, int R, int a, int b) {
        if (R < a || L > b || L > R || a > b) return 0;
        if (a <= L && R <= b) return f[r2].sum - f[r1].sum;
        int M = L + (R - L) / 2;
        return query(f[r1].left, f[r2].left, L, M, a, b)
            + query(f[r1].right, f[r2].right, M+1, R, a, b);
    }
} fst;
 
int main() {
    scanf("%d%d", &n, &q);
    long long rev = 0;
    for (int i=1; i<=n; ++i) {
        scanf("%d", a+i);
        p[a[i]] = i;
        inv[i] = ft.sum(n) - ft.sum(a[i]);
        rev += inv[i];
        ft.add(a[i]);
    }
    ft.init();
    for (int i=n; i>=1; --i) {
        inv[i] += ft.sum(a[i]-1);
        ft.add(a[i]);
    }
    for (int x; q--; ) {
        printf("%lld\n", rev);
        scanf("%d", &x), x = p[x];
        rev -= inv[x] - fst.sum(0, x-1, a[x]+1, n) - fst.sum(x, n, 1, a[x]-1);
        fst.add(x, a[x], 1);
    }
    return 0;
}
