#include<cstdio>
#include<memory>
#include<cstdlib>
using namespace std;

const int MaxN = 51;
int cnt;
int xn;
int yn;
int zn;
int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};
char graph[MaxN][MaxN][MaxN];

struct T
{
	int time[MaxN*MaxN*MaxN];
	int num;
}f[4];

int cmp(const void *a, const void *b)
{
	return *(int *)b - *(int *)a;
}

bool border(int x, int y, int z)
{
	return (x >= 0) && (x < xn) && (y >= 0) && (y < yn) && (z >= 0) && (y <yn);
}

void floodfill(int x, int y, int z, char &m)
{
	int i;
	int j;
	int k;
	int tx;
	int ty;
	int tz;
	
	graph[x][y][z] = '*';
	
	for (i=0; i<6; ++i)
	{
		tx = x + dx[i];
		ty = y + dy[i];
		tz = z + dz[i];
		
		if (border(tx, ty, tz) && (graph[tx][ty][tz] == m))
		{
			++cnt;
			floodfill(tx, ty, tz, m);
		}
	}
}

int main(void)
{
	int i;
	int j;
	int k;
	int case_num(1);
	char t;
	
	scanf("%d %d %d", &yn, &zn, &xn);
	
	while (1)
	{
		for (i=0; i<xn; ++i)
		{
			for (j=0; j<yn; ++j)
			{
				scanf("%s", graph[i][j]);
			}
		}
		
		memset(f, 0, sizeof(f));
		
		for (i=0; i<xn; ++i)
		{
			for (j=0; j<yn; ++j)
			{
				for (k=0; k<zn; ++k)
				{
					t = graph[i][j][k];
					
					if (t != '*')
					{
						cnt = 1;
						floodfill(i, j, k, t);
						f[t-'a'].time[f[t-'a'].num] = cnt;
						++f[t-'a'].num;
					}
				}
			}
		}
		
		for (i=0; i<4; ++i)
		{
			qsort(f[i].time, f[i].num, sizeof(f[i].time[0]), cmp);
		}
		
		printf("Case %d:\n", case_num);
		++case_num;
		
		for (i=0; i<4; ++i)
		{
			printf("%c ", 'a' + i);
			
			for (j=0; j<f[i].num-1; ++j)
			{
				printf("%d ", f[i].time[j]);
			}
			
			printf("%d\n", f[i].time[j]);
		}
		
		if (scanf("%d %d %d", &yn, &zn, &xn) == EOF)
		{
			break;
		}
		
		printf("\n");
	}
	
	return 0;
}
