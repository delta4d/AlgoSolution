#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#include<math.h>

#define Inf 99999999

long visit[500];
double dis[500];
double x[500];
double y[500];

int cmp(const void *a, const void *b)
{
	double *c = (double *)a;
	double *d = (double *)b;
	
	if (*c < *d)
	{
		return -1;
	}
	else
	{
		return 1;
	}
}

double calc_dis(double x1, double y1, double x2, double y2)
{
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

void mst(int n)
{
	long i;
	long j;
	long k;
	long index;
	double min;
	
	for (i=1; i<n; ++i)
	{
		dis[i] = Inf;
	}
	
	memset(visit, 0, sizeof(visit));
	
	dis[0] = 0;
	
	for (k=0; k<n; ++k)
	{
		min = Inf;
		
		for (i=0; i<n; ++i)
		{
			if ((visit[i] == 0) && (min > dis[i]))
			{
				index = i;
				min = dis[i];
			}
		}
		
		visit[index] = 1;
		
		for (i=0; i<n; ++i)
		{
			if ((visit[i] == 0) && (calc_dis(x[index], y[index], x[i], y[i]) < dis[i]))
			{
				dis[i] = calc_dis(x[index], y[index], x[i], y[i]);
			}
		}
	}
	
	qsort(dis, n, sizeof(dis[0]), cmp);
	
	return;
}

int main(void)
{
	int s;
	int p;
	int i;
	int j;
	int k;
	int TestCase;
	
	scanf("%d", &TestCase);
	
	for (k=0; k<TestCase; ++k)
	{
		scanf("%d %d", &s, &p);
		
		for (i=0; i<p; ++i)
		{
			scanf("%lf %lf", x+i, y+i);
		}
		
		mst(p);
		
		printf("%.2lf\n", dis[p-s]);
	}
	
	return 0;
}
