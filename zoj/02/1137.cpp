#include<cstdio>
#include<memory>
#include<vector>

using namespace std;

const int MaxN = 500;

int n;
int match[MaxN];
bool visit[MaxN];
vector<int>Link[MaxN];

bool find(int k)
{
	vector<int> :: iterator it;
	
    for (it=Link[k].begin(); it!=Link[k].end(); ++it)
    {
        if (!visit[*it])
        {
            visit[*it] = true;
            if (match[*it] == -1 || find(match[*it]))
            {
                match[*it] = k;
                return true;
            }
        }
    }

    return false;
}

int main(void)
{
    int i;
    int j;
    int t;
    int src;
    int dst;
    int ans;

    while (scanf("%d", &n) != EOF)
    {
        for (i=0; i<n; ++i)
        {
            Link[i].clear();
        }

        for (i=0; i<n; ++i)
        {
            scanf("%d", &src);

            getchar();
            getchar();
            getchar();
            scanf("%d", &t);
            getchar();

            for (j=0; j<t; ++j)
            {
                scanf("%d", &dst);
                Link[i].push_back(dst);
            }
        }

        ans = 0;
        memset(match, -1, sizeof(match));

        for (i=0; i<n; ++i)
        {
            memset(visit, false, sizeof(visit));

            if (find(i))
            {
                ++ans;
            }
        }

        printf("%d\n", n - ans / 2);
    }

    return 0;
}
