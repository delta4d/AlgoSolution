#include<stdio.h>
#include<math.h>

int known[111];
double dis[111];
double len;

struct City
{
	double x;
	double y;
}cities[111];

double CalcDis(int i, int j)
{
	double dis;

	dis = (cities[i].x - cities[j].x) * (cities[i].x - cities[j].x)
	       + (cities[i].y - cities[j].y) * (cities[i].y - cities[j].y);

	dis = sqrt(dis);

	return dis;
}

double MST(int n)
{
	int i;
	int j;
	int k;
	int index;
	double min;
	double len = 0;

	for (i=0; i<111; ++i)
	{
		known[i] = 0;
		dis[i] = 99999999;
	}

	dis[1] = 0;

	for (i=1; i<n+1; ++i)
	{
		min = 99999999;

		for (j=1; j<n+1; ++j)
		{
			if ((known[j] == 0) && (min > dis[j]))
			{
				min = dis[j];
				index = j;
			}
		}

		known[index] = 1;

		for (j=1; j<n+1; ++j)
		{
			if ((known[j] == 0) && (CalcDis(j, index) < dis[j]))
			{
				dis[j] = CalcDis(j, index);
			}
		}

	}

	for (i=1; i<n+1; ++i)
	{
		len += dis[i];
	}

	return len;
}

int main(void)
{
	int n;
	int i;
	int order = 1;
	double len;

	scanf("%d", &n);

	while (n != 0)
	{
		for (i=1; i<n+1; ++i)
		{
			scanf("%lf %lf", &cities[i].x, &cities[i].y);
		}

		len = MST(n);

		printf("Case #%d:\nThe minimal distance is: %.2lf\n", order, len);

		++order;
		
		scanf("%d", &n);
		
		if (n != 0)
		{
			printf("\n");
		}
	}

	return 0;
}
