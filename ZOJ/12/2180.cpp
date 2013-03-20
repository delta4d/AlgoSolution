#include<stdio.h>
#include<memory.h>

#define MaxN 1001
char s[2*MaxN];
int h[MaxN];
int left[MaxN];
int right[MaxN];
int m;
int n;
int max;

void gen_left(void)
{
	int i;
    left[0] = s[0] == 'F' ? 1 : 0;
    for (i=1; i<n; ++i)
    {
        if (s[i*2] == 'F')
        {
            left[i] = left[i-1] + 1;
        }
        else
        {
            left[i] = 0;
        }
    }
    
    return;
}

void gen_right(void)
{
	int i;
	right[n-1] = s[2*n-2] == 'F' ? 1 : 0;
    for (i=n-1; i>=0; --i)
    {
        if (s[i*2] == 'F')
        {
            right[i] = right[i+1] + 1;
        }
        else
        {
            right[i] = 0;
        }
    }
    
    return;
}

void gen_h(void)
{
	int i;
	for (i=0; i<n; ++i)
    {
        h[i] = s[i*2] == 'F' ? h[i] + 1 : 0;
    }
    
    return;
}

void update_area(void)
{
	int i;
	int j;
	int k;
	
	for (k=0; k<n; ++k)
	{
		for (i=k; i>k-left[k]; --i)
		{
			if (h[i] < h[k])
			{
				break;
			}
		}
		
		for (j=k; j<k+right[k]; ++j)
		{
			if (h[j] < h[k])
			{
				break;
			}
		}
		
		if ((j - i - 1) * h[k] > max)
		{
			max = (j - i - 1) * h[k];
		}
	}
	
	return;
}

int main(void)
{
    int i;
    int j;
    int k;
    int test_case;

    scanf("%d", &test_case);

    for (k=0; k<test_case; ++k)
    {
    	scanf("%d %d", &m, &n);
    	max = 0;
        memset(h, 0, sizeof(h));
        getchar();

        for (j=0; j<m; ++j)
        {
            gets(s);
			gen_left();
			gen_right();
			gen_h();
			update_area();
        }
        
        printf("%d\n", max * 3);
    }

    return 0;
}
