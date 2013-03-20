#include <cstdio>
#include <cstring>
using namespace std;
int const Maxn=1000+3;
int s[Maxn],t[Maxn];
struct data
{
    int x,y,d;
}edge[Maxn];
int n,m;
int init()
{
    int i;
    for (i=1;i<=n;i++) scanf("%d",&t[i]);
    char s[5];
    m=0;
    while (scanf("%s",s)!=EOF)
    {
        if (strcmp(s,"#")==0) break;
        m++;
        scanf("%d%d",&edge[m].x,&edge[m].y);
        if (strcmp(s,"SAF")==0) edge[m].d=t[edge[m].y];
        if (strcmp(s,"FAF")==0) edge[m].d=t[edge[m].y]-t[edge[m].x];
        if (strcmp(s,"SAS")==0) edge[m].d=0;
        if (strcmp(s,"FAS")==0) edge[m].d=-t[edge[m].x];
    }
    
    for (i=1; i<=m; ++i)
    printf("%d->%d(%d)\n", edge[i].x, edge[i].y, edge[i].d);
    
    return 0;
}
int solve(int num)
{
    int i,j,k,get;
    for (i=0;i<=n;i++) s[i]=0;
    for (k=1;k<=n;k++)
    {
        get=0;
        for (i=1;i<=m;i++)
            if (s[edge[i].x]<s[edge[i].y]+edge[i].d)
            {
                s[edge[i].x]=s[edge[i].y]+edge[i].d;
                get=1;
            }
        if (!get) break;
    }
    printf("Case %d:\n",num);
    if (get) printf("impossible\n");
    else
    {
        for (i=1;i<=n;i++)
            printf("%d %d\n",i,s[i]);
    }
    printf("\n");
    return 0;
}

int main()
{
    int num=0;
    freopen("f:\\in.txt", "r", stdin);
    freopen("f:\\out.txt", "w", stdout);
    while (scanf("%d",&n) && n)
    {
        init();
        solve(++num);
    }
    return 0;
}
/*
一道比较简单的差分约束系统，约束条件还是比较容易找到的
if SAF s[a]>=s[b]+t[b];
if FAF s[a]+t[a]>=s[b]+t[b];
if SAS s[a]>=s[b];
if FAS s[a]+t[a]>=s[b];
*/
