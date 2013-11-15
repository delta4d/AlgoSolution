#include<stdio.h>

#define Inf 32767

int graph[26][26];
int dis[26];
int visit[26];

int mst(int n)
{
	int i;
	int j;
	int k;
	int min;
	int len;
	int index;
	
	for (i=0; i<26; ++i)
	{
		dis[i] = Inf;
		visit[i] = 0;
	}
	
	dis[0] = 0;
	
	for (k=0; k<n; ++k)
	{
		min = Inf;
		
		for (i=0; i<n; ++i)
		{
			if ((visit[i] == 0) && (dis[i] < min))
			{
				index = i;
				min = dis[i];
			}
		}
		
		visit[index] = 1;
		
		for (i=0; i<n; ++i)
		{
			if ((visit[i] == 0) && (graph[index][i] < dis[i]))
			{
				dis[i] = graph[i][index];
			}
		}
	}
	
	len = 0;
	
	for (i=0; i<n; ++i)
	{
		len += dis[i];
	}
	
	return len;
}

int main(void)
{
	int i;
	int j;
	int k;
	int n;
	int d;
	int len;
	char temp[2];
	char village[2];
	
	scanf("%d", &n);

	while (n != 0)
	{		
		for (i=0; i<n; ++i)
		{
			for (j=0; j<n; ++j)
			{
				graph[i][j] = Inf;
			}
		}
		
		for (i=0; i<n-1; ++i)
		{
			scanf("%s", village);
			
			scanf("%d", &k);
			
			for (j=0; j<k; ++j)
			{
				scanf("%s %d", temp, &d);
				
				graph[village[0]-'A'][temp[0]-'A'] = graph[temp[0]-'A'][village[0]-'A'] = d;
			}
		}
		
		len = mst(n);
		
		printf("%d\n", len);
		
		scanf("%d", &n);
	}

	return 0;
}
