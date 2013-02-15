#include<iostream>
using namespace std;

char map[101][101];
char temp[101][101];
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};
int m;
int n;

bool border(int x, int y)
{
	if ((x >= 0) && (x <= m) && (y >= 0) && (y <= n))
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	int TestCase;
	int day;
	int t;
	int i;
	int j;
	int k;
	int u;
	
	cin >> TestCase;
	
	for (k=0; k<TestCase; ++k)
	{
		cin >> m >> n >> day;
		
		for (i=0; i<m; ++i)
		{
			cin >> map[i];
		}
		
		for (i=0; i<m; ++i)
		{
			for (j=0; j<n; ++j)
			{
				temp[i][j] = map[i][j];
			}
		}
		
		for (t=0; t<day; ++t)
		{
			for (i=0; i<m; ++i)
			{
				for (j=0; j<n; ++j)
				{
					if (map[i][j] == 'R')
					{
						for (u=0; u<4; ++u)
						{
							if (border(i+dx[u], j+dy[u]) && (map[i+dx[u]][j+dy[u]] == 'S'))
							{
								temp[i+dx[u]][j+dy[u]] = 'R';
							}
						}
					}
					else if (map[i][j] == 'S')
					{
						for (u=0; u<4; ++u)
						{
							if (border(i+dx[u], j+dy[u]) && (map[i+dx[u]][j+dy[u]] == 'P'))
							{
								temp[i+dx[u]][j+dy[u]] = 'S';
							}
						}
					}
					else
					{
						for (u=0; u<4; ++u)
						{
							if (border(i+dx[u], j+dy[u]) && (map[i+dx[u]][j+dy[u]] == 'R'))
							{
								temp[i+dx[u]][j+dy[u]] = 'P';
							}
						}
					}
				}
			}
			
			for (i=0; i<m; ++i)
			{
				for (j=0; j<n; ++j)
				{
				map[i][j] = temp[i][j];
				}
			}
		}
		
		for (i=0; i<m; ++i)
		{
			for (j=0; j<n; ++j)
			{
				cout << map[i][j];
			}
			
			cout << endl;
		}		
		
		if (k < TestCase - 1)
		{
			cout << endl;
		}
	}
	
	return 0;
}
