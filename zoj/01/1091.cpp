#include<stdio.h>

int x[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int y[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int chess[9][9];
int front;
int rear;

struct Queue
{
	int x;
	int y;
}queue[10000];

int bfs(int xd, int yd)
{
	int i;
	int xs;
	int ys;
	int tx;
	int ty;
	long mark = 0;
	
	while (front < rear)
	{
		xs = queue[front].x;
		ys = queue[front].y;
		++front;
		
		for (i=0; i<8; ++i)
		{
			if ((xs == xd) && (ys == yd))
			{
				return chess[xd][yd];
			}
			
			tx = xs + x[i];
			ty = ys + y[i];
			
			if ((tx <= 8) && (tx >= 1) && (ty <= 8) && (ty >= 1) && (chess[tx][ty] == -1))
			{
				queue[rear].x = tx;
				queue[rear].y = ty;
				++rear;
				
				chess[tx][ty] = chess[xs][ys] + 1; 
				
				if ((tx == xd) && (ty == yd))
				{
					return chess[xd][yd];
				}
			}
			
		}
		
	}
	
}

int main(void)
{
	
	int xs;
	int ys;
	int xd;
	int yd;
	int step;
	int i;
	int j;
	char ps[3];
	char pd[3];
	
	while (scanf("%s %s", ps, pd) != EOF)
	{
		for (i=0; i<9; ++i)
		{
			for (j=0; j<9; ++j)
			{
				chess[i][j] = -1;
			}
		}
		
		front = 0;
		rear = 1;
		
		xs = ps[0] - 'a' + 1;
		ys = ps[1] - '0';
		xd = pd[0] - 'a' + 1;
		yd = pd[1] - '0';
		
		chess[xs][ys] = 0;
		
		queue[0].x = xs;
		queue[0].y = ys;
		
		step = bfs(xd, yd);
		
		printf("To get from %s to %s takes %d knight moves.\n", ps, pd, step);
	}
	
	return 0;
}