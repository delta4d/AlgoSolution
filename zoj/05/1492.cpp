#include<iostream>

using namespace std;

const int MaxN = 50;

int g[MaxN][MaxN];
int num[MaxN];
int n;
int best;

bool dfs(int *adj, int total, int cnt)
{
    int i;
    int j;
    int k;
    int t[MaxN];

    if (total == 0)
    {
        if (best < cnt)
        {
            best = cnt;
            return true;
        }

        return false;
    }

    for (i=0; i<total; ++i)
    {
        if (cnt + total - i <= best)
        {
            return false;
        }

        if (cnt + num[adj[i]] <= best)
        {
            return false;
        }

        k = 0;

        for (j=i+1; j<total; ++j)
        {
            if (g[adj[i]][adj[j]] == 1)
            {
                t[k] = adj[j];
                ++k;
            }
        }    
		
		if (dfs(t, k, cnt+1))
  		{
    		return true;
    	}   
    }

	return false;
}

int MaximumClique()
{
    int i;
    int j;
    int k;
    int adj[MaxN];

    for (i=n-1; i>=0; --i)
    {
        k = 0;

        for (j=i+1; j<n; ++j)
        {
            if (g[i][j] == 1)
            {
                adj[k] = j;
                ++k;
            }
        }

        dfs(adj, k, 1);
        num[i] = best;
    }

    return best;
}

int main(void)
{
    int i;
    int j;
    int res;

    cin >> n;

    while (n != 0)
    {
        for (i=0; i<n; ++i)
        {
            for (j=0; j<n; ++j)
            {
                cin >> g[i][j];
            }
        }

		best = 0;

        res = MaximumClique();

        cout << res << endl;

        cin >> n;
    }

    return 0;
}
