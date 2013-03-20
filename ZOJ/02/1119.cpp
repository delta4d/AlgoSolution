#include<cstdio>
#include<vector>
#include<memory>
using namespace std;

const int MaxN = 500;
const int root = 1;

vector<int>v[MaxN];
int a[MaxN];
int D[MaxN];
int cut[MaxN];
int c[MaxN];

void dfs(int k, int f, int d)
{
	int i;
	int t;
	int tot(0);
	vector<int> :: iterator it;
	a[k] = d;
	D[k] = d;
	c[k] = 1;
	
	for (it=v[k].begin(); it!=v[k].end(); ++it)
	{
		t = *it;
		
		if (c[t] == 1)
		{
			a[k] = a[k] < D[t] ? a[k] : D[t];
		}
		
		if (c[t] == 0)
		{
			dfs(t, k, d + 1);
			++tot;
			
			a[k] = a[k] < a[t] ? a[k] : a[t];
			
			if ((k == root && tot > 1) || (k != root && a[t] >= D[k]))
			{
				++cut[k];
			}
		}
	}
	
	c[k] = 2;
}

int main(void)
{
	int x;
	int y;
	int i;
	int n;
	int case_num(1);
	bool find;
	
	scanf("%d", &x);
	
	while (1)
	{
		for (i=0; i<MaxN; ++i)
		{
			v[i].clear();
		}
		n = 0;
		
		while (x != 0)
		{
			scanf("%d", &y);
			
			v[x].push_back(y);
			v[y].push_back(x);
			++n;
			
			scanf("%d", &x);
		}
		
		memset(cut, 0, sizeof(cut));
		memset(c, 0, sizeof(c));
		dfs(root, root, 0);
		
		find = false;
		for (i=1; i<=n; ++i)
		{
			if (cut[i] != 0)
			{
				find = true;
				break;
			}
		}
		
		printf("Network #%d\n", case_num);
		++case_num;
		
		if (find)
		{
			for (; i<=n; ++i)
			{
				if (cut[i] != 0)
				{
					printf("  SPF node %d leaves %d subnets\n", i, cut[i]+1);
				}
			}
		}
		else
		{
			printf("  No SPF nodes\n");
		}
		
		scanf("%d", &x);
		
		if (x == 0)
		{
			break;
		}
		
		printf("\n");
	}
	
	return 0;
}
