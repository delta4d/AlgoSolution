#include <cstdio>
using namespace std;

const int MaxN = 10001;
int n;
int p;
int cable[MaxN];

inline int calc(int x)
{
	int res(0);
	for (int i=0; i<n; ++i) res += cable[i] / x;
	return res;
}

void gao(int left, int right)
{
	int i;
	int cur;
	int mid((left + right) / 2);
	while (left <= right)
	{
		cur = calc(mid);
		if (cur >= p)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
		mid = (left + right) / 2;
	}
	if (mid == 0) printf("0.00\n");
	else printf("%.2lf\n", mid/100.0);
}

int main()
{
	int i;
	int j;
	int k;
	int tc;
	int max;
	double x;
	//freopen("f:\\in.txt", "r", stdin);
	scanf("%d", &tc);
	for (k=0; k<tc; ++k)
	{
		max = -1;
		scanf("%d %d", &n, &p);
		for (i=0; i<n; ++i)
		{
			scanf("%lf", &x);
			cable[i] = x * 100 + 0.5;
			max = max < cable[i] ? cable[i] : max;
		}
		gao(1, max);
		if (k != tc - 1) printf("\n");
	}
	
	return 0;
}