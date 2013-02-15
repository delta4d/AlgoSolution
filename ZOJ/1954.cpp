#include <cstdio>
using namespace std;

const int MAXN = 100001;
struct node
{
	int x;
	int y;
	node(int x=0, int y=0):x(x), y(y) {}
	void Print()
	{
		printf("%d %d\n", x, y);
	}
}f[MAXN];

void gen()
{
	int i;
	int depth;
	int x;
	int y;
	for (i=2; i<MAXN; ++i)
	{
		x = f[i-1].x;
		y = f[i-1].y;
		if (x >= 0 && y == 0) // x+
		{
			f[i].x = x;
			f[i].y = y + 1;
			depth = x + 1;
		}
		else if (x > 0 && y > 0) //1
		{
			f[i].x = x - 1;
			f[i].y = y + 1;
		}
		else if (x == 0 && y > 0) //y+
		{
			f[i].x = x - 1;
			f[i].y = y;
		}
		else if (x < 0 && y > 0) //2
		{
			if (x > -depth) //go ahead
			{
				f[i].x = x - 1;
				f[i].y = y;
			}
			else if (x == -depth) //turn
			{
				f[i].x = x;
				f[i].y = y - 1;
			}
		}
		else if (x < 0 && y == 0) //x-
		{
			f[i].x = x + 1;
			f[i].y = y - 1;
		}
		else if (x < 0 && y < 0) //3
		{
			f[i].x = x + 1;
			f[i].y = y - 1;
		}
		else if (x == 0 && y < 0) //y-
		{
			f[i].x = x + 1;
			f[i].y = y;
		}
		else if (x > 0 && y < 0) //4
		{
			if (x < depth) //go ahead
			{
				f[i].x = x + 1;
				f[i].y = y;
			}
			else if (x == depth) //turn
			{
				f[i].x = x;
				f[i].y = y + 1;
			}
		}
		else //where does (x, y) exist ...
		{
			printf("error !!!\n");
		}
	}
}

int main()
{
	int n;
	//freopen("f:\\in.txt", "r", stdin);
	//freopen("f:\\out.txt", "w", stdout);
	gen();
	//for (int i=1; i<=100; ++i) f[i].Print();
	while (scanf("%d", &n) != EOF) f[n].Print();
	return 0;
}
