#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct node
{
    int index;
	int d;
};

int a[50002];
int b[50002];
int c[50002];

vector <node> map[50002];
bool inqueue[50002];
int d[50002];

queue <node> q;

int main()
{
    freopen("f:\\in.txt","r",stdin);
    freopen("f:\\out.txt", "w", stdout);
    int i,j,m,mn,mx;
    node ss,tt;
    while(cin>>m)
    {
        memset(inqueue,0,sizeof(inqueue));
        for(i=1; i<=m; i++)
            scanf("%d%d%d",&a[i],&b[i],&c[i]);
        mn=50002;
        mx=0;
        for(i=1; i<=m; i++)
        {
            mn=min(mn,a[i]);
            mx=max(mx,b[i]);
        }
        mx++;
        for(i=mn; i<=mx; i++)
            d[i]=100000;

        for(i=mn; i<=mx; i++)
            map[i].clear();
        for(i=mn; i<mx; i++)
        {
            ss.index=i+1;
            ss.d=1;
            map[i].push_back(ss);
        }

        for(i=mn+1; i<=mx; i++)
        {
            ss.index=i-1;
            ss.d=0;
            map[i].push_back(ss);
        }
        for(i=1; i<=m; i++)
        {
            ss.d=-c[i];
            ss.index=a[i];
            map[b[i]+1].push_back(ss);
        }
        /*vector<node>::iterator it;
        for (i=mn; i<=mx; ++i)
        {
        	printf("%d: ", i);
        	for (it=map[i].begin(); it!=map[i].end(); ++it) printf("-> %d(%d) ", (*it).index, (*it).d);
        	puts("");
		}*/
        
       while(!q.empty())
            q.pop();
        ss.index=mx;
        ss.d=0;
        d[ss.index]=0;
        q.push(ss);
        while(!q.empty())
        {
            ss=q.front();
            q.pop();

            inqueue[ss.index]=false;
            for(i=0; i<map[ss.index].size(); i++)
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
                        q.push(tt);
                    }
                }
            }
        }
        cout<<-d[mn]<<endl;
    }

    return 0;
}