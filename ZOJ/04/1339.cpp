#include <cstdio>
#include <memory>
#include <cstring>
#include <algorithm>
using namespace std;

#define debug 0
const int INF = 0x3f3f3f3f;
const int MaxR = 20;
const int MaxC = 30;
char image[MaxR][MaxC];

int main()
{
	int i;
	int j;
	int n;
	int res;
	int len;
	int d;
	int cd;
#if debug
	freopen("f:\\in.txt", "r", stdin);
#endif	
	scanf("%d", &n);
	while (n != 0)
	{
		getchar();
		for (i=0; i<n; ++i) gets(image[i]);
		len = strlen(image[0]);
		d = INF;
		res = 0;
		for (i=0; i<n; ++i)
		{
			cd = 0;
			for (j=0; j<len; ++j)
			{
				if (image[i][j] != 'X')
				{
					++cd;
				}
			}
			d = min(cd, d);
			res += cd;
		}
		res -= d * n;
		printf("%d\n", res);
		scanf("%d", &n);
	}
	
	return 0;
}
