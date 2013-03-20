#include <cstdio>
#include <memory>
#include <cstring>
using namespace std;

#define debug 0
const int MaxN = 10;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};
char graph[MaxN][MaxN];
bool zhaodaole;
int n;
int m;
int t;
int sx;
int sy;
int ex;
int ey;
int avi;

inline bool border(int x, int y)
{
	return x >= 0 && x < n && y >= 0 && y < m;
}

void dfs(int x, int y, int cost)
{
	int i;
	int tx;
	int ty;
	if (cost == t && x == ex && y == ey)
	{
		zhaodaole = true;
		return;
	}
	if (zhaodaole) return;
	int v = t - cost - abs(ex-x)-abs(ey-y);
    if(v < 0 || v & 1) return;//if((abs(destx-ic)+abs(desty-jc))%2!=(t-tc)%2)return;
	for (i=0; i<4; ++i)
	{
		tx = x + dx[i];
		ty = y + dy[i];
		if (graph[tx][ty] != 'X' && border(tx, ty))
		{
			graph[tx][ty] = 'X';
			dfs(tx, ty, cost+1);
			if (zhaodaole) return;
			graph[tx][ty] = '.';
		}
	}
}

int main()
{
    int i;
    int j;
#if debug
    freopen("f:\\in.txt", "r", stdin);
#endif
    scanf("%d %d %d", &n, &m, &t);
    while (n != 0 || m != 0 || t != 0)
    {
        avi = 1;
        for (i=0; i<n; ++i) scanf("%s", graph[i]);
        for (i=0; i<n; ++i)
        {
        	for (j=0; j<m; ++j)
        	{
        		if (graph[i][j] == 'D') {ex = i; ey = j;}
        		else if (graph[i][j] == 'S') {sx = i; sy = j;}
        		else if (graph[i][j] == '.') ++avi;
			}
		}
        if (avi < t) printf("NO\n");
        else
        {
 	        zhaodaole = false;
 	        graph[sx][sy] = 'X';
  	        dfs(sx, sy, 0);
   	        if (zhaodaole) printf("YES\n");
   	        else printf("NO\n");
		}
        
        scanf("%d %d %d", &n, &m, &t);
    }

    return 0;
}
