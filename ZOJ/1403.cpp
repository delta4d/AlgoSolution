#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>

using namespace std;

long target;

int cmp(const void *a, const void *b)
{
	return *(char *)b - *(char *)a;
}

bool form_target(long v, long w, long x, long y, long z)
{
	return v - (long)pow((double)w, 2.0) + (long)pow((double)x, 3.0) - (long)pow((double)y, 4.0) + (long)pow((double)z, 5.0) == target; 
}

int main(void)
{
	char message[13];
	int len;
	int i;
	int j;
	int k;
	int l;
	int m;
	bool flag;
	
	scanf("%ld %s", &target, message);
	
	while (target != 0 || strcmp(message, "END") != 0)
	{
		len = strlen(message);
		flag = false;
		qsort(message, len, sizeof(message[0]), cmp);
		
		for (i=0; i<len; ++i)
		{
			for (j=0; j<len; ++j)
			{
				if (j == i)
				{
					continue;
				}
				
				for (k=0; k<len; ++k)
				{
					if (k == i || k == j)
					{
						continue;
					}
					
					for (l=0; l<len; ++l)
					{
						if (l == i || l == j || l == k)
						{
							continue;
						}
						
						for (m=0; m<len; ++m)
						{
							if (m == i || m == j || m == k || m == l)
							{
								continue;
							}
							
							flag = form_target(message[i] - 'A' + 1, message[j] - 'A' + 1, message[k] - 'A' + 1, message[l] - 'A' + 1, message[m] - 'A' + 1);
							
							if (flag)
							{
								break;
							}
						}
						
						if (flag)
						{
							break;
						}
					}
					
					if (flag)
					{
						break;
					}
				}
				
				if (flag)
				{
					break;
				}
			}
			
			if (flag)
			{
				break;
			}
		}
		
		if (!flag)
		{
			printf("no solution\n");
		}
		else
		{
			printf("%c%c%c%c%c\n", message[i], message[j], message[k], message[l], message[m]);
		}
		
		scanf("%ld %s", &target, message);
	}
	
	return 0;
}
