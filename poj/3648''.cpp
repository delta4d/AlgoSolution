#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

const int N=65;

vector<int>map[N];                                                                                                                          //原图
vector<int>map1[N];                                                                                                                         //原图map[]的逆向图
vector<int>dag[N];                                                                                                                          //缩点后的图的连接关系

bool used[N],flag[N][N];

int order[N],id[N],dfn[N],degree[N];
int m,n,cnt,color;

void Init()                                                                                                                                 //初始化
{
     for(int i=0;i<2*n;i++)
     {
          map[i].clear();
          map1[i].clear();
     }
}

void addedge(int from,int to)                                                                                                              //在原图和逆向图中加边
{
     map[from].push_back(to);
     map1[to].push_back(from);
}

void build_map()                                                                                                                          //根据题意建图
{
     int i,u,v,uu,vv;
     char ch1,ch2;
     for(i=0;i<m;i++)
     {
         scanf("%d%c %d%c",&u,&ch1,&v,&ch2);
         if(ch1=='w')
         {
              u=2*u;
              uu=u+1;
         }
         else
         {
              u=2*u+1;
              uu=u-1;
         }
         if(ch2=='w')
         {
               v=2*v;
               vv=v+1;
         }
         else
         {
               v=2*v+1;
               vv=v-1;
         }
         addedge(u,vv);
         addedge(v,uu);
     }
     addedge(0,1);                                                                                                                     //注意这条边
}

void dfs1(int u)                                                                                                                       //Kosaraju算法求解强连通分量
{
     used[u]=true;
     for(int i=0;i<map[u].size();i++)
       if(!used[map[u][i]])
          dfs1(map[u][i]);
     order[cnt++]=u;
}

void dfs2(int u)                                                                                                                      
{
     used[u]=true;
     id[u]=color;
     for(int i=0;i<map1[u].size();i++)
      if(!used[map1[u][i]])
        dfs2(map1[u][i]);
}

bool sat()                                                                                                                            //判断该问题是否存在可行解
{
     int i;
     memset(used,0,sizeof(used));
     color=cnt=0;
     for(i=0;i<2*n;i++)
      if(!used[i])
        dfs1(i);
     memset(used,0,sizeof(used));
     for(i=cnt-1;i>=0;i--)
      if(!used[order[i]])
      {
         color++;
         dfs2(order[i]);
      }
     for(i=0;i<2*n;i+=2)
      if(id[i]==id[i+1])
        return 0;
     return 1;
}

void build_dag()                                                                                                                     //缩点逆图
{
     int i,v;
     memset(flag,0,sizeof(flag));
     memset(degree,0,sizeof(degree));
     for(i=1;i<=color;i++)
         dag[i].clear();
     for(i=0;i<2*n;i++)
      for(vector<int>::iterator j=map[i].begin();j!=map[i].end();j++)
       if(!flag[id[*j]][id[i]]&&id[i]!=id[*j])
       {
              degree[id[i]]++;
              flag[id[*j]][id[i]]=true;
              dag[id[*j]].push_back(id[i]);
       }
}

void topsort()                                                                                                                      //对缩点逆图拓扑排序
{
     int i,u;
     cnt=0;
     stack<int>q;
     for(i=1;i<=color;i++)
      if(degree[i]==0)
        q.push(i);
     while(!q.empty())
     { 
        u=q.top();
        order[cnt++]=u;
        q.pop();
        for(vector<int>::iterator v=dag[u].begin();v!=dag[u].end();v++)
        {
            degree[*v]--;
            if(degree[*v]==0)
               q.push(*v);
        }
     }
}

void dfs_color(int u)                                                                                                             //找出子孙节点并染色
{ 
     dfn[u]=2;
     for(vector<int>::iterator v=dag[u].begin();v!=dag[u].end();v++)
         if(dfn[*v]==0)
            dfs_color(*v);
}

void set_color()                                                                                                                 //求解可行解
{
     int i,j,tmp;
     memset(dfn,0,sizeof(dfn));
     for(i=0;i<cnt;i++)
      if(!dfn[order[i]])
      {
          dfn[order[i]]=1;
          for(j=0;j<2*n;j++)
          {
              if(id[j]==order[i])
              {
                   if(j&1)
                      tmp=j-1;
                   else
                      tmp=j+1;
                   tmp=id[tmp];
                   if(dfn[tmp])
                      continue;
                   dfs_color(tmp);
              }
          }
      }
}
                     

void solve()
{
     int i,tmp,flag=1;
     tmp=dfn[id[0]]; 
     for(i=2;i<2*n;i++)
      if(dfn[id[i]]==tmp)                                                                                                   //以新娘为标准
      {
          if(!flag)
             printf(" ");
          if(i%2==1)
             printf("%dh",i/2);
          else
             printf("%dw",i/2);
          flag=0;
      }
     printf("\n");
}

int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(n==0&&m==0)
           break;
        Init();
        build_map();
        if(!sat())
           printf("bad luck\n");
        else
        {
            
            build_dag();
            topsort();
            set_color();
            solve();
        }
    }
    system("pause");
    return 0;
}