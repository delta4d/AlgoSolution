#include <iostream>
#include <list>
#include <map>
#include <set>
using namespace std ;

map< int,list<int> > Map ;
set<int> used ;

bool Read( int &num, int n )
{
    int i, temp ;
    num = 0 ;
    for( i=0; i<n; ++i ){
        scanf("%d", &temp );
        if( temp == -1 )
            return false ;
        num *= 10 ;
        num += temp ;
    }
    return true ;
}

bool dfs( int from, int end )
{
    list<int>::iterator it=Map[from].begin() ;
    for( ; it!=Map[from].end(); ++it ){
        if( *it == end )
            return true ;
        if( !used.count(*it) ){
            used.insert(*it) ;
            if( dfs(*it, end) )
    return true ;
        }
    }
    return false ;
}

int main()
{
    int n, s, start, end, temp, from, to ;
    for( s=1; scanf("%d",&n), n; ++s ){
        Map.clear() ;
        Read(start,n);
        Read(end,n);
        while( Read(from,n) ){
            Read(to,n) ;
            Map[from].push_back(to) ;
            Map[to].push_back(from) ;
        }
        used.clear() ;
        if( dfs(start,end) )
            printf("Maze #%d can be travelled\n", s );
        else
            printf("Maze #%d cannot be travelled\n", s );
    }
    return 0 ;
}
