#include<iostream>
#include<cstdio>
#include<queue>
#include<memory>
using namespace std;

int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};
int graph[202][202];
int visit[202][202];

struct node
{
    int x;
    int y;
    int step;
    
    node(int x, int y, int step) : x(x), y(y), step(step){}
};

int bfs(int sx, int sy, int fx, int fy)
{
    queue<node>Q;
    int i;
    int j;
    int k;
    int tx;
    int ty;   

	memset(visit,0,sizeof(visit));

    Q.push(node(sx, sy, 0));
    visit[sx][sy] = 1;

    while (!Q.empty())
    {
        node t = Q.front();
        Q.pop();
  		
    	if (graph[t.x][t.y] == 2)
    	{
    		visit[t.x][t.y] = 1;
    		graph[t.x][t.y] = 1;
    		Q.push(node(t.x, t.y, t.step + 1));
		}
		else
    	{
    		for (i=0; i<4; ++i)
    		{
    			tx = t.x + dx[i];
    			ty = t.y + dy[i];
    			
    			if (tx == fx && ty == fy)
    			{
    				return t.step + 1;
				}
				
				if ((graph[tx][ty] == 1 || graph[tx][ty] == 2) && visit[tx][ty] == 0)
				{
					visit[tx][ty] = 1;
					Q.push(node(tx, ty, t.step + 1));
				}
			}
		}
       	
    }
	
	return -1;

}

int main()
{
    int m;
    int n;
    int i;
    int j;
    int len;
    int sx;
    int sy;
    int fx;
    int fy;
    int step;
    char temp[201];

    while (scanf("%d %d", &m, &n) != EOF)
    {
        for (i=0; i<=m+1; ++i)
        {
            for (j=0; j<=n+1; ++j)
            {
                graph[i][j] = 0;
            }
        }

        for (i=1; i<=m; ++i)
        {
        	scanf("%s", temp);
        	
            len = strlen(temp);

            for (j=0; j<len; ++j)
            {
                if (temp[j] == 'r')
                {
                    sx = i;
                    sy = j + 1;
                    graph[sx][sy] = 1;
                }
                else if (temp[j] == 'a')
                {
                    fx = i;
                    fy = j + 1;
                    graph[fx][fy] = 1;
                }
                else if (temp[j] == '.')
                {
                    graph[i][j+1] = 1;
                }
                else if (temp[j] == 'x')
                {
                    graph[i][j+1] = 2;
                }
            }
        }

        step = bfs(sx, sy, fx, fy);
        
        if (step == -1)
        {
        	printf("Poor ANGEL has to stay in the prison all his life.\n");
		}
		else
		{		
			printf("%d\n", step);
		}
    }

    return 0;
}
