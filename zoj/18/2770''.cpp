#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct node
{
    int index;
	int d;
};
queue <node> q;
vector <node> map[1001];
bool inqueue[1001];
int in[1001];
int d[1001];
int num[1001];

int main()
{
    //freopen("debug\\in.txt","r",stdin);
    int m,n,i,j,x,y,z;
    int MAX=100000000;
    node ss,tt;
    while(cin>>m>>n)
    {
        for(i=1;i<=m;i++)
            scanf("%d",&num[i]);
        for(i=0;i<=m;i++)
            map[i].clear();
        for(i=0;i<m;i++)
        {
            ss.index=i+1;
            ss.d=num[i+1];
            map[i].push_back(ss);
        }
        for(i=1;i<=m;i++)
        {
            ss.index=i-1;
            ss.d=0;
            map[i].push_back(ss);
        }
        for(i=1;i<=n;i++)
        {
            scanf("%d%d%d",&x,&y,&z);
            ss.index=x-1;
            ss.d=-z;
            map[y].push_back(ss);
        }
        for(i=0;i<=m;i++)
        {
            in[i]=0;
            inqueue[i]=false;
            d[i]=MAX;
        }
        
        while(!q.empty())
            q.pop();
        ss.index=m;
        ss.d=0;
        d[ss.index]=0;
        in[m]=1;
        q.push(ss);
        bool circle=false;
        while(!q.empty())
        {
            ss=q.front();
            q.pop();
            inqueue[ss.index]=false;
            if(in[ss.index]>=m+2)
            {
                circle=true;
                break;
            }
            for(i=0;i<map[ss.index].size();i++)
            {
                tt.index=map[ss.index][i].index;
                tt.d=map[ss.index][i].d;
                tt.d+=d[ss.index];
                if(tt.d<d[tt.index])
                {
                    d[tt.index]=tt.d;
                    if(!inqueue[tt.index])
                    {
                        inqueue[tt.index]=true;
                        in[tt.index]++;
                        q.push(tt);
                    }
                }
            }
        }
        if(!circle)
            printf("%d\n",-d[0]);
        else printf("Bad Estimations\n");
    }


    return 0;
}
