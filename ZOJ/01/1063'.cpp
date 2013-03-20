#include <cstdio>
#include <string>

int b[60][60][60];
bool used[216000];
int q[216000];
int N, M, K, L;
int dir[6][3] =
{
	{ 1, 0, 0 }, { -1, 0, 0 }, { 0, 1, 0 }, { 0, -1, 0 }, { 0, 0, 1 }, { 0, 0, -1 }
};

int getx ( int n, int m, int k )
{
	return ( k * M + m ) * N + n;
}

void setx ( int x, int &n, int &m, int &k )
{
	k = x / ( N * M );
	x = x % ( N * M );
	m = x / N;
	n = x % N;
}

int main ()
{
	while ( scanf ( "%d%d%d%d", &N, &M, &K, &L ) && N )
	{
		memset ( b, 0, sizeof ( b ) );		
		int i, x, n, m, k;
		for ( i = 0; i < L; i ++ )
		{
			scanf ( "%d", &x );
			setx ( x, n, m, k );
			b[n][m][k] = 1;
		}
		memset ( used, 0, sizeof ( used ) );
		int op, ed;	
		int count = 0;
		for ( n = 0; n < N; n ++ )
		{
			for ( m = 0; m < M; m ++ )
			{
				for ( k = 0; k < K; k ++ )
				{
					if ( n != 0 && n != N - 1 && m != 0 && m != M - 1 && k != 0 && k != K - 1 )
						continue;
					if ( b[n][m][k] == 0 )
					{
						b[n][m][k] = 2;
						int x = getx ( n, m, k );
						q[0] = x;
						for ( op = -1, ed = 0; op ++ < ed; )
						{
							int xx = q[op];
							int kk, mm, nn;
							setx ( xx, nn, mm, kk );
							int l;
							for ( l = 0; l < 6; l ++ )
							{
								int nnn = nn + dir[l][0], mmm = mm + dir[l][1], kkk = kk + dir[l][2];
								if ( nnn < 0 || nnn >= N || mmm < 0 || mmm >= M || kkk < 0 || kkk >= K )
									continue;
								if ( b[nnn][mmm][kkk] == 1 )
									count ++;
								if ( b[nnn][mmm][kkk] == 0 )
								{
									b[nnn][mmm][kkk] = 2;
									int xxx = getx ( nnn, mmm, kkk );
									q[++ ed] = xxx;
								}
							}
						}
					}				
				}
			}
		}
		for ( n = 0; n < N; n ++ )
		{
			for ( m = 0; m < M; m ++ )
			{
				if ( b[n][m][0] == 1 )
					count ++;
				if ( b[n][m][K - 1] == 1 )
					count ++;
			}
		}
		for ( k = 0; k < K; k ++ )
		{
			for ( m = 0; m < M; m ++ )
			{
				if ( b[0][m][k] == 1 )
					count ++;
				if ( b[N - 1][m][k] == 1 )
					count ++;
			}
		}
		for ( n = 0; n < N; n ++ )
		{
			for ( k = 0; k < K; k ++ )
			{
				if ( b[n][0][k] == 1 )
					count ++;
				if ( b[n][M - 1][k] == 1 )
					count ++;
			}
		}

		printf ( "The number of faces needing shielding is %d.\n", count );
	}
	return 0;
}
