#include<iostream>
#include<cstdlib>
using namespace std;

const int _DataSize = 102;

int    weig[ _DataSize ];
bool   canc[ _DataSize ][ _DataSize ];
double rate[ _DataSize ][ _DataSize ];

void Initial( int n, int m )
{
    int    A,B;
    double C;
    for ( int i = 1 ; i <= n ; ++ i )
        for ( int j = 1 ; j <= n ; ++ j )
            rate[ i ][ j ] = 1.0;//初始化成0了。。。WA了n次。。。
    for ( int i = 1 ; i < n ; ++ i )
        cin >> weig[ i ];
    for ( int i = 0 ; i < m ; ++ i )
    {
        cin >> A >> B >> C;
        if ( rate[ A ][ B ] - C > 1e-7 )
        {
            rate[ A ][ B ] = C;
            rate[ B ][ A ] = C;
        }
    }
}

double V[ _DataSize ];
bool   S[ _DataSize ];

void   Dijstra( int n )
{
    for ( int i = 1 ; i <= n ; ++ i )
    {
        V[ i ] = 0.0;
        S[ i ] = false;
    }
    S[ n ] = true;
    V[ n ] = 1.0;
    int now = n;
    for ( int i = 1 ; i < n ; ++ i )
    {
        for ( int j = 1 ; j < n ; ++ j )
            if ( !S[ j ] && V[ now ]*(1.0-rate[ now ][ j ]) - V[ j ] > 1e-7 )
                V[ j ] = V[ now ]*(1.0-rate[ now ][ j ]);
        double min = 0.0;
        for ( int j = 1 ; j < n ; ++ j )
            if ( !S[ j ] && V[ j ] - min > 1e-7 )
            {
                min = V[ j ];
                now = j;
            }
        S[ now ] = true;
    }
    double sum = 0.0;
    for ( int i = 1 ; i < n ; ++ i )
        sum += weig[ i ]*V[ i ];
    printf("%.2lf\n",sum);
}

int main()
{
    int n,m;
    freopen("f:\\in.txt", "r", stdin);
    while ( cin >> n >> m )
    {
        Initial( n, m );
        Dijstra( n );
    }
    return 0;
}