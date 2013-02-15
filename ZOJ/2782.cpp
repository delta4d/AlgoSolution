#include<stdio.h>

char str[30][10];
char res[30][10];
char temp[10];
int m, n;
int strmark[30];
int resmark[30];

void Q(int s, int r)
{
	int i;
	
	resmark[r] = 1;
	strmark[s] = 1;
	
	strcpy(res[r], str[s]);
}

int main()
{
	int i;
	int r;
	int j;
	int k;
	int start;
	int request;
	
	scanf("%d", &r);
	
	for (i=0; i<r; i++)
	{
		scanf("%d %d", &m, &n);
		
		k =1;
		for (j=0; j<30; j++)
		{
			strmark[j] = resmark[j] = 0;
		}
		
		for (j=1; j<=m; j++)
		{
			scanf("%s", str[j]);
		}
		
		for (j=0; j<n; j++)
		{
			scanf("%d %d", &start, &request);
			
			Q(start, request);
		}
		
		for (j=1; j<=m; j++)
		{
			if (strmark[j] == 0)
			{
				while (resmark[k] == 1)
				{
					k++;
				}
				
				resmark[k] = 1;
				strcpy(res[k], str[j]);
			}
		}
		
		for (j=1; j<m; j++)
		{
			printf("%s ", res[j]);
		}
		printf("%s\n", res[m]);
	}
}