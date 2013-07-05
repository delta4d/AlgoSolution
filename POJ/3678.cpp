
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
int n,m;
const int N=10000;
const int M=5000000;
typedef struct EDGE
{
    int v,next;
};
EDGE edge[M];
int cnt,head[N];
int scc,index,dfn[N],low[N],belong[N],num[N];
int out[N],in[N],top,sstack[N];
bool instack[N];
void addedge(int u,int v)
{
    edge[cnt].v=v;
    edge[cnt].next=head[u];
    head[u]=cnt++;
}
int MIN(int a,int b)
{
    if(a>b)
        return b;
    return a;
}
void tarjan(int u)
{
    dfn[u]=low[u]=++index;
    sstack[++top]=u;
    instack[u]=true;
    for(int j=head[u];j!=-1;j=edge[j].next)
    {
        int v=edge[j].v;
        if(dfn[v]==0)
        {
            tarjan(v);
            low[u]=MIN(low[v],low[u]);
        }
        else if(instack[v])
        {
            low[u]=MIN(low[u],dfn[v]);
        }
    }
    if(dfn[u]==low[u])
    {
        scc++;
        while(1)
        {
            int tmp=sstack[top--];
            instack[tmp]=false;
            belong[tmp]=scc;
            num[scc]++;
            if(tmp==u) break;
        }
    }
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        cnt=0;
        scc=index=top=0;
        memset(dfn,0,sizeof(dfn));
        memset(head,-1,sizeof(head));
        memset(num,0,sizeof(num));
        memset(instack,0,sizeof(instack));
        for(int i=1;i<=m;i++)
        {
            int a,b,c;char str[10];
            scanf("%d%d%d%s",&a,&b,&c,str);
            if(str[0]=='A')
            {
                if(c==1)
                {
                    addedge(a+n,b+n);
                    addedge(b+n,a+n);
                    addedge(a,a+n);
                    addedge(b,b+n);
                }
                else if(c==0)
                {
                    addedge(b+n,a);
                    addedge(a+n,b);
                }
            }
            else if(str[0]=='O')
            {
                if(c==0)
                {
                    addedge(a,b);
                    addedge(b,a);
                    addedge(a+n,a);
                    addedge(b+n,b);
                }
                else if(c==1)
                {
                    addedge(a,b+n);
                    addedge(b,a+n);
                }
            }
            else if(str[0]=='X')
            {
                if(c==1)
                {
                    addedge(a,b+n);
                    addedge(b,a+n);
                    addedge(b+n,a);
                    addedge(a+n,b);
                }
                else if(c==0)
                {
                    addedge(a+n,b+n);
                    addedge(b+n,a+n);
                    addedge(a,b);
                    addedge(b,a);
                }
            }
        }
        for(int i=0;i<n*2;i++)
        {
            if(!dfn[i]) tarjan(i);
        }
        bool flag=false;
        for(int i=0;i<n;i++)
        {
            if(belong[i]==belong[i+n])
            {
                printf("NO\n");
                flag=true;
                break;
            }
        }
        if(!flag)
            printf("YES\n");
    }
}