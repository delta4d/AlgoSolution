#include<cstdio>
#include<vector>
#include<memory>

using namespace std;

const int MaxN = 1501;
int n;
int f[MaxN][2];
bool visit[MaxN];
vector<int>connect[MaxN];

int min(int &a, int &b)
{
	return a < b ? a : b;
}

void dfs(int root)
{
	int i;
	int take_root = 0;
	int untake_root = 0;
	bool leaf = true;
	vector<int> :: iterator it;
	
	for (it=connect[root].begin(); it!=connect[root].end(); ++it)
	{
		leaf = false;
		dfs(*it);
		take_root += min(f[*it][0], f[*it][1]);
		untake_root += f[*it][1];
	}
	
	if (leaf)
	{
		f[root][0] = 0;
		f[root][1] = 1;
	}
	else
	{
		f[root][0] = untake_root;
		f[root][1] = take_root + 1;
	}
}

int main(void)
{
	int i;
	int j;
	int x;
	int y;
	int m;
	int root;
	int res;
	
	while (scanf("%d", &n) != EOF)
	{
		//initial
		for (i=0; i<n; ++i)
		{
			connect[i].clear();
		}
		
		//build tree
		memset(visit, false, sizeof(visit));
		for (i=0; i<n; ++i)
		{
			scanf("%d", &x);
			getchar();
			getchar();
			scanf("%d", &m);
			getchar();
			
			for (j=0; j<m; ++j)
			{
				scanf("%d", &y);
				connect[x].push_back(y);
				visit[y] = true;
			}
		}
		
		memset(f, 0 ,sizeof(f));
		
		//find root		
		for (i=0; i<n; ++i)
		{
			if (!visit[i])
			{
				root = i;
				break;
			}
		}
		
		dfs(root);
		
		res = min(f[root][0], f[root][1]);
		
		printf("%d\n", res);
	}
	
	return 0;
}
