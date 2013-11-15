#include<cstdio>
#include<memory>

using namespace std;

int n;
const int MaxN = 21;
int f[MaxN];
bool prime[MaxN*2];
bool visit[MaxN];

void gen()
{
    int i;
    int j;
    memset(prime, true, sizeof(prime));

    prime[0] = prime[1] = false;

    for (i=2; i*i<2*MaxN; ++i)
    {
        if (prime[i])
        {
            for (j=i+i; j<2*MaxN; j+=i)
            {
                if (prime[j])
                {
                    prime[j] = false;
                }
            }
        }
    }

    return;
}

void dfs(int depth)
{
    int i;

    if (depth == n)
    {
        if (prime[f[n]+f[1]])
        {
            for (i=1; i<n; ++i)
            {
                printf("%d ", f[i]);
            }

            printf("%d\n", f[n]);
        }

        return;
    }

    for (i=1; i<=n; ++i)
    {
        if (!visit[i] && prime[i+f[depth]])
        {
            visit[i] = true;
            f[depth + 1] = i;
            dfs(depth + 1);
            visit[i] = false;
        }
    }

    return;
}

int main(void)
{
    int case_num = 1;
    gen();

    while (scanf("%d", &n) != EOF)
    {
        printf("Case %d:\n", case_num);
        ++case_num;

        if (n % 2 == 0)
        {
            memset(visit, false, sizeof(visit));
            f[1] = 1;
            visit[1] = true;

            dfs(1);
        }
        
        printf("\n");
    }

    return 0;
}
