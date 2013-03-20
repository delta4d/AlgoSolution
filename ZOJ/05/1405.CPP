#include<stdio.h>

int main(void)
{
	char away[100];
	char customer[100];
	int i;
	int j;
	int k;
	int n;
	int len;
	int CurLive;
	int IsLive;
	int IsAway;
	int res;

	scanf("%d", &n);

	while (n != 0)
	{
		scanf("%s", customer);

		k = 0;
		res = 0;
		CurLive = 0;
		len = strlen(customer);

		for (i=0; i<len; ++i)
		{
			IsAway = 0;

			for (j=0; j<k; ++j)
			{
				if (away[j] == customer[i])
				{
					IsAway = 1;
					break;
				}
			}

			if (IsAway == 0)
			{

				IsLive = 0;

				for (j=0; j<i; ++j)
				{
					if (customer[j] == customer[i])
					{
						IsLive = 1;
						break;
					}
				}
			
				if (IsLive == 1)
				{
					--CurLive;
				}
				else
				{
					if (CurLive < n)
					{
						++CurLive;
					}
					else
					{
						away[k] = customer[i];
						++k;
						++res;
					}
				}
			}
		}
		
		if (res == 0)
		{
			printf("All customers tanned successfully.\n");
		}
		else
		{
			printf("%d customer(s) walked away.\n", res);
		}
		
		scanf("%d", &n);
	}
	
	return 0;
}
