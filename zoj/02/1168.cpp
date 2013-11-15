#include<stdio.h>

long w[21][21][21];

void gen(void)
{
	int i;
	int j;
	int a;
	int b;
	int c;
	
	for (i=0; i<21; ++i)
	{
		for (j=0; j<21; ++j)
		{
			w[0][i][j] = 1;
			w[i][0][j] = 1;
			w[i][j][0] = 1;
		}
	}
	
	for (a=1; a<21; ++a)
	{
		for (b=1; b<21; ++b)
		{
			for (c=1; c<21; ++c)
			{
				if ((a < b) && (b < c))
				{
					w[a][b][c] = w[a][b][c-1] + w[a][b-1][c-1] - w[a][b-1][c];
				}
				else
				{
					w[a][b][c] = w[a-1][b][c] + w[a-1][b-1][c] + w[a-1][b][c-1] - w[a-1][b-1][c-1];
				}
			}
		}
	}
	
	return;
}

int main(void)
{
	int a;
	int b;
	int c;
	
	gen();
	
	scanf("%d %d %d", &a, &b, &c);
	
	while (a != -1 || b != -1 || c != -1)
	{
		printf("w(%d, %d, %d) = ", a, b, c);
		
		if (a <= 0 || b <= 0 || c <= 0)
		{
			printf("1\n");
		}
		else if (a > 20 || b > 20 || c > 20)
		{
			printf("%ld\n", w[20][20][20]);
		}
		else
		{
			printf("%ld\n", w[a][b][c]);
		}
		
		scanf("%d %d %d", &a, &b, &c);
	}
	
	return 0;
}
