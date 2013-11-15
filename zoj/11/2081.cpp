#include<cstdio>
#include<memory>
#include<queue>
using namespace std;

struct f
{
	int x;
	int y;
	int step;
};

const int MaxN = 11;
int m;
int n;
int sx;
int sy;
int tx;
int ty;
int total;
int mine;
int len;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
char map[MaxN][MaxN];
char map1[MaxN][MaxN];

bool border(int x, int y)
{
	return (x >= 0) && (x < m) && (y >= 0) && (y < n);
}

void bfs()
{
	int i;
	int j;
	int x;
	int y;
	f temp;
	f temp1;
	queue<f>Q;
	
	temp.x = sx;
	temp.y = sy;
	temp.step = 0;
	map[sx][sy] = '#';
	Q.push(temp);
	
	while (!Q.empty())
	{
		temp = Q.front();
		Q.pop();
		
		if ((temp.x == tx) && (temp.y == ty))
		{
			len = temp.step;
			return;
		}
		
		for (i=0; i<4; ++i)
		{
			x = temp.x + dx[i];
			y = temp.y + dy[i];
			
			if ((map[x][y] != '#') && border(x, y))
			{
				temp1.x = x;
				temp1.y = y;
				temp1.step = temp.step + 1;
				map[x][y] = '#';
				
				Q.push(temp1);
			}
		}
	}
}

void dfs(int x, int y, int step, bool pass_mine)
{
	int i;
	int j;
	int tempx;
	int tempy;
	char ch;
	
	if ((x == tx) && (y == ty))
	{
		++total;
		
		if (pass_mine)
		{
			++mine;
		}
		
		return;
	}
	
	if (step >=len)
	{
		return;
	}
	
	for (i=0; i<4; ++i)
	{
		tempx = x + dx[i];
		tempy = y + dy[i];
		
		if ((map1[tempx][tempy] != '#') && border(tempx, tempy))
		{
			ch = map1[tempx][tempy];
			map1[tempx][tempy] = '#';
			
			if (ch == 'M')
			{		
				dfs(tempx, tempy, step + 1, true);
			}
			else
			{
				dfs(tempx, tempy, step + 1, pass_mine);
			}
			
			map1[tempx][tempy] = ch;
		}
	}
}

int main(void)
{
	int i;
	int j;
	int k;
	int test_case;
	double p;
	bool find_spy;
	bool find_tmt;
	
	scanf("%d", &test_case);
	
	for (k=1; k<=test_case; ++k)
	{
		scanf("%d %d", &m, &n);
		getchar();
		find_tmt = false;
		find_spy = false;
		
		for (i=0; i<m; ++i)
		{
			gets(map[i]);
			
			if (!find_tmt || !find_spy)
			{
				for (j=0; j<n; ++j)
				{
					if (map[i][j] == 'S')
					{
						sx = i;
						sy = j;
						find_spy = true;
					}
					
					if (map[i][j] == 'T')
					{
						tx = i;
						ty = j;
						find_tmt = true;
					}
				}
			}
		}
		
		memcpy(map1, map, sizeof(map));
		
		bfs();
		
		total = 0;
		mine = 0;
		
		dfs(sx, sy, 0, false);
		
		printf("Mission #%d:\n", k);
		
		if (mine == total)
		{
			printf("Mission Impossible.\n\n");
		}
		else
		{
			p = (double)(total - mine) / total * 100.0;
			printf("The probability for the spy to get to the telegraph transmitter is %.2lf%%.\n\n", p);
		}
	}
	
	return 0;
}
