#include<stdio.h>

int a[300];
int t[300];

int isend(int n)
{
	int i;
	int flag = 1;
	
	for (i=0; i<n; ++i)
	{
		if (a[i] != a[(i+1)%n])
		{
			flag = 0;
			break;
		}
	}
	
	return flag;
}

int main(void)
{
	int n;
	int i;
	int j;
	int w;

	scanf("%d", &n);
	
	while (n != 0)
	{
		w = 0;
		
		for (i=0; i<n; ++i)
		{
			scanf("%d", a+i);
		}
		
		while (isend(n) == 0)
		{
			for (i=0; i<n; ++i)
			{
				t[i] = (a[(i-1+n)%n] + a[i]) / 2;
				
				if (t[i] % 2 == 1)
				{
					++t[i];
				}
			}
			
			for (i=0; i<n; ++i)
			{
				a[i] = t[i];
			}
			
			++w;
		}
		
		printf("%d %d\n", w, a[0]);
		
		scanf("%d", &n);
	}

	return 0;
}
