/**************************************************************
    Problem: 1036
    User: delta
    Language: C++
    Result: Accepted
    Time:2940 ms
    Memory:5000 kb
****************************************************************/
 
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
 
int const N = 3e4 + 10;
int const INF = 0x3f3f3f3f;
 
struct SegmentTree {
    int sum[N<<2], mx[N<<2];
    void modify(int r, int L, int R, int p, int x) {
        if (R < p || L > p) return;
        if (L == R) {
            sum[r] = mx[r] = x;
        } else {
            int M = L + (R - L) / 2, ls = r << 1, rs = ls | 1;
            modify(ls, L, M, p, x);
            modify(rs, M+1, R, p, x);
            sum[r] = sum[ls] + sum[rs];
            mx[r] = max(mx[ls], mx[rs]);
        }
    }
    int query_sum(int r, int L, int R, int a, int b) {
        if (R < a || L > b) return 0;
        if (a <= L && R <= b) return sum[r];
        int M = L + (R - L) / 2, ls = r << 1, rs = ls | 1;
        return query_sum(ls, L, M, a, b) + query_sum(rs, M+1, R, a, b);
    }
    int query_max(int r, int L, int R, int a, int b) {
        if (R < a || L > b) return -INF;
        if (a <= L && R <= b) return mx[r];
        int M = L + (R - L) / 2, ls = r << 1, rs = ls | 1;
        return max(query_max(ls, L, M, a, b), query_max(rs, M+1, R, a, b));
    }
} T;
 
vector <int> e[N];
int fa[N], dep[N], hson[N], sz[N], tp[N], id[N];
int num, n, q;
char op[20];
 
void dfs(int x, int p, int d) {
    fa[x] = p, dep[x] = d, hson[x] = -1, sz[x] = 1;
    for (int i=0; i<(int)e[x].size(); ++i) {
        int y = e[x][i];
        if (y == p) continue;
        dfs(y, x, d+1);
        sz[x] += sz[y];
        if (hson[x] == -1 || sz[hson[x]] < sz[y]) hson[x] = y;
    }
}
 
void dfs(int x, int p) {
    id[x] = num++;
    tp[x] = p;
    if (hson[x] != -1) dfs(hson[x], p);
    for (int i=0; i<(int)e[x].size(); ++i) {
        int y = e[x][i];
        if (y == fa[x] || y == hson[x]) continue;
        dfs(y, y);
    }
}
 
int query_max(int a, int b) {
    int ta = tp[a], tb = tp[b], ret = -INF;
    while (ta != tb) {
        if (dep[ta] < dep[tb]) swap(ta, tb), swap(a, b);
        ret = max(ret, T.query_max(1, 0, n-1, id[ta], id[a]));
        a = fa[ta], ta = tp[a];
    }
    if (dep[a] > dep[b]) swap(a, b);
    ret = max(ret, T.query_max(1, 0, n-1, id[a], id[b]));
    return ret;
}
 
int query_sum(int a, int b) {
    int ta = tp[a], tb = tp[b], ret = 0;
    while (ta != tb) {
        if (dep[ta] < dep[tb]) swap(ta, tb), swap(a, b);
        ret += T.query_sum(1, 0, n-1, id[ta], id[a]);
        a = fa[ta], ta = tp[a];
    }
    if (dep[a] > dep[b]) swap(a, b);
    ret += T.query_sum(1, 0, n-1, id[a], id[b]);
    return ret;
}
 
int main() {
    scanf("%d", &n);
    for (int i=1,a,b; i<n; ++i) {
        scanf("%d%d", &a, &b), --a, --b;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    dfs(0, -1, 0);
    dfs(0, 0);
    for (int i=0,w; i<n; ++i) {
        scanf("%d", &w);
        T.modify(1, 0, n-1, id[i], w);
    }
    scanf("%d", &q);
    for (int a,b; q--; ) {
        scanf("%s%d%d", op, &a, &b);
        if (op[0] == 'C') {
            T.modify(1, 0, n-1, id[a-1], b);
        } else {
            if (op[1] == 'M') printf("%d\n", query_max(a-1, b-1));
            else printf("%d\n", query_sum(a-1, b-1));
        }
    }
    return 0;
}
