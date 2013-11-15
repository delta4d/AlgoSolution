#include<iostream>
#include<queue>
using namespace std;
bool useif[105];	//是否正在使用
int father[105];	//看英文吧
int edge[105][105]; //边，值是权
int n,m;
int ford()
{
    int max=0;
    while (1)		//一直找，直到找不到
    {
        int now,i,min=0xffff;
        memset(useif,0,sizeof(useif));
        queue<int> q;
        q.push(0);
        while (!q.empty())//BFS找一个增广路
        {
            now=q.front();
            q.pop();
            if (now==n)break;
            for (i=0;i<=n;i++)
            {
                if (!useif[i]&&edge[now][i])
                {
                    useif[i]=true;
                    q.push(i);//加入队列
                    father[i]=now;
                }
            }
        }
        if (!useif[n])break;
        for (i=n;i;i=father[i])
        {
            if (edge[father[i]][i]<min)
                min=edge[father[i]][i];
        }
        for (i=n;i;i=father[i])
        {
            edge[father[i]][i]-=min;//更新正向流量
            edge[i][father[i]]+=min;//反向，流量抵消
        }
        max+=min;
    }
    return max;
}
int main()
{
    int i,j,np,nc,a,b,c;
    char ss[50];
    while (scanf("%d%d%d%d",&n,&np,&nc,&m)!=EOF)
    {
        getchar();
        memset(edge,0,sizeof(edge));
        memset(father,-1,sizeof(father));
        for (i=1;i<=m;i++)
        {
            scanf("%s",ss);
            sscanf(ss,"(%d,%d)%d",&a,&b,&c);//第一次用这个函数，挺好用的
            edge[a+1][b+1]+=c;
        }
        for (i=1;i<=np;i++)
        {
            scanf("%s",ss);
            sscanf(ss,"(%d)%d",&a,&b);
            edge[0][a+1]+=b;//0即源点
        }
        n++;//汇点
        for (i=1;i<=nc;i++)
        {
            scanf("%s",ss);
            sscanf(ss,"(%d)%d",&a,&b);
            edge[a+1][n]+=b;
        }
        printf("%d\n",ford());
    }
}
