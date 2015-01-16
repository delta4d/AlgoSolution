/**************************************************************
    Problem: 2653
    User: delta
    Language: C++
    Result: Accepted
    Time:2596 ms
    Memory:6908 kb
****************************************************************/
 
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
 
int const N = 2e4 + 10;
int const INF = 0x3f3f3f3f;
 
struct node {
    int sum, lmn, rmn;
    int left, right;
    node(int s=0, int ln=INF, int rn=INF, int l=0, int r=0):
        sum(s), lmn(ln), rmn(rn), left(l), right(r) {}
} f[N*15];
 
int root[N], next_node;
pair <int, int> a[N];
 
void up(node &ret, node const &lhs, node const &rhs) {
    ret.sum = lhs.sum + rhs.sum;
    ret.lmn = min(lhs.lmn, lhs.sum+rhs.lmn);
    ret.rmn = min(rhs.rmn, rhs.sum+lhs.rmn);
}
 
int build(int L, int R) {
    int cur = next_node++;
    if (L == R) {
        f[cur].sum = -1;
        f[cur].lmn = -1, f[cur].rmn = -1;
        f[cur].left = 0, f[cur].right = 0;
    } else {
        int M = L + (R - L) / 2;
        f[cur].left = build(L, M);
        f[cur].right = build(M+1, R);
        up(f[cur], f[f[cur].left], f[f[cur].right]);
    }
    return cur;
}
 
int insert(int r, int L, int R, int p) {
    if (R < p || L > p || L > R) return r;
    int cur = next_node++;
    f[cur] = f[r];
    if (L == R) {
        f[cur].sum = 1;
        f[cur].lmn = 1, f[cur].rmn = 1;
    } else {
        int M = L + (R - L) / 2;
        f[cur].left = insert(f[r].left, L, M, p);
        f[cur].right = insert(f[r].right, M+1, R, p);
        up(f[cur], f[f[cur].left], f[f[cur].right]);
    }
    return cur;
}
 
node query(int r, int L, int R, int a, int b) {
    if (R < a || L > b || L > R || a > b) return node();
    if (a <= L && R <= b) return f[r];
    int M = L + (R - L) / 2;
    node lq = query(f[r].left, L, M, a, b);
    node rq = query(f[r].right, M+1, R, a, b);
    node ret;
    up(ret, lq, rq);
    return ret;
}
 
int main() {
    int n, q;
    scanf("%d", &n);
    for (int i=0,x; i<n; ++i) {
        scanf("%d", &x);
        a[i].first = x, a[i].second = i;
    }
    sort(a, a+n);
    root[0] = build(0, n-1);
    for (int i=1; i<=n; ++i) {
        root[i] = insert(root[i-1], 0, n-1, a[i-1].second);
    }
    scanf("%d", &q);
    for (int a,b,c,d,x=0; q--; ) {
        scanf("%d%d%d%d", &a, &b, &c, &d);
        int e[] = {(a+x)%n, (b+x)%n, (c+x)%n, (d+x)%n};
        sort(e, e+4);
        a = e[0], b = e[1], c = e[2], d = e[3];
        int left = 0, right = n - 1, mid = -1, pos = -1;
        while (left <= right) {
            mid = left + (right - left) / 2;
            int sum = query(root[mid+1], 0, n-1, a, b).rmn
                    + query(root[mid+1], 0, n-1, b+1, c-1).sum
                    + query(root[mid+1], 0, n-1, c, d).lmn;
            if (sum <= 0) left = mid + 1;
            else pos = mid, right = mid - 1;
        }
        x = ::a[pos].first;
        printf("%d\n", x);
    }
    return 0;
}
