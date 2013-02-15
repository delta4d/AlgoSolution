#include <cstdio>
#include <cstring>
using namespace std;

char str[1000];
int card[7];

bool dfs ( int sum )
{
    int i;
    for ( i = 1; i <= 6; i ++ )
    {
        if ( card[i] && sum - i >= 0 )
        {
            card[i] --;
            if ( dfs ( sum - i ) )
            {
                card[i] ++;
                return false;
            }
            card[i] ++;
        }
    }
    return true;
}

void proc ()
{
    int i, sum = 31;
    for ( i = 0; i < 7; i ++ )
        card[i] = 4;
    int turn;
    int len = strlen ( str );
    for ( i = 0, turn = 0; i < len; i ++, turn = 1 - turn )
    {
        sum -= str[i] - '0';
        card[str[i] - '0'] --;
    }
    if ( sum > 0 )
        if ( dfs ( sum ) )
            turn = 1 - turn;
    if ( sum == 0 )
        turn = 1 - turn;
    printf ( "%s %c ", str, 'A' + turn );
}

int main ()
{
    //freopen ( "in.txt", "r", stdin );
    while ( scanf ( "%s", str ) != EOF )
    {
        proc ();
    }
    return 0;
}