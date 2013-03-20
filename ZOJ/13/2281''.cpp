/*无向图中给定单源，求到某点路径中最小权边的最大值。

可以将其看成求单源最短路径的变种，使用dijkstra算法+最大堆。

单源最短路径的算法是：记录从源点出发访问每一点i的最短路为value[i]，

对于当前所有value中的最小值点u，进行BFS式的操作，对于每条 Edge(u,v)，

如果edge(u,v)+value[u] < value[v] 则更新v。

对此稍做修改。记录每条边目前能承受的最大重量为value[i]（即从源点所遍历路径的最小权中的最大值）。

设u是当前结点，对于每条Edge(u,v)，当路径扩展到v时的最小 value（min(edge, value[u])）大于value[v] 时更新。

由于边数目巨大(M<1000000)，因此使用链表储存。使用num数组保存起点为i的起始位置，next数组保存链表。 

num[i]=a,next[a]=b,next[b]=c,next[c]=d,next[d]=0，这里abcd都为边数组中的位置，表示以i为起点的边在abcd处。

WA了一下午，才发现把INF定义的太小了。

*/

#include <cstdio>
#include <string>

#define min(x, y) ( x < y ? x : y )
#define INF 2000000001

        int N, M, src, dst, size;
const int MAXM = 1000010;
const int MAXN = 100001;

typedef struct
{
    int y, w;
} Edge;
Edge e[MAXM * 2];
int next[MAXM * 2], value[MAXN], visited[MAXN], num[MAXN], heap[MAXN], idx[MAXN];
//heap存放点序号，idx存放点在heap中的位置

int init ();
int dijk ();
int get_top ();
void update ( int );
void print_heap ();
void print_value ();
void print_link ();

int main ()
{
    //freopen ( "in.txt", "r", stdin );
    while ( init () )
    {
        printf ( "%d\n", dijk () );
    }
    return 0;
}

int init ()
{
    if ( scanf ( "%d%d", &N, &M ) != 2 )
    {
        return 0;
    }
    int i, j;
    memset ( num, 0x00, sizeof ( num ) );
    for ( i = 1, j = 0; i <= M; i ++ )
    {
        int tx, ty, tw;
        scanf ( "%d%d%d", &tx, &ty, &tw );
        e[++ j].w = tw, e[j].y = ty, next[j] = num[tx], num[tx] = j;
        e[++ j].w = tw, e[j].y = tx, next[j] = num[ty], num[ty] = j;
    }
    scanf ( "%d%d", &src, &dst );
    memset ( value, 0, sizeof ( value ) );
    memset ( visited, 0, sizeof ( visited ) );
    memset ( idx, 0, sizeof ( idx ) );
    return 1;
}

int dijk ()
{
    size = 0;
    value[src] = INF, visited[src] = 1;
    heap[++ size] = src, idx[src] = 1;
    while ( true )
    {
        if ( visited[dst] || size == 0 )
        {
            break;
        }
        int j, u, v;
        u = get_top ();
        visited[u] = 1;
        for ( j = num[u]; j; j = next[j] )
        {
            v = e[j].y;
            if ( !visited[v] && value[v] < min ( value[u], e[j].w ) )
            {
                if ( idx[v] == 0 )
                {
                    heap[++ size] = v;
                    idx[v] = size;
                }
                
                value[v] = min ( value[u], e[j].w );
                update ( v );
            }
        }
    }
    return value[dst];
}

int get_top ()
{
    int res = heap[1], p = 1, q = 2, r = heap[size --];
    while ( q <= size )
    {
        if ( q < size && value[heap[q + 1]] > value[heap[q]] )
        {
            q ++;
        }
        if ( value[heap[q]] > value[r] )
        {
            idx[heap[q]] = p;
            heap[p] = heap[q];
            p = q;
            q = p << 1;
        }
        else
        {
            break;
        }
    }
    heap[p] = r;
    idx[r] = p;
    return res;
}

void update ( int r )
{
    int q = idx[r], p = q >> 1;
    while ( p && value[heap[p]] < value[r] )
    {
        idx[heap[p]] = q;
        heap[q] = heap[p];
        q = p;
        p = q >> 1;
    }
    heap[q] = r;
    idx[r] = q;
}

