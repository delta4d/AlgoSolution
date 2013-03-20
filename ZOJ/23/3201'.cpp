#include <cstdio>
using namespace std;

const int SIZE = 101;

struct TREE
{
    int m_arr[SIZE];
    int m_size;
    int m_value;
}tree[SIZE];

int N, K;
int dp[SIZE][SIZE];

inline int MAX(const int& a, const int& b)
{
    return (a > b ? a : b);
}

void Init()
{
    int i;
    for ( i = 0; i < SIZE; ++i )
        tree[i].m_size = 0;
}

void DFS( const int& root, const int& fat )
{
    int i, j, k;

    dp[root][0] = 0;
    dp[root][1] = tree[root].m_value;

    for ( i = 2; i <= K; ++i )
        dp[root][i] = -1;

    for ( i = 0; i < tree[root].m_size; ++i )
    {
        int x = tree[root].m_arr[i];

        if ( x == fat )
            continue;

        DFS( x, root );

        for ( j = K; j >= 2; --j )
        {
            int t = -1;

            for ( k = 1; k <= j; ++k )
            {
                if ( dp[root][k] == -1 || dp[x][j - k] == -1 )
                    continue;
                t = MAX( t, dp[root][k] + dp[x][j - k] );
            }

            dp[root][j] = t;
        }
    }
}

void Solve()
{
    int ans = 0;

    DFS( 0, -1 );

    for ( int i = 0; i < N; ++i )
        if ( ans < dp[i][K] )
            ans = dp[i][K];

    printf("%d\n", ans);
}

int main()
{
    int i;
	int x;
	int y;

    while ( scanf("%d %d", &N, &K) != EOF )
    {
        Init();

        for ( i = 0; i < N; ++i )
            scanf("%d", &tree[i].m_value);

        for ( i = 0; i < N - 1; ++i )
        {
            scanf("%d %d", &x, &y);
            tree[x].m_arr[tree[x].m_size++] = y;
            tree[y].m_arr[tree[y].m_size++] = x;
        }
        
        Solve();
    }
    
    return 0;
}
