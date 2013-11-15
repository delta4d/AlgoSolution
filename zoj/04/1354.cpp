#include <cstdio>
#include <memory>
using namespace std;

#define FOR(i, x) for ((i)=1; (i)<=(x); ++(i))
const int row = 7;
const int col = 8;
int temp[row][col];
int light[row][col];
int op[row][col];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool gao(int n)
{
	int i;
	int j;
	int k;
	memset(op, 0, sizeof(op));
	memcpy(temp, light, sizeof(light));
	for (k=1; k<=6; ++k)
	{
		op[1][k] = n % 2;
		n /= 2;
		if (op[1][k] == 1)
		{
			temp[1][k] ^= 1;
			for (i=0; i<4; ++i) temp[1+dx[i]][k+dy[i]] ^= 1;
		}
	}
	for (i=2; i<=5; ++i)
	{
		for (j=1; j<=6; ++j)
		{
			if (temp[i-1][j] == 1)
			{
				op[i][j] = 1;
				temp[i][j] ^= 1;
				for (k=0; k<4; ++k) temp[i+dx[k]][j+dy[k]] ^= 1;
			}
		}
	}
	for (i=1; i<=6; ++i) if (temp[5][i] == 1) return false;
	return true;
}

int main()
{
	int i;
	int j;
	int k;
	int t;
	int tc;
	//freopen("f:\\in.txt", "r", stdin);
	scanf("%d", &tc);
	for (t=1; t<=tc; ++t)
	{
		for (i=1; i<=5; ++i) for (j=1; j<=6; ++j) scanf("%d", light[i]+j);
		for (k=0; k<64; ++k)
		{
			if (gao(k))
			{
				printf("PUZZLE #%d\n", t);
				for (i=1; i<=5; ++i)
				{
					for (j=1; j<=6; ++j)
					{
						printf("%d", op[i][j]);
						printf("%c", j==6?'\n':' ');
					}
				}
				break;
			}
		}
	}
	
	return 0;
}