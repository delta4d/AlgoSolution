#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

const int MaxN = 128;
int dx[MaxN];
int dy[MaxN];

inline int cross_product(int x1, int y1, int x2, int y2)
{
	return x1 * y2 - x2 * y1;
}

inline int gcd(int x, int y)
{
	int t;
	x = x > 0 ? x : -x;
	y = y > 0 ? y : -y;
	if (x < y) x ^= y ^= x ^= y;
	while (1)
	{
		if (y == 0) return x;
		t = y;
		y = x % y;
		x = t;
	}
}

int main()
{
	int test_case;
	int tc_num;
	int n;
	int i;
	int j;
	int k;
	int E;
	int I;
	int x;
	int y;
	double A;
	
	//freopen("f:\\in.txt", "r", stdin);
	scanf("%d", &test_case);
	for (tc_num=1; tc_num<=test_case; ++tc_num)
	{
		scanf("%d", &n);
		E = 0;
		for (i=0; i<n; ++i)
		{
			scanf("%d %d", dx+i, dy+i);
			E += gcd(dx[i], dy[i]);
		}
		A = 0;
		x = y = 0;
		for (i=0; i<n; ++i)
		{
			A += cross_product(x, y, x+dx[i], y+dy[i]);
			x += dx[i];
			y += dy[i];
		}
		A = A > 0 ? A/2.0 : -A/2.0;
		I = A + 1 - E / 2.0;
		printf("Scenario #%d:\n", tc_num);
		printf("%d %d %.1lf\n\n", I, E, A); 
	}
	
	return 0;
}
