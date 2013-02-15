#include<cstdio>
#include<cstring>
#include<vector>
#include<memory>

using namespace std;

const int MaxL = 300;
const int MaxN = 101;
vector<int>v[MaxN];
char s[MaxL];
char buff[10];
int color[MaxN];
int dep[MaxN];
int anc[MaxN];
int root;
bool cut[MaxN];

void dfs(int k, int f, int d)
{
	int tot(0);
	vector<int> :: iterator it;
	anc[k] = d;
	dep[k] = d;
	color[k] = 1;
	
	for (it=v[k].begin(); it!=v[k].end(); ++it)
	{
		int t = *it;
		
		if (t != f && color[t] == 1)
		{
			anc[k] = anc[k] < dep[t] ? anc[k] : dep[t];
		}
		
		if (color[t] == 0)
        {
            dfs(t, k, d + 1);
            ++tot;
            
            anc[k] = anc[k] < anc[t] ? anc[k] : anc[t];
            if ((k == root && tot > 1) || (k != root && anc[t] >= dep[k]))
            {
                cut[k] = true;
            }
        }
	}
	
	color[k] = 2;
}

int to_num(int len)
{
	int i;
	int res(0);
	
	for (i=0; i<len; ++i)
	{
		res = res * 10 + buff[i] - '0';
	}
	
	return res;
}

int main(void)
{
	int i;
	int k;
	int n;
	int x;
	int y;
	int len;
	int res;
	
	scanf("%d", &n);
	
	while (n != 0)
	{
		scanf("%d", &x);
		for (i=0; i<=n; ++i)
		{
			v[i].clear();
		}
		
		while (x != 0)
		{
			gets(s);
			i = 0;
			while (s[i] == ' ')
			{
				++i;
			}
			len = strlen(s);
			k = 0;
			
			for (; i<=len; ++i)
			{
				if (s[i] == ' ' || s[i] == '\0')
				{
					y = to_num(k);
					v[x].push_back(y);
					v[y].push_back(x);
					k = 0;
				}
				else
				{
					buff[k] = s[i];
					++k;
				}
			}
			
			scanf("%d", &x);
		}
		
		//vector<int> :: iterator it;
		//for (it=v[5].begin(); it!=v[5].end(); ++it)printf("%d ", *it);
		root = 1;
		memset(cut, false, sizeof(cut));
		memset(color, 0, sizeof(color));		
		dfs(root, root, 0);		
		res = 0;
		for (i=1; i<=n; ++i)
		{
			if (cut[i])
			{
				++res;
			}
		}
		
		printf("%d\n", res);
		
		scanf("%d", &n);
	}
	
	return 0;
}
