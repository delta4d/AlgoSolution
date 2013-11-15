#include <cstdio>

int n;
int ans;
int a[100];
int r[100];
int d[202];

void init()
{
    int i;
    ans = n;
    a[0] = 1;
    
    for (i = n; i <= n + n; ++i)
	{
		d[i] = 0;
	}
	
    for (i = n - 1; i > 0; --i)
	{
		d[i] = d[i + i] + 1;
	}
}

void print()
{
    int i;
    
    for (i = 0; i < ans; i ++)
    {
        printf("%d ", r[i]);
    }
    
    printf("%d\n", n);
}

void dfs(int l)
{
    int i;
	int k;
	
    if (l + d[a[l]] >= ans)
    {
        return;
    }
    
    if (a[l] == n)
    {
        ans = l;
        
        for (i = 0; i < l; ++i)
        {
            r[i] = a[i];
        }
        
        return;
    }
    
    for (i = l; i >= 0; --i)
    {
        for (k = i; k >= 0; --k)
        {
            a[l + 1] = a[i] + a[k];
            
            if (a[l + 1] > a[l] && a[l + 1] <= n)
            {
                dfs(l + 1);
            }
        }
    }  
}

int main()
{
    while (scanf("%d", &n) && n)
    {
        init();
        dfs(0);
        print();
    }
    
    return 0;
}
