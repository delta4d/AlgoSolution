#include<iostream>

using namespace std;

const int MaxN = 5; 
char graph[MaxN][MaxN];
int n;
int max;

bool CouldPut(int x, int y)
{
	int i;
	
	if (graph[x][y] != '.')
	{
		return false;
	}
	
	for (i=y-1; i>=0; --i)
	{
		if (graph[x][i] == 'X')
		{
			break;
		}
		
		if (graph[x][i] == 'A')
		{
			return false;
		}
	}
	
	for (i=y+1; i<n; ++i)
	{
		if (graph[x][i] == 'X')
		{
			break;
		}
		
		if (graph[x][i] == 'A')
		{
			return false;
		}
	}
	
	for (i=x-1; i>=0; --i)
	{
		if (graph[i][y] == 'X')
		{
			break;
		}
		
		if (graph[i][y] == 'A')
		{
			return false;
		}
	}
	
	for (i=x+1; i<n; ++i)
	{
		if (graph[i][y] == 'X')
		{
			break;
		}
		
		if (graph[i][y] == 'A')
		{
			return false;
		}
	}
	
	return true;
}

void dfs(int pos, int cnt)
{
	int x;
	int y;
	
	if (pos == n * n)
	{
		if (cnt > max)
		{
			max = cnt;
		}
		
		return;
	}
	
	x = pos / n;
	y = pos % n;
	
	if (CouldPut(x, y))
	{
		graph[x][y] = 'A';
		
		dfs(pos + 1, cnt + 1);
		
		graph[x][y] = '.';
	}
	
	dfs(pos + 1, cnt);
}

int main(void)
{
	int i;
	
	cin >> n;
	
	while (n != 0)
	{
		for (i=0; i<n; ++i)
		{
			cin >> graph[i];
		}
		
		max = 0;
		
		dfs(0, 0);
		
		cout << max << endl;
		
		cin >> n;
	}
	
	return 0;
}
