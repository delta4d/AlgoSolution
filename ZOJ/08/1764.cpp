#include<stdio.h>

#define Inf 30000;

int main(void)
{
	int n;
	int sub;
	int time;
	int i;
	int j;
	int points;
	int min;
	int solved;
	int sol;
	char name[30];
	char temp[30];
	
	scanf("%d", &n);
	min = Inf;
	solved = -1;
	
	for (i=0; i<n; ++i)
	{	
		scanf("%s", temp);
		
		sol = 0;
		points = 0;
		
		for (j=0; j<4; ++j)
		{
			scanf("%d %d", &sub, &time);
			
			if (time != 0)
			{
				points = points + time + (sub - 1) * 20;
				++sol;
			}
		}
		
		if ((sol > solved) || ((solved == sol) && (points < min)))
		{
			strcpy(name, temp);
			min = points;
			solved = sol;
		}
	}
	
	printf("%s %d %d\n", name, solved, min);

	return 0;
}
