#include <cstdio>
#include <memory>
#include <queue>

using namespace std;

const int MaxN = 51;
struct NODE
{
	int p1;
	int p2;
	int p3;
	int step;
}curr;

char graph[MaxN][MaxN];
bool state[MaxN][MaxN][MaxN];
bool find;
int n;
int res;

void bfs()
{
	int i;
	int j;
	int k;
	queue<NODE>f;
	f.push(curr);
	
	find = false;
	memset(state, false, sizeof(state));
	state[curr.p1][curr.p2][curr.p3] = true;
	
	while (!f.empty())
	{
		curr = f.front();
		f.pop();
		
		if (curr.p1 == curr.p2 && curr.p2 == curr.p3)
		{
			find = true;
			res = curr.step;
			return;
		}
		
		for (i=1; i<=n; ++i)
		{
			if (i != curr.p1 && !state[i][curr.p2][curr.p3] 
			&& graph[curr.p1][i] == graph[curr.p2][curr.p3])
			{
				state[i][curr.p2][curr.p3] = true;
				NODE temp(curr);
				temp.p1 = i;
				++temp.step;
				f.push(temp);
			}
		}
		
		for (i=1; i<=n; ++i)
		{
			if (i != curr.p2 && !state[curr.p1][i][curr.p3] 
			&& graph[curr.p2][i] == graph[curr.p1][curr.p3])
			{
				state[curr.p1][i][curr.p3] = true;
				NODE temp(curr);
				temp.p2 = i;
				++temp.step;
				f.push(temp);
			}
		}
		
		for (i=1; i<=n; ++i)
		{
			if (i != curr.p3 && !state[curr.p1][curr.p2][i] 
			&& graph[curr.p3][i] == graph[curr.p1][curr.p2])
			{
				state[curr.p1][curr.p2][i] = true;
				NODE temp(curr);
				temp.p3 = i;
				++temp.step;
				f.push(temp);
			}
		}
	}
	
	return;
}

int main(void)
{
	int i;
	int j;
	int k;
	char buff[10];
	
	scanf("%d", &n);
	
	while (n != 0)
	{
		scanf("%d %d %d", &curr.p1, &curr.p2, &curr.p3);
		curr.step = 0;

		for (i=1; i<=n; ++i)
		{
			for (j=1; j<=n; ++j)
			{
				scanf("%s", buff);
				graph[i][j] = buff[0];
			}
		}
		
		bfs();
		
		if (find)
		{
			printf("%d\n", res);
		}
		else
		{
			printf("impossible\n");
		}
		
		scanf("%d", &n);
	}
	
	return 0;
}
