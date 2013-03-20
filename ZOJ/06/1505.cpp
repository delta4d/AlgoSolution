#include <set>
#include <queue>
#include <cstdio>
#include <memory>
#include <cstring>
using namespace std;

#define debug 0
const int MaxN = 9;
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};
struct node
{
    int state;
    int step;
    node(int a=0, int b=0) : state(a), step(b) {}
};
bool graph[MaxN][MaxN];
int start;
int dest;
int x[4];
int y[4];
set<int>state;

inline int get_state()
{
    int res(0);
    for (int i=1; i<MaxN; ++i)
        for (int j=1; j<MaxN; ++j)
            if (graph[i][j]) res = res * 100 + 10 * i + j;
    return res;
}

inline void get_graph(int n)
{
    int tx;
    int ty;
    memset(graph, false, sizeof(graph));
    for (int i=0; i<4; ++i)
    {
        ty = n % 10;
        n /= 10;
        tx = n % 10;
        n /= 10;
        graph[tx][ty] = true;
        x[i] = tx;
        y[i] = ty;
    }
}

inline bool border(int x, int y)
{
    return x >= 0 && x < MaxN && y >= 0 && y < MaxN;
}

bool bfs()
{
    int i;
    int j;
    int k;
    int nx;
    int ny;
    int tx;
    int ty;
    int new_state;
    node ss;
    queue<node>q;
    q.push(node(start, 0));
    state.clear();
    state.insert(start);

    while (!q.empty())
    {
        ss = q.front();
        q.pop();
        //if (ss.step == 8) return false;
        if (ss.state == dest) return true;
        get_graph(ss.state);
        for (int t=0; t<4; ++t)
        {
            i = x[t];
            j = y[t];

            for (k=0; k<4; ++k)
            {
                tx = i + dx[k];
                ty = j + dy[k];
                if (border(tx, ty) && !graph[tx][ty])
                {
                    graph[i][j] = false;
                    graph[tx][ty] = true;
                    new_state = get_state();
                    if (state.find(new_state) == state.end())
                    {
                        if (new_state == dest) return true;
                        state.insert(new_state);
                        if (ss.step+1<8)
                            q.push(node(new_state, ss.step+1));
                    }
                    graph[i][j] = true;
                    graph[tx][ty] = false;
                }
                if (border(tx+dx[k], ty+dy[k]) && graph[tx][ty] && !graph[tx+dx[k]][ty+dy[k]])
                {
                    tx += dx[k];
                    ty += dy[k];
                    graph[i][j] = false;
                    graph[tx][ty] = true;
                    new_state = get_state();
                    if (state.find(new_state) == state.end())
                    {
                        if (new_state == dest) return true;
                        state.insert(new_state);
                        if (ss.step+1<8)
                            q.push(node(new_state, ss.step+1));
                    }
                    graph[i][j] = true;
                    graph[tx][ty] = false;
                }
            }
        }


    }
    return false;
}

bool input()
{
    int i;
    int x;
    int y;
    memset(graph, false, sizeof(graph));
    for (i=0; i<4; ++i)
        if (scanf("%d %d", &x, &y) == EOF) return false;
        else graph[x][y] = true;
    start = get_state(); //printf("start: %d ", start);
    memset(graph, false, sizeof(graph));
    for (i=0; i<4; ++i)
        if (scanf("%d %d", &x, &y) == EOF) return false;
        else graph[x][y] = true;
    dest = get_state(); //printf("dest: %d\n", dest);
    printf("%s\n", bfs()?"YES":"NO");
    return true;
}

int main()
{
#if debug
    freopen("f:\\in.txt", "r", stdin);
    //freopen("f:\\out.txt", "w", stdout);
#endif
    while (input());

    return 0;
}
