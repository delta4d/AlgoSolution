#include<iostream>
#include<cmath>
#include<list>
using namespace std;
int n, q;
struct node
{
    int lab, dis;
    void init(int l, int d)
    {
        lab = l; dis = d;
    }
};
int v1, v2, v3, len;
list<node> g[50001];
int ei, e[100002], r[50001], l[100002], d[50001];
bool visit[50001];
int pow2[18];
int mmin[18][100002];

void dfs(int u, int dep)
{
    e[++ei] = u; l[ei] = dep;
    if(visit[u]) return;
    visit[u] = true;
    list<node>::iterator it = g[u].begin();
    while(it != g[u].end())
    {
        int v = it->lab, len = it->dis;
        if(!visit[v])
        {
            d[v] = min(d[v], d[u] + len);
            dfs(v, dep+1);
            e[++ei] = u; l[ei] = dep;
            
        }
        it++;
    }
}

void init_rmq()
{
    ei = 0;
    memset(visit, 0, sizeof(visit));
    d[0] = 0;
    dfs(0, 1);
    memset(r, -1, sizeof(r));
    for(int i=1; i<=ei; i++)
        if(r[e[i]] == -1)
            r[e[i]] = i;
    memset(mmin, 0, sizeof(mmin));
    for(int i=1; i<=ei; i++)
        mmin[0][i] = i;
    int t1 = (int)(log((double)ei) / log(2.0));
    for(int i=1; i<=t1; i++)
        for(int j=1; j + pow2[i] - 1<=ei; j++)
        {
            int a = mmin[i-1][j], b = mmin[i-1][j+pow2[i-1]];
            if(l[a] <= l[b])
                mmin[i][j] = a;
            else
                mmin[i][j] = b;
        }
}

int rmq(int u, int v)
{
    int i = r[u], j = r[v];
    if(i > j) swap(i, j);
    int t1 = (int)(log((double)j - i + 1) / log(2.0));
    int a = mmin[t1][i], b = mmin[t1][j - pow2[t1] + 1];
    if(l[a] <= l[b])
        return e[a];
    else
        return e[b];
}

int main()
{
    for(int i=0; i<18; i++)
        pow2[i] = 1 << i;
    bool flag = false;
    while(scanf("%d", &n) != EOF)
    {
        if(flag) printf("\n");
        flag = true;
        for(int i=0; i<n; i++)
        {
            g[i].clear();
            d[i] = INT_MAX;
        }
        for(int i=0; i<n-1; i++)
        {
            scanf("%d%d%d", &v1, &v2, &len);
            node n1; n1.init(v2, len);
            g[v1].push_back(n1);
            node n2; n2.init(v1, len);
            g[v2].push_back(n2);
        }
        init_rmq();
        scanf("%d", &q);
        while(q--)
        {
            int res = INT_MAX;
            scanf("%d%d%d", &v1, &v2, &v3);
            int temp = 0;
            int lca1 = rmq(v1, v2);
            temp = d[v1] + d[v2] - 2*d[lca1];
            int lca2 = rmq(lca1, v3);
            temp += d[lca1] + d[v3] - 2*d[lca2];
            res = min(res, temp);
            temp = 0;
            lca1 = rmq(v1, v3);
            temp = d[v1] + d[v3] - 2*d[lca1];
            lca2 = rmq(lca1, v2);
            temp += d[v2] + d[lca1] - 2*d[lca2];
            res = min(res, temp);
            temp = 0;
            lca1 = rmq(v2, v3);
            temp = d[v2] + d[v3] - 2*d[lca1];
            lca2 = rmq(lca1, v1);
            temp += d[v1] + d[lca1] - 2*d[lca2];
            res = min(res, temp);
            printf("%d\n", res);
        }
    }
}