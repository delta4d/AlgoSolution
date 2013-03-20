#include <cstdio>
#include <memory>
using namespace std;

const int INF = 0x7fffffff;
const int MaxN = 101;
struct node
{
	int x;
	int y;
	int w;
}e[MaxN];
int d[MaxN];

int main()
{
	int n;
	int m;
	int i;
	int j;
	int k;
	int x;
	int y;
	int w;
	char op[3];
	bool suc;
	
	freopen("f:\\in.txt", "r", stdin);
	
	scanf("%d", &n);
	while (n != 0)
	{
		scanf("%d", &m);
		for (i=0; i<m; ++i)
		{
			scanf("%d %d %s %d", &x, &y, op, &w);
			y += x;
			--x;
			if (op[0] == 'g')
			{
				e[i].x = x;
				e[i].y = y;
				e[i].w = -w - 1;
			}
			else
			{
				e[i].x = y;
				e[i].y = x;
				e[i].w = w - 1;
			}
		}
		
		//Bellman-Ford
		fill(d, d+MaxN, INF);
		for (i=0; i<=n; ++i)
		{
			suc = false;
			for (j=0; j<m; ++j)
			{
				if (d[e[j].y] > d[e[j].x] + e[j].w)
				{
					d[e[j].y] = d[e[j].x] + e[j].w;
					suc = true;
				}
			}
		}
		
		if (suc) puts("successful conspiracy");
		else puts("lamentable kingdom");
		scanf("%d", &n);
	}
	
	return 0;
}
