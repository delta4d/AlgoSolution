#include <cstdio>
#include <memory>
using namespace std;

int d[26];
int f[26];
bool visit[26];
char buff[26];

int Find(int x)
{
	if (f[x] < 0) return x;
	return f[x] = Find(f[x]);
}

void Union(int x, int y)
{
	int rx = Find(x);
	int ry = Find(y);
	if (rx == ry) return;
	f[y] = rx;
	f[ry] = rx;
}

int main()
{
	int i;
	int j;
	int k;
	int n;
	int x;
	int y;
	int tc;
	int cnt;
	int len;
	int root;
	int e[26];
	bool set_root;
	bool youjie;
	
	//freopen("f:\\in.txt", "r", stdin);
	scanf("%d", &tc);
	for (k=0; k<tc; ++k)
	{
		memset(d, 0, sizeof(d));
		memset(f, -1, sizeof(f));
		memset(visit, false, sizeof(visit));
		scanf("%d", &n);
		for (i=0; i<n; ++i)
		{
			scanf("%s", buff);
			len = strlen(buff);
			x = buff[0]-'a';
			y = buff[len-1]-'a';
			--d[x];
			++d[y];
			visit[x] = visit[y] = true;
			Union(x, y);
		}
		set_root = false;
		youjie = true;
		for (i=0; i<26; ++i)
		{
			if (visit[i])
			{
				if (!set_root)
				{
					root = Find(i);
					set_root = true;
				}
				else
				{
					if (root != Find(i))
					{
						youjie = false;
						break;
					}
				}
			}
		}
		if (!youjie)
		{
			printf("The door cannot be opened.\n");
			continue;
		}
		cnt = 0;
		for (i=0; i<26; ++i)
		{
			if (d[i] != 0)
			{
				e[cnt] = d[i];
				++cnt;
			}
		}
		if (cnt > 2 || cnt == 1) printf("The door cannot be opened.\n");
		else if (cnt == 0) printf("Ordering is possible.\n");
		else
		{
			if (e[0] == 1 && e[1] == -1 || e[0] == -1 && e[1] == 1) printf("Ordering is possible.\n");
			else printf("The door cannot be opened.\n");
		}
	}
	
	return 0;
}
