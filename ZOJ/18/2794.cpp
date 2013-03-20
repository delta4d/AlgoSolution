#include <queue>
#include <cstdio>
#include <memory>
#include <cstring>
using namespace std;

#define debug 0
#define EMPTY -1
#define OBSTACLE -2
#define VISITED -3
struct node
{
	int x;
	int y;
	int step;
	int cs;
	node(int a=0, int b=0, int c=0, int d=0) : x(a), y(b), step(c), cs(d) {}
};
const int MaxN = 21;
const int MaxS = 1 << 10;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};
int graph[MaxN][MaxN];
bool state[MaxN][MaxN][MaxS];
int num;
int m;
int n;
int sx;
int sy;
char buff[MaxN];

inline bool border(int x, int y)
{
	return x < m && x >= 0 && y < n && y >= 0;
}

void input()
{
	int i;
	int j;
	num = 0;
	for (i=0; i<m; ++i)
	{
		scanf("%s", buff);
		for (j=0; j<n; ++j)
		{
			if (buff[j] == 'o')
			{
				sx = i;
				sy = j;
				graph[i][j] = EMPTY;
			}
			else if (buff[j] == '.')
			{
				graph[i][j] = EMPTY;
			}
			else if (buff[j] == 'x')
			{
				graph[i][j] = OBSTACLE;
			}
			else if (buff[j] == '*')
			{
				graph[i][j] = num;
				++num;
			}
			else
			{
				throw "input error !";
			}
		}
	}
}

int bfs(int x, int y)
{
	int i;
	int j;
	int tx;
	int ty;
	const int cmp = (1 << num) - 1;
	node tt;
	queue<node>q;
	q.push(node(sx, sy, 0, 0));
	memset(state, false, sizeof(state));
	state[sx][sy][0] = true;
	while (!q.empty())
	{
		tt = q.front();
		q.pop();
		if (tt.cs == cmp) return tt.step;
		for (i=0; i<4; ++i)
		{
			tx = dx[i] + tt.x;
			ty = dy[i] + tt.y;
			if (!border(tx, ty)) continue;
			if (graph[tx][ty] == OBSTACLE) continue;
			if (graph[tx][ty] == EMPTY)
			{
				if (state[tx][ty][tt.cs]) continue;
				q.push(node(tx, ty, tt.step+1, tt.cs));
				state[tx][ty][tt.cs] = true;
				continue;
			}
			int new_state = tt.cs | (1 << graph[tx][ty]);
			if (state[tx][ty][new_state]) continue;
			q.push(node(tx, ty, tt.step+1, new_state));
			state[tx][ty][new_state] = true;
		}
	}
	return -1;
}

void solve()
{
	printf("%d\n", bfs(sx, sy));
}

int main()
{
#if debug
	freopen("f:\\in.txt", "r", stdin);
#endif
	scanf("%d %d", &n, &m);
	while (m != 0 || n != 0)
	{
		input();
		solve();
		scanf("%d %d", &n, &m);
	}
	
	return 0;
}
