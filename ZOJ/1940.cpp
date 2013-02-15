#include<cstdio>
#include<queue>
using namespace std;

struct Cor
{
	int x;
	int y;
	int z;
	int step;
};

const int MaxN = 31;
bool find;
int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};
int xn;
int yn;
int zn;
int sx;
int sy;
int sz;
int ex;
int ey;
int ez;
int len;
char maze[MaxN][MaxN][MaxN];

bool border(int x, int y, int z)
{
    return (x >= 0) && (x < xn) && (y >= 0) && (y < yn) && (z >= 0) && (z < zn);
}

void bfs()
{
	int i;
	int j;
	int k;
	int tx;
	int ty;
	int tz;
	Cor temp;
	Cor ff;
	queue<Cor>f;
	
	find = false;
	
	temp.x = sx;
	temp.y = sy;
	temp.z = sz;
	temp.step = 0;
	maze[sx][sy][sz] = '#';
	f.push(temp);
	
	while (!f.empty())
	{
		ff = f.front();
		f.pop();
		
		if ((ff.x == ex) && (ff.y == ey) && (ff.z == ez))
		{
			find = true;
			len = ff.step;
			return;
		}
		
		for (i=0; i<6; ++i)
		{
			tx = ff.x + dx[i];
			ty = ff.y + dy[i];
			tz = ff.z + dz[i];
			
			if (border(tx, ty, tz) && (maze[tx][ty][tz] != '#'))
			{
				temp.x = tx;
				temp.y = ty;
				temp.z = tz;
				temp.step = ff.step + 1;
				maze[tx][ty][tz] = '#';
				f.push(temp);
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
    bool finds;
    bool finde;

    scanf("%d %d %d", &xn, &yn, &zn);

    while (xn != 0 || yn != 0 || zn != 0)
    {
        finds = finde = false;

        for (i=0; i<xn; ++i)
        {
            for (j=0; j<yn; ++j)
            {
                scanf("%s", maze[i][j]);

                if (!finde || !finds)
                {
                    for (k=0; k<zn; ++k)
                    {
                        if (maze[i][j][k] == 'S')
                        {
                        	sx = i;
                        	sy = j;
                        	sz = k;
                        	finds = true;
						}
						
						if (maze[i][j][k] == 'E')
						{
							ex = i;
							ey = j;
							ez = k;
							finde = true;
						}
                    }
                }
            }
        }
        
        bfs();
        
        if (find)
        {
        	printf("Escaped in %d minute(s).\n", len);
		}
		else
		{
			printf("Trapped!\n");
		}
        
        scanf("%d %d %d", &xn, &yn, &zn);
    }

    return 0;
}
