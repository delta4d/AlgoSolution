#include<cstdio>
#include<memory>

using namespace std;

const int MaxN = 60;
int cnt;
int x;
int y;
int z;
int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};
int graph[MaxN][MaxN][MaxN];

bool face(int tx, int ty, int tz)
{
	return (tx == 0) || (tx == x - 1) || (ty == 0) || (ty == y - 1) || (tz == 0) || (tz == z - 1);
}

bool border(int tx, int ty, int tz)
{
    return (tx >= 0) && (tx < x) && (ty >= 0) && (ty < y) && (tz >= 0) && (tz < z);
}

void floodfill(int xx, int yy, int zz)
{
    int i;
    int j;
    int k;
    int t;
    int tx;
    int ty;
    int tz;

    graph[xx][yy][zz] = 2;

    for (t=0; t<6; ++t)
    {
        tx = xx + dx[t];
        ty = yy + dy[t];
        tz = zz + dz[t];
        if (border(tx, ty, tz))
        {
            if (graph[tx][ty][tz] == 0)
            {
                floodfill(tx, ty, tz);
            }
            else if (graph[tx][ty][tz] == 1)
            {
                ++cnt;
            }
        }
    }
}

void f(void)
{
    int i;
    int j;
    int k;
    for (i=0; i<x; ++i)
    {
    	for (j=0; j<y; ++j)
    	{
    		for (k=0; k<z; ++k)
    		{
    			if (face(i, j, k) && (graph[i][j][k] == 0))
    			{
    				floodfill(i, j, k);
				}
			}
		}
	}
}

void g(void)
{
    int i;
    int j;
    int k;
    for (i=0; i<x; ++i)
    {
        for (j=0; j<y; ++j)
        {
            if (graph[i][j][0] == 1)
            {
                ++cnt;
            }
            if (graph[i][j][z-1] == 1)
            {
                ++cnt;
            }
        }
    }
    for (i=0; i<y; ++i)
    {
        for (j=0; j<z; ++j)
        {
            if (graph[0][i][j] == 1)
            {
                ++cnt;
            }
            if (graph[x-1][i][j] == 1)
            {
                ++cnt;
            }
        }
    }
    for (i=0; i<x; ++i)
    {
        for (j=0; j<z; ++j)
        {
            if (graph[i][0][j] == 1)
            {
                ++cnt;
            }
            if (graph[i][y-1][j] == 1)
            {
                ++cnt;
            }
        }
    }
}

int main(void)
{
    int i;
    int j;
    int k;
    int n;
    int t;
    int tx;
    int ty;
    int tz;

    scanf("%d %d %d %d", &z, &y, &x, &n);

    while (z != 0 || y != 0 || x != 0 || n != 0)
    {
        memset(graph, 0, sizeof(graph));
        cnt = 0;

        for (i=0; i<n; ++i)
        {
            scanf("%d", &t);
            tx = t / (y * z);
            t %= (y * z);
            ty = t / z;
            t %= z;
            tz = t;
            graph[tx][ty][tz] = 1;
        }

        f();
        g();

        printf("The number of faces needing shielding is %d.\n", cnt);

        scanf("%d %d %d %d", &z, &y, &x, &n);
    }

    return 0;
}
