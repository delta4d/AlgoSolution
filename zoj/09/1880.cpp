#include<cstdio>
#include<memory>

using namespace std;

const int MaxN = 101;
const int MaxW = 25001;

bool f[MaxN][MaxW];
int w[MaxN];

int main(void)
{
	int n;
	int i;
	int j;
	int k;
	int sum;
	
	while (scanf("%d", &n) != EOF)
	{
		sum = 0;
		
		for (i=0; i<n; ++i)
		{
			scanf("%d", w + i);
			sum += w[i];
		}
		
		memset(f, false, sizeof(f));

		f[0][0] = true;
		
		for (k=0; k<n; ++k)
		{
			for (i=(n+1)/2; i>=0; --i)
			{
				for (j=sum/2; j>=0; --j)
				{
					if (f[i][j] && !f[i+1][j+w[k]])
					{
						f[i+1][j+w[k]] = true;
					}
				}
			}
		}
		
		for (i=sum/2; i>=0; --i)
		{
			if (f[n/2][i] || f[(n+1)/2][i])
			{
				break;
			}
		}
		
		printf("%d %d\n", i, sum-i);
	}
	
	return 0;
}
