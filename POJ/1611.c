#include<stdio.h>

int f[30001];

int find_root(int x)
{
	if (f[x] < 0)
	{
		return x;
	}
	else
	{
		return f[x] = find_root(f[x]);
	}
}

void Union(int x, int y)
{
	int rootx = find_root(x);
	int rooty = find_root(y);
	
	if (rootx == rooty)
	{
		return;
	}
	
	f[rootx] += f[rooty];
	f[rooty] = rootx;		
	
	return;
}

int main(void)
{
	int n;
	int m;
	int i;
	int j;
	int num;
	int root;
	int cur;
	int res;
	
	scanf("%d %d", &n, &m);
	
	while (n != 0 || m != 0)
	{
		for (i=0; i<n; ++i)
		{
			f[i] = -1;
		}
		
		for (i=0; i<m; ++i)
		{
			scanf("%d", &num);
			scanf("%d", &root);
			
			for (j=0; j<num-1; ++j)
			{
				scanf("%d", &cur);
				Union(root, cur);
			}						
		}
		
		res = -f[find_root(0)];
		
		printf("%d\n", res);
		
		scanf("%d %d", &n, &m);
	}
	
	return 0;
}