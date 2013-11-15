#include<stdio.h>

int main(void)
{
	int p;
	int e;
	int i;
	int d;
	int k;
	int t;
	int x;
	int order;
	int flag1;
	int flag2;
	int temp;
	int TestCase;
	
	scanf("%d", &TestCase);
	
	for (t=0; t<TestCase; ++t)
	{
		order = 1;
		scanf("%d %d %d %d", &p, &e, &i, &d);
		
		while (p != -1 || e != -1 || i != -1 || d != -1)
		{
			p = p % 23 + d;
			e = e % 28 + d;
			i = i % 33 + d;
			
			for (x=i; ; x+=33)
			{
				flag1 = flag2 = 0;
				
				temp = x - e;
				
				if (temp == (temp / 28) * 28)
				{
					flag1 = 1;
				}
				
				temp = x - p;
				
				if (temp == (temp / 23) * 23)
				{
					flag2 = 1;
				}
				
				if ((flag1 == 1) && (flag2 == 1) && (x > d))
				{
					break;
				}
			}
			
			printf("Case %d: the next triple peak occurs in %d days.\n", order, x - d);
			++order;
			
			scanf("%d %d %d %d", &p, &e, &i, &d);
		}
		
		if (t < TestCase - 1)
		{
			printf("\n");
		}
	}
	
	return 0;
}
