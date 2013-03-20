#include <map>
#include <set>
#include <list>
#include <cstdio>
using namespace std;

const char res[2][32] = {"can be travelled", "cannot be travelled"};
map<int, list<int> > graph;
set<int> visit;

bool input(int &x, int &y, const int &n)
{
	int i;
	int t;
	x = 0;
	y = 0;
	scanf("%d", &t);
	if (t == -1) return false;
	x = t;
	for (i=1; i<n; ++i)
	{
		scanf("%d", &t);
		x = x * 10 + t;
	}
	for (i=0; i<n; ++i)
	{
		scanf("%d", &t);
		y = y * 10 + t;
	}
	return true;
}

bool dfs(int x, const int &dest)
{
	list<int>::iterator it;
	for (it=graph[x].begin(); it!=graph[x].end(); ++it)
	{
		if (*it == dest) return true;
		if (visit.find(*it) == visit.end())
		{
			visit.insert(*it);
			if (dfs(*it, dest)) return true;
		}
	}
	return false;
}

int main()
{
	int i;
	int j;
	int x;
	int y;
	int n;
	int ss;
	int tt;
	int cn(0);
	//freopen("f:\\in.txt", "r", stdin);
	scanf("%d", &n);
	while (n != 0)
	{
		graph.clear();
		visit.clear();
		input(ss, tt, n);
		while (input(x, y, n))
		{
			graph[x].push_back(y);
			graph[y].push_back(x);
		}
		printf("Maze #%d %s\n", ++cn, res[dfs(ss, tt)?0:1]);
		scanf("%d", &n);
	}
	
	return 0;
}
