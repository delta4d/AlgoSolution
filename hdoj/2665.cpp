#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int const N = 1e5 + 10;

struct node {
    int sum, left, right;
} f[N*18];
int next_node;
int root[N], a[N], b[N];

int insert(int r, int L, int R, int k) {
    if (R < k || L > k || L > R) return r;
    int cur = next_node++;
    f[cur] = f[r];
    if (L == R) {
        ++f[cur].sum;
    } else {
        int M = L + (R - L) / 2;
        f[cur].left = insert(f[r].left, L, M, k);
        f[cur].right = insert(f[r].right, M+1, R, k);
        f[cur].sum = f[f[cur].left].sum + f[f[cur].right].sum;
    }
    return cur;
}

int query(int l, int r, int L, int R, int k) {
    if (L == R) return b[L];
    int sum = f[f[r].left].sum - f[f[l].left].sum;
    int M = L + (R - L) / 2;
    if (sum < k) return query(f[l].right, f[r].right, M+1, R, k-sum);
    return query(f[l].left, f[r].left, L, M, k);
}

int main() {
    int tc, n, q;
    for (scanf("%d", &tc); tc--; ) {
        memset(f, 0, sizeof(f));
        next_node = 1;
        scanf("%d%d", &n, &q);
        for (int i=0; i<n; ++i) {
            scanf("%d", a+i);
            b[i] = a[i];
        }
        sort(b, b+n);
        int m = unique(b, b+n) - b;
        for (int i=0; i<n; ++i) {
            int id = lower_bound(b, b+m, a[i]) - b;
            root[i+1] = insert(root[i], 0, m-1, id);
        }
        for (int l,r,k; q--; ) {
            scanf("%d%d%d", &l, &r, &k);
            printf("%d\n", query(root[l-1], root[r], 0, m-1, k));
        }
    }
    return 0;
}

// 12700470	2015-01-14 22:57:50	Accepted	2665	795MS	23368K	1374 B	G++	delta
