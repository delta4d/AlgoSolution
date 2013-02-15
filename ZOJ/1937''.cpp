#include<cstdio>
#include<cmath>

using namespace std;

bool found;
int f[10];
int res[10];
int opd;
int deapth;
int n;

void dfs(int k)
{
	if (!found)
	{
		if (f[k] == n)
		{
			opd = k;
			
			for (int i=0; i<=k; ++i)
			{
				res[i] = f[i];
			}
			
			found = true;			
			return;
		}
		else if (k < deapth)
		{
			for (int i=k; i>=0; --i)
			{
				if (2 * f[i] > f[k])
				{
					for (int j=i; j>=0; --j)
					{
						if (f[i] + f[j] > f[k] && f[i] + f[j] <= n)
						{
							f[k+1] = f[i] + f[j];
							
							dfs(k+1);
						}
					}
				}
			}
		}
	}
}

int main()
{	
	scanf("%d", &n);
	
	while (n != 0)
	{
		found = false;
		deapth = (int)(log(n) / log(2));
		
		while (!found)
		{
			f[0] = 1;
			dfs(0);
			++deapth;
		}
		
		for (int i=0; i<opd; ++i)
		{
			printf("%d ", res[i]);
		}
		
		printf("%d\n", n);
		
		scanf("%d", &n);
	}
	
	return 0;
}
