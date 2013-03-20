#include<iostream>
#include<vector>
using namespace std;
int f[50001], e[50001];

struct In {
    int next, l;
} edge;
vector<In> son[50001];

struct Node {
    int father, w;
} p[50001];
int node, t;
int minn;

int dfs(int v, int father) {
    if (f[v] == -1) f[v] = t, e[v] = t;
    else e[v] = t;
    int len = son[v].size();
    for (int i = 0; i < len; i++) {
        edge=son[v][i];
        if(edge.next==p[v].father) continue;
        t++;
        p[edge.next].father = v;
        p[edge.next].w = edge.l;
        dfs(edge.next, v);
        t++;
        e[v] = t;
    }
    return 0;
}

int findlastfather(int x, int y) {
    if (f[x] < f[y] && e[x] > e[y]) return x;
    else if (f[x] > f[y] && e[x] < e[y]) return y;
    else return findlastfather(p[x].father, y);
}

int judge(int x, int y) {
    if (x == y) return x;
    if (f[x] < f[y] && e[x] > e[y]) {
        int k = y;
        while (k != x) {
            minn += p[k].w;
            k = p[k].father;
        }
        return x;
    } else if (f[x] > f[y] && e[x] < e[y]) {
        int k = x;
        while (k != y) {
            minn += p[k].w;
            k = p[k].father;
        }
        return y;
    } else {
        minn += p[x].w;
        return judge(p[x].father, y);
    }
}

int main() {
    int g = 0;
    while (scanf("%d", &node) != EOF) {
        for (int i = 0; i < node; i++) son[i].clear();
        for (int i = 0; i < node - 1; i++) {
            int a, b;
            scanf("%d%d%d", &a, &b, &edge.l);
            edge.next = b;
            son[a].push_back(edge);
            edge.next = a;
            son[b].push_back(edge);
            f[i] = -1;
        }
        p[0].father = 0;
        p[0].w = 0;
        f[node - 1] = -1;
        t = 0;
        dfs(0, 0);
        if (g) printf("\n");
        g++;
        int cas;
        scanf("%d", &cas);
        while (cas--) {
            int x, y, z, pp;
            minn = 0;
            scanf("%d%d%d", &x, &y, &z);
            int xy, xz, yz;
            xy = findlastfather(x, y);
            xz = findlastfather(x, z);
            yz = findlastfather(y, z);
            if (xy == xz) {
                pp = judge(y, z);
                judge(pp, x);
            } else if (xy == yz) {
                pp = judge(x, z);
                judge(pp, y);
            } else if (xz == yz) {
                pp = judge(x, y);
                judge(pp, z);
            }
            printf("%d\n", minn);
        }
    }
    return 0;
}
