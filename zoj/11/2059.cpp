#include<stdio.h>
#include<math.h>
#include<memory.h>

int f[2][2001];
int h[100];

int min(int a, int b)
{
	if (a < b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

int max(int a, int b)
{
	if (a > b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

int main(void)
{
	int i;
	int j;
	int k;
	int n;
	int temp;
	
	scanf("%d", &n);
	
	while (n != -1)
	{
		for (i=0; i<n; ++i)
		{
			scanf("%d", h+i);
		}
		
		for (i=0; i<2001; ++i)
		{			
			f[0][i] = -1;
		}
		
		f[0][0] = 0;
		
		for (i=0; i<n; ++i)
		{
			memcpy(f[1],f[0],sizeof(f[0]));
			
			for (j=0; j<2001; ++j)
			{
				if (f[1][j] >= 0)
				{					
					temp = min(f[1][j]+h[i], f[1][j]+j);
					
					f[0][(int)fabs(h[i] - j)] = max(temp, f[0][(int)fabs(h[i] - j)]);
					
					f[0][h[i]+j] = max(f[0][h[i]+j], f[1][j]);
				}
			}
		}
	
		if (f[0][0] == 0)
		{
			printf("Sorry\n");
		}
		else
		{
			printf("%d\n", f[0][0]);
		}
		
		scanf("%d", &n);
	}
	
	return 0;
}
