#include<stdio.h>

int f[2][1000];

int main(void)
{
	char s1[1000];
	char s2[1000];
	int i;
	int j;
	int k;
	int len1;
	int len2;
	int res;

	while (scanf("%s %s", s1, s2) != EOF)
	{
		len1 = strlen(s1);
		len2 = strlen(s2);

		for (i=0; i<=len2; ++i)
		{
			f[0][i] = 0;
		}

		f[1][0] = 0;

		for (i=0; i<len1; ++i)
		{
			for (j=0; j<len2; ++j)
			{
				if (s2[j] == s1[i])
				{
					f[1][j+1] = f[0][j] + 1;
				}
				else
				{
					f[1][j+1] = f[1][j] > f[0][j+1] ? f[1][j] : f[0][j+1];
				}
			}

			for (k=1; k<=len2; ++k)
			{
				f[0][k] = f[1][k];
			}
		}

		printf("%d\n", f[0][len2]);
	}

	return 0;
}
