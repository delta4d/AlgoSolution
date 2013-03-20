#include<cstdio>
#include<cstdlib>
using namespace std;
#define MaxN 5000

struct interval
{
	int start;
	int end;
}f[MaxN];

int cmp(const void *a, const void *b)
{
	struct interval *c = (struct interval *)a;
	struct interval *d = (struct interval *)b;
	
	return c -> start - d -> start;
}

int main(void)
{
	int curs;
	int end;
	int i;
	int j;
	int k;
	int n;
	int test_case;
	int max;
	int p;
	
	scanf("%d", &test_case);
	
	for (k=0; k<test_case; ++k)
	{
		scanf("%d", &end);
		
		for (i=0; i<end; ++i)
		{
			scanf("%d %d", &f[i].start, &f[i].end);
		}
		
		qsort(f, end, sizeof(f[0]), cmp);
		
		n = 0;
		p = 0;
		curs = 1;
		
		while (1)
		{
			if (curs > end)
			{
				break;
			}
			
			max = -1;
			
			for (i=p; i<end; ++i)
			{
				if (f[i].start <= curs)
				{
					if ((f[i].end >= curs) && (f[i].end> max))
					{
						max = f[i].end;
					}
				}
				else
				{
					break;
				}
			}
			
			curs = max + 1;
			p = i;
			++n;
		}
		
		printf("%d\n", n);
	}
	
	return 0;
}
