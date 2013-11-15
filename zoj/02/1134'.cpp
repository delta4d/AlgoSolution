#include<cstdio>
#include<vector>
using namespace std;

int dp[2000][3];
int n;
bool vis[2000];
vector<int> vec[2000];

int minn(int a,int b)
{
    if (a<b) return a;
    return b;
}

void dfs(int root)
{
    int i,s,t,len = vec[root].size();
    bool leaf = true;
    s = t = 0;
    for (i=0;i<len;i++)
    {
        leaf = false;
        int k = vec[root][i];
        dfs(k);
        s+=dp[k][1];
        t+=minn(dp[k][0],dp[k][1]);
    }
    if (leaf)
    {
        dp[root][0] = 0;
        dp[root][1] = 1;
    }
    else
    {
        dp[root][0] = s;
        dp[root][1] = t+1;
    }
}

int main()
{
    int i,j,a,b,x;
    while (scanf("%d",&n)!=EOF)
    {
        for (i=0;i<n;i++)
        {
            vis[i] = 0 ;
            vec[i].clear();
        }
        for (i=0;i<n;i++)
        {
            scanf("%d:(%d)",&a,&b);
            for (j=0;j<b;j++)
            {
                scanf("%d",&x);
                vec[a].push_back(x);
                vis[x] = 1;
            }
        }
        int root;
        for (i=0;i<n;i++)
        {
            if (!vis[i])
            {
                root = i ;
                break;
            }
        }

        dfs(root);
        printf("%d\n",minn(dp[root][0],dp[root][1]));
    }
    return 0;
}
