#include <cstdio>
#include <cstdlib>
#define MAXN 100001
#define MAX 500001
struct node
{
    long x , y , w ;
}T[MAXN<<1] ;
long N , M , S , Val ;
void build( long p , long a , long b )
{
    T[p].x = a ;
    T[p].y = b ;
    T[p].w = MAX ;
    if  ( a+1 < b )
    {
        build( p<<1 , a , a+b>>1 ) ;
        build( (p<<1)+1 , a+b>>1 , b ) ;
    }
}
void update( long p )
{
    if ( T[p].w > Val ) T[p].w = Val ;
    if ( T[p].x+1 < T[p].y ) if  ( S <= T[p].x+T[p].y>>1 ) update(p<<1) ;
	else update( (p<<1)+1 ) ;
}
long query( long p , long a , long b )
{
    if (( a <= T[p].x ) && ( T[p].y <= b )) return  T[p].w ;
    long mid = T[p].x+T[p].y>>1 ;
    if (b <= mid) return  query( p<<1 , a , b ) ;
    if (mid <= a) return  query( (p<<1)+1 , a , b ) ;
    long t1 = query(p<<1, a , mid) ;
    long t2 = query((p<<1)+1, mid, b ) ;
    return  t1 < t2 ? t1 : t2 ;
}
int main()
{
    long temp ;
    while (scanf( "%ld%ld", &N, &M) != EOF)
    {
        build(1, 0, N) ;
        S = 1;
        Val = 0;
        update(1);
        while (M--)
        {
            scanf("%ld%ld", &temp , &S) ;
            Val = query(1 ,temp-1 ,S-1) + 1 ;
            update(1) ;
        }
        printf("%ld\n" , query(1, N-1, N )) ;
    }
    return  0 ;
}
