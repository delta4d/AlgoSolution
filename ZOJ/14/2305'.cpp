#include <cstdio>
typedef long long LL;
using namespace std;

int gao(int a, int b, int &x, int &y)
{
	if (b == 0)
	{
		x = 1;
		y = 0;
		return a;
	}
	int res = gao(b, a%b, x, y);
	int t = x;
	x = y;
	y = t - (a / b) * y;
	return res;
}

int main()
{
	int A;
	int B;
	int C;
	int k;
	int a;
	int b;
	int x;
	int y;
	int t;
	int gcd;
	int res;
	
	freopen("f:\\debug\\in.txt", "r", stdin);
	scanf ("%d %d %d %d", &A, &B, &C, &k);
	
	while (A != 0 || B != 0 || C != 0 || k != 0)
	{
		a = C;
		b = 1 << k;
		gcd = gao(a, -b, x, y);
		if ((B - A) % gcd != 0)
		{
			puts("FOREVER");
		}
		else
		{
			int cc = b / gcd;
			if (cc < 0) cc *= -1;
			int dd = (A - B) * x / gcd;
			t = dd / cc;
			res = -dd * x + cc * t;
			if (res < 0) res += cc;
			printf("%d\n", res);
		}
		
		scanf ("%d %d %d %d", &A, &B, &C, &k);
	}
	
	return 0;
}
