#include<cstdio>
#include<queue>

using namespace std;

const int MaxN = 11; 

int sx;
int sy;
int sz;
int tx;
int ty;
int tz;
int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};
int len;
char graph[MaxN][MaxN][MaxN];
bool flag;

struct Cor
{
	int x;
	int y;
	int z;
	int step;
	
	Cor (int x, int y, int z, int step) : x(x), y(y), z(z), step(step){}
};

bool border(int x, int y, int z, int n)
{
	if ((x < n) && (x >= 0) && (y < n) && (y >= 0) && (z < n) && (z >= 0))
	{
		return true;
	}
	
	return false;
}

void bfs(int n)
{
	int i;
	int j;
	int k;
	int tempx;
	int tempy;
	int tempz;
	
	queue<Cor>Q;
	Q.push(Cor(sx, sy, sz, 0));
	graph[sx][sy][sz] = 'X';
	
	while (!Q.empty())
	{
		Cor temp = Q.front();
		Q.pop();
		
		if ((temp.x == tx) && (temp.y == ty) && (temp.z == tz))
		{
			flag = true;
			len = temp.step;
			return;
		}
		
		for (i=0; i<6; ++i)
		{
			tempx = temp.x + dx[i];
			tempy = temp.y + dy[i];
			tempz = temp.z + dz[i];
			
			if (border(tempx, tempy, tempz, n) && (graph[tempx][tempy][tempz] == 'O'))
			{
				Q.push(Cor(tempx, tempy, tempz, temp.step + 1));
				graph[tempx][tempy][tempz] = 'X';
			}
		}
	}
	
	return;
}

int main(void)
{
	int i;
	int j;
	int k;
	int n;
	char order[10];
	
	while (scanf("%s %d", order, &n) != EOF)
	{
		for (i=0; i<n; ++i)
		{
			for (j=0; j<n; ++j)
			{
				scanf("%s", graph[i][j]);
			}
		}
		
		scanf("%d %d %d", &sz, &sy, &sx);
		scanf("%d %d %d", &tz, &ty, &tx);
		scanf("%s", order);
		
		flag = false;
		
		bfs(n);
		
		if (flag)
		{
			printf("%d %d\n", n, len);
		}
		else
		{
			printf("NO ROUTE\n");
		}
	}
	
	return 0;
}
