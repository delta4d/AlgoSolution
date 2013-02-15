#include<iostream>
#include<vector>
using namespace std;
vector<int> son[101], temp;
int dp[101][101];

struct Node
{
    int father, first, second;
} node[101];

int N, K, w[101], NN;

int creat(int v)
{
    int len = son[v].size();
    bool flag = false;
    for (int i = 0; i < len; i++)
    {
        if (son[v][i] != node[v].father)
        {
            if (!flag)
            {
                node[son[v][i]].father = v;
                node[v].first = son[v][i];
                node[son[v][i]].first = -1;
                node[son[v][i]].second = -1;
                creat(son[v][i]);
                flag = true;
            }
            else
            {
                node[son[v][i]].father = v;
                node[son[v][i - 1]].second = son[v][i];
                node[son[v][i]].first = -1;
                node[son[v][i]].second = -1;
                creat(son[v][i]);
            }
        }
    }
    return 0;
}

int findbest(int v, int k)
{
    int ret = 0;
    if (v == -1) return 0;
    if (dp[v][k] != -1) return dp[v][k];
    if (k == 0)
    {
        dp[v][k] = 0;
    }
    else if (k == 1)
    {
        dp[v][k] = max(w[v], findbest(node[v].second, 1));
    }
    else
    {
        for (int p = 0; p <= k; p++)
        {
            int m = 0;
            m += findbest(node[v].second, p);
            if (k - p >= 1)
            {
                m += w[v];
                m += findbest(node[v].first, k - p - 1);
            }
            ret = max(ret, m);
        }
        dp[v][k] = ret;
    }
    return dp[v][k];
}

int main()
{
    while (scanf("%d%d", &N, &K) != EOF)
    {
        for (int i = 0; i < N; i++) for (int j = 0; j <= K; j++) dp[i][j] = -1;
        for (int i = 0; i < N; i++)
        {
            scanf("%d", &w[i]);
            son[i].clear();
        }
        for (int i = 0; i < N - 1; i++)
        {
            int a, b;
            scanf("%d%d", &a, &b);
            son[a].push_back(b);
            son[b].push_back(a);
        }
        node[0].father = 0;
        node[0].first = -1;
        node[0].second = -1;
        creat(0);
        int res = 0;
        /*
                for (int i = 0; i < N; i++) {
                    cout << i << " firstson= " << node[i].first << " nextbrother= " << node[i].second << endl;
                }
         */
        for (int i = 0; i < N; i++)
        {
            int ans = w[i] + findbest(node[i].first, K - 1);
            //cout << ans << endl;
            res = max(res, ans);
        }

        cout << res << endl;
    }

    return 0;
}
