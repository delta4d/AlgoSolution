#include <cstdio>
#include <cmath>
using namespace std;

#define debug 0
const int MaxN = 1024;
int n;
double x[MaxN];
double y[MaxN];

inline double cross_product(double x1, double y1, double x2, double y2)
{
	return x1 * y2 - x2 * y1;
}

inline double area()
{
	int i;
	double res(0);
	for (i=0; i<n; ++i) res += cross_product(x[i], y[i], x[i+1==n?0:i+1], y[i+1==n?0:i+1]);
	return res > 0 ? res/2.0 : -res/2.0;
}

bool is_intersect(double x11, double y11, double x12, double y12, double x21, double y21, double x22, double y22)
{
	return cross_product(x12-x11, y12-y11, x22-x11, y22-y11) * cross_product(x12-x11, y12-y11, x21-x11, y21-y11) < 0
		&& cross_product(x22-x21, y22-y21, x12-x21, y12-y21) * cross_product(x22-x21, y22-y21, x11-x21, y11-y21) < 0;
}

bool is_parallel(double x1, double y1, double x2, double y2)
{
	return cross_product(x1, y1, x2, y2) == 0;
}

bool judge(int k)
{
	int i;
	int j;
	for (i=0; i<k-2; ++i) if (is_intersect(x[i], y[i], x[i+1], y[i+1], x[k-1], y[k-1], x[k], y[k])) return false;
	if (is_parallel(x[k-1]-x[k-2], y[k-1]-y[k-2], x[k]-x[k-1], y[k]-y[k-1])) return false;
	if (k == n - 1)
	{
		for (i=0; i<n-2; ++i) if (is_intersect(x[i], y[i], x[i+1], y[i+1], x[0], y[0], x[k], y[k])) return false;
	}
	if (k == n - 1) if (is_parallel(x[0]-x[1], y[0]-y[1], x[k]-x[0], y[k]-y[0])) return false;
	return true;
}

int main()
{
	int i;
	int j;
	int k;
	int case_num(0);
	bool kegao;
#if debug
	freopen("f:\\in.txt", "r", stdin);
#endif
	scanf("%d", &n);
	while (n != 0)
	{
		printf("Figure %d: ", ++case_num);
		if (n <= 2)
		{
			for (i=0; i<n; ++i) scanf("%lf %lf", x, y);
			puts("Impossible");
			goto gaoding;
		}
		if (n == 3)
		{
			for (i=0; i<n; ++i) scanf("%lf %lf", x+i, y+i);
			printf("%.2lf\n", area());
			goto gaoding;
		}
		kegao = true;
		for (i=0; i<n; ++i)
		{
			scanf("%lf %lf", x+i, y+i);
			if (i < 3) continue;
			if (kegao) if (!judge(i)) kegao = false;
		}
		if (kegao) printf("%.2lf\n", area());
		else puts("Impossible");
gaoding:
		scanf("%d", &n);
		if (n != 0) printf("\n");		
	}
	
	return 0;
}
