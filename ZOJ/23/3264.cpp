#include<stdio.h>

long w1[11111];
long w2[11111];
long v1[11111];
long v2[11111];
long r[11111];
long f[2][51111];

int main(void)
{
	long w;
	long n;
	long i;
	long j;
	long temp;
	long temp1;
	long temp2;
	
	while (scanf("%ld %ld", &w, &n) != EOF)
	{
		w /= 100;
		
		for (i=1; i<n+1; ++i)
		{
			scanf("%ld %ld %ld %ld %ld", w1 + i, v1 + i, w2 + i, v2 + i, r + i);
			
			w1[i] /= 100;
			w2[i] /= 100;
		}
		
		for (i=0; i<11111; ++i)
		{
			f[0][i] = f[1][i] = 0;
		}
		
		for (i=1; i<n+1; ++i)
		{
			for (j=0; j<w+1; ++j)
			{
				if (r[i] == 1)
				{
					if (j >= w1[i] + w2[i])
					{
						temp = f[0][j-w1[i]-w2[i]] + v1[i] + v2[i];
						
						f[1][j] = f[0][j] > temp ? f[0][j] : temp;
					}
					else
					{
						f[1][j] = f[0][j];
					}
				}
				else if (r[i] == 2)
				{
					if ((j >= w1[i]) && (j >= w2[i]))
					{
						temp1 = f[0][j-w1[i]] + v1[i];
						temp2 = f[0][j-w2[i]] + v2[i];
						
						temp = temp1 > temp2 ? temp1 : temp2;
						
						f[1][j] = f[0][j] > temp ? f[0][j] : temp;
					}
					else if (j >= w1[i])
					{
						temp = f[0][j-w1[i]] + v1[i];
						
						f[1][j] = f[0][j] > temp ? f[0][j] : temp;
					}
					else if (j >= w2[i])
					{
						temp = f[0][j-w2[i]] + v2[i];
						
						f[1][j] = f[0][j] > temp ? f[0][j] : temp;
					}
					else
					{
						f[1][j] = f[0][j];
					}
				}
				else
				{
					if (j >= w1[i] + w2[i])
					{
						temp1 = f[0][j-w1[i]] + v1[i];
						temp2 = f[0][j-w1[i]-w2[i]] + v1[i] + v2[i];
						
						temp = temp1 > temp2 ? temp1 : temp2;
						
						f[1][j] = f[0][j] > temp ? f[0][j] : temp;
					}
					else if (j >= w1[i])
					{
						temp = f[0][j-w1[i]] + v1[i];
						
						f[1][j] = f[0][j] > temp ? f[0][j] : temp;
					}
					else
					{
						f[1][j] = f[0][j];
					}
				}
			}
			
			for (j=0; j<w+1; ++j)
			{
				f[0][j] = f[1][j];
			}
		}
		
		printf("%ld\n", f[0][w]);
	}
	
	return 0;
}

