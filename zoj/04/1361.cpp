#include <set>
#include <queue>
#include <cmath>
#include <cstdio>
#include <memory>
#include <cstring>
using namespace std;

#define debug 1
const int MaxN = 21;
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {-1, 0, 1, 0};
int m;
int n;
int L;
int ss;
bool graph[MaxN][MaxN];
bool org[MaxN][MaxN];

struct node
{
	int state;
	int step;
	node(int a=0, int b=0) : state(a), step(b) {}
};

struct S
{
	int x[9];
	int y[9];
	int d[9];
	void operator=(const S&a)
	{
		for (int i=0; i<9; ++i)
		{
			x[i] = a.x[i];
			y[i] = a.y[i];
			d[i] = a.d[i];
		}
	}
}snake;

inline void input()
{
	int i;
	int x;
	int y;
	int cx;
	int cy;
	int difx;
	int dify;
	ss = 0;
	scanf("%d %d", &x, &y);
	ss = (x << 6) + y;
	for (i=1; i<L; ++i)
	{
		scanf("%d %d", &cx, &cy);
		difx = cx - x;
		dify = cy - y;
		ss <<= 2;
		switch (difx*10 + dify)
		{
			case  -1: ss += 0; break;
			case  10: ss += 1; break;
			case   1: ss += 2; break;
			case -10: ss += 3; break;
			default : throw "error !"; break;
		}
		x = cx;
		y = cy;
	}
	/*while (ss != 0)
	{
		printf("%d ", ss%4);
		ss >>= 2;
	}*/
	int bn;
	memset(org, false, sizeof(org));
	scanf("%d", &bn);
	for (i=0; i<bn; ++i)
	{
		scanf("%d %d", &x, &y);
		org[x][y] = true;
	}
	return;
}

int get_state(S &a)
{
	int i;
	int difx;
	int dify;
	int res((a.x[0]<<6)+a.y[0]);
	for (i=1; i<L; ++i)
	{
		res <<= 2;
		res += a.d[i];
	}
	return res;
}

void get_graph(int state)
{
	int i;
	memcpy(graph, org, sizeof(graph));
	for (i=L-1; i>0; --i)
	{
		snake.d[i] = state % 4;
		state >>= 2;
	}
	snake.y[0] = state % 64;
	snake.x[0] = state >> 6;
	for (i=1; i<L; ++i)
	{
		snake.x[i] = snake.x[i-1] + dx[snake.d[i]];
		snake.y[i] = snake.y[i-1] + dy[snake.d[i]];
		graph[snake.x[i]][snake.y[i]] = true;
	}
	return;
}

inline border(int x, int y)
{
	return x < m && x >= 0 && y < n && y >=0;
}

bool could_move(int dir)
{

}

void move(S &a, int tx, int ty, int dir)
{
	
}

int bfs()
{
	int i;
	int j;
	int k;
	int tx;
	int ty;
	int new_state;
	node tt;
	S temp;
	set<int>state;
	queue<node>q;
	q.push(node(ss, 0));
	state.insert(ss);
	
	while (!q.empty())
	{
		tt = q.front();
		q.pop();
		get_graph(tt.state);
		if (snake.x[0] == 1 && snake.y[0] == 1) return tt.step;
		for (k=0; k<4; ++k)
		{
			//tx = snake.x[0] + dx[k];
			//ty = snake.y[0] + dy[k];
			if (could_move(k))
			{
				temp = snake;
				move(temp, tx, ty, k);
				new_state = get_state(temp);
				if (state.find(new_state) == state.end())
				{
					q.push(node(new_state, tt.step+1));
					state.insert(new_state);
				}
			}
		}
	}
	return -1;
}

inline void output(int n)
{
	printf("Case %d: %d\n", n, bfs());
}

int main()
{
#if debug
	freopen("f:\\in.txt", "r", stdin);
#endif
	int cn(0);
	scanf("%d %d %d", &m, &n, &L);
	while (m != 0 || n != 0 || L != 0)
	{
		input();
		output(++cn);
		scanf("%d %d %d", &m, &n, &L);
	}
	
	return 0;
}
