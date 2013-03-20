#include <cstdio>
#include <queue>
#include <vector>
#define MAX 100005
using namespace std;
typedef struct node
{
    int heap;
    int dis;
    node()
    {}
    node(int h,int d)
    {
        heap=h;
        dis=d;
    }
    friend bool operator <(node a,node b)  //用的是大堆
    {
        return a.dis<b.dis;
    }
}Point;
priority_queue<Point>Q;
Point temp;
vector<Point>G[MAX];
int n,m,start,end,dis[MAX],zz=1;
void Init()
{
    int i,a,b,s;
    for(i=1;i<=n;i++)  //初始化
        G[i].clear();
    while(m--)
    {
        scanf("%d%d%d",&a,&b,&s);
        G[a].push_back(node(b,s));
        G[b].push_back(node(a,s));
    }
    scanf("%d%d",&start,&end);
}
int GetMin(int a,int b)
{
    if(a==-1)
        return b;
    else
    {
        if(a>b)
            return b;
        else
            return a;
    }
}
void Dijkstra()
{
    int i,tp,td,k;
    for(i=1;i<=n;i++)
    {
        dis[i]=-1;
    }
    while(!Q.empty())
        Q.pop();
    Q.push(node(start,-1));
    while(!Q.empty())
    {
        temp=Q.top();
        k=temp.heap;
        Q.pop();
        if(k==end)
        {
            printf("%d\n",temp.dis);
            return ;
        }
        for(i=0;i<G[temp.heap].size();i++)
        {
            tp=G[temp.heap][i].heap;
            td=G[temp.heap][i].dis;
            if(GetMin(dis[k],td)>dis[tp])
            {
                dis[tp]=GetMin(dis[k],td);
                Q.push(node(tp,dis[tp]));
            }
        }
    }
    printf("0\n");
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        Init();
        Dijkstra();
    }
    return 0;
}
