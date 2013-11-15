#include<stdio.h>
#include<memory.h>

long n;
long stick[20];
long visit[20];
long flag;
long edge;

void dfs(long curnum, long i, long curlen)
{
    long j;
    long k;

    if (flag == 1)
    {
        return;
    }

    if (curnum == 3)
    {
        flag = 1;
        return;
    }

    if (curlen == edge)
    {
		dfs(curnum+1, 0, 0);
	}
	else if (curlen < edge)
	{
		for (k=i+1; k<n; ++k)
		{
			if (visit[k] == 0)
			{			
				visit[k] = 1;
			
				dfs(curnum, k, curlen+stick[k]);
				
				visit[k] = 0;
			}
		}
	}
}

int main(void)
{
    long TestCase;
    long i;
    long k;
    long sum;

    scanf("%ld", &TestCase);

    for (k=0; k<TestCase; ++k)
    {
        sum = 0;

        scanf("%ld", &n);

        for (i=0; i<n; ++i)
        {
            scanf("%ld", stick+i);

            sum += stick[i];
        }

        if (sum % 4 != 0)
        {
            printf("no\n");
        }
        else
        {
        	flag = 1;
        	edge = sum / 4;
        	
        	for (i=0; i<n; ++i)
        	{
        		if (stick[i] > edge)
        		{
        			flag = 0;
        			break;
				}
			}
        	
        	if (flag == 1)
        	{     	
            	memset(visit, 0, sizeof(visit));
            	flag = 0;
            	visit[0] = 1;            

            	dfs(0, 0, stick[0]);

            	if (flag == 1)
            	{
             	   printf("yes\n");
            	}
            	else
            	{
                	printf("no\n");
            	}
        	}
        	else
        	{
        		printf("no\n");
			}
        }
    }

    return 0;
}
