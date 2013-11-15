#include <cstdio>
#include <cstring>
using namespace std;

#define debug 0
struct R
{
	int x;
	int y;
	int d;
};
const int MaxN = 64;
const int MaxL = 1024;
const char dir[5] = {"NWSE"};
char maze[MaxN][MaxN];
char order[MaxL];

int main()
{
	int m;
	int n;
	int i;
	int j;
	int k;
	int len;
	R robot;
	bool wanshi;
#if debug
	freopen("f:\\in.txt", "r", stdin);
#endif
	while (scanf("%d %d", &m, &n) != EOF)
	{
		getchar();
		for (i=1; i<=m; ++i) gets(maze[i]+1);
		scanf("%d %d", &robot.x, &robot.y);
		robot.d = 0;
		wanshi = false;
		while (1)
		{
			scanf("%s", order);
			len = strlen(order);
			for (i=0; i<len; ++i)
			{
				switch (order[i])
				{
					case 'L': ++robot.d; robot.d %= 4; break;
					case 'R': robot.d += 3; robot.d %= 4; break;
					case 'F': switch (robot.d)
                              {
                              		case 0: if (maze[robot.x-1][robot.y] != '*') --robot.x; break;
                              		case 1: if (maze[robot.x][robot.y-1] != '*') --robot.y; break;
                              		case 2: if (maze[robot.x+1][robot.y] != '*') ++robot.x; break;
                              		case 3: if (maze[robot.x][robot.y+1] != '*') ++robot.y; break;
                              		default: printf("F error!\n"); throw "error !"; break;
							  }break;
					case 'Q': wanshi = true; break;
					default: printf("S error!\n"); throw "error!"; break;
				}
			}
			if (wanshi) break;
		}
		printf("%d %d %c\n", robot.x, robot.y, dir[robot.d]);
	}
	
	return 0;
}
