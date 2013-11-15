#include<cstdio>
#include<queue>
#include<memory>

using namespace std;

struct F
{
	long n;
	long step;
	
	F(long n, long step) : n(n), step(step){}
};

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int tg[4][4];
int ttg[4][4];
long len;
bool find;
bool mark[65536];

bool border(int x, int y)
{
	return (x >= 0) && (x < 4) && (y >= 0) && (y < 4);
}

void ntoa(long n)
{
	int i;
	int j;
	
	for (i=3; i>=0; --i)
	{
		for (j=3; j>=0; --j)
		{
			tg[i][j] = n % 2;
			n /= 2;
		}
	}
	
	return;
}

long aton()
{
	long res = 0;
	int i;
	int j;
	
	for (i=0; i<4; ++i)
	{
		for (j=0; j<4; ++j)
		{
			res = res * 2 + ttg[i][j];
		}
	}
	
	return res;
}

void bfs()
{
	int i;
	int j;
	int k;
	int tx;
	int ty;
	long n;
	queue<F>Q;
	
	memset(mark, false, sizeof(mark));
	n = aton();
	mark[n] = true;
	
	Q.push(F(n, 0));
	
	while (!Q.empty())
	{
		F temp = Q.front();
		Q.pop();
		
		if (temp.n == 0 || temp.n == 65535)
		{
			find = true;
			len = temp.step;
			break;
		}
		
		ntoa(temp.n);
		
		for (i=0; i<4; ++i)
		{
			for (j=0; j<4; ++j)
			{
				memcpy(ttg, tg, sizeof(tg));
				
				ttg[i][j] ^= 1;
				
				for (k=0; k<4; ++k)
				{
					tx = i + dx[k];
					ty = j + dy[k];
					
					if (border(tx, ty))
					{
						ttg[tx][ty] ^= 1;
					}
				}
				
				n = aton();
				
				if (!mark[n])
				{
					mark[n] = true;
					Q.push(F(n, temp.step + 1));
				}				
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
	int test_case;
	char temp[5];
	
	scanf("%d", &test_case);
	
	for (k=1; k<=test_case; ++k)
	{
		memset(ttg, 0, sizeof(ttg));
		
		for (i=0; i<4; ++i)
		{
			scanf("%s", temp);
			
			for (j=0; j<4; ++j)
			{
				if (temp[j] == 'w')
				{
					ttg[i][j] = 1;
				}
			}
		}
		
		find = false;
		
		bfs();
		
		if (find)
		{
			printf("%d\n", len);
		}
		else
		{
			printf("Impossible\n");
		}
		
		if (k < test_case)
		{
			printf("\n");
		}
	}
	
	return 0;
}
