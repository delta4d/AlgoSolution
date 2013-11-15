/*����ͼ�и�����Դ����ĳ��·������СȨ�ߵ����ֵ��

���Խ��俴����Դ���·���ı��֣�ʹ��dijkstra�㷨+���ѡ�

��Դ���·�����㷨�ǣ���¼��Դ���������ÿһ��i�����·Ϊvalue[i]��

���ڵ�ǰ����value�е���Сֵ��u������BFSʽ�Ĳ���������ÿ�� Edge(u,v)��

���edge(u,v)+value[u] < value[v] �����v��

�Դ������޸ġ���¼ÿ����Ŀǰ�ܳ��ܵ��������Ϊvalue[i]������Դ��������·������СȨ�е����ֵ����

��u�ǵ�ǰ��㣬����ÿ��Edge(u,v)����·����չ��vʱ����С value��min(edge, value[u])������value[v] ʱ���¡�

���ڱ���Ŀ�޴�(M<1000000)�����ʹ�������档ʹ��num���鱣�����Ϊi����ʼλ�ã�next���鱣������ 

num[i]=a,next[a]=b,next[b]=c,next[c]=d,next[d]=0������abcd��Ϊ�������е�λ�ã���ʾ��iΪ���ı���abcd����

WA��һ���磬�ŷ��ְ�INF�����̫С�ˡ�

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
//heap��ŵ���ţ�idx��ŵ���heap�е�λ��

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

