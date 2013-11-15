#include<stdio.h>

int GetFacNum(int n, int fac)
{
	int res;
	
	res = 0;
	
	while (n % fac == 0)
	{
		n /= fac;
		++res;
	}
	
	return res;
}

int main(void)
{
	int flag;
	int i;
	int d;
	int x;
	int p2;
	int p3;
	int p5;
	int off_p2;
	int off_p3;
	int off_p5;
	
	scanf("%d %d", &x, &d);
	
	while (x != 0 || d != 0)
	{
		p2 = GetFacNum(x, 2);
		p3 = GetFacNum(x, 3);
		p5 = GetFacNum(x, 5);
		off_p2 = GetFacNum(d+1, 2);
		off_p3 = GetFacNum(d+1, 3);
		off_p5 = GetFacNum(d+1, 5);
		
		flag = 1;
		
		if (((p2 < 2) && (off_p2 == 0)) || ((p3 == 0) && (off_p3 == 0)) || ((p5 == 0) && (off_p5 == 0)))
		{
			flag = 0;
		}
		else
		{
			for (i=1; ; ++i)
			{
				p2 += off_p2;
				p3 += off_p3;
				p5 += off_p5;
				
				if ((p2 >= 2) && (p3 >= 1) && (p5 >= 1))
				{
					break;
				}
			}
		}
		
		if (flag == 1)
		{
			printf("%d\n", i);
		}
		else
		{
			printf("Impossible\n");
		}
		
		scanf("%d %d", &x, &d);
	}

	return 0;
}
