#include <iostream>
#include <queue>
#include <set>
#include <cstring>
#include <cstdio>
using namespace std ;

struct Node{
    int pos, cnt ;
    Node(){}
    Node(int tp, int tc):pos(tp), cnt(tc) {}
};
queue<Node> q ;
set<int> used ;

bool Map[9][9] ;
int dirx1[4] = {0, 0, 1, -1 } ;
int diry1[4] = {1, -1, 0, 0 } ;
int dirx2[4] = {0, 0, 2, -2 } ;
int diry2[4] = {2, -2, 0, 0 } ;

void getMap(int pos)
{
    int r, c ;
    memset( Map, 0, sizeof(Map) ) ;
    while( pos ){
        c = pos%10 ;
        pos /= 10 ;
        r = pos%10 ;
        pos /= 10 ;
        Map[r][c] = true ;
    }
}

int getPos()
{
    int ret=0, i, j ;
    for( i=1; i<=8; ++i ){
        for( j=1; j<=8; ++j ){
            // 注意必须是从统一的左上到右下的压缩，也可以用别的，但是顺序要统一。 
            if( Map[i][j] ){
                ret *= 10 ;
                ret += i ;
                ret *= 10 ;
                ret += j ;
            }
        }
    }
    return ret ;
}

inline bool OK( int i, int j )
{
    return i>0 && i<=8 && j>0 && j<=8 ;
}

bool bfs(int start, int end )
{
    Node node ;
    while( !q.empty() )
        q.pop() ;
    q.push( Node(start,0) );
    used.clear() ; 
    used.insert(start);
    int i, j, d, x, y ;
    while( !q.empty() ){
        node = q.front() ;
        q.pop() ;
        //if (node.cnt == 8) return false;
        //if (node.pos == end) return true;
        getMap(node.pos) ;
        ++node.cnt ;
        for( i=1; i<=8; ++i ){
            for( j=1; j<=8; ++j ){
                if( Map[i][j] ){
                    for( d=0; d<4; ++d ){
                        x = i+dirx1[d] ;
                        y = j+diry1[d] ;
                        if( OK(x,y) && !Map[x][y] ){
                            Map[i][j] = false ;
                            Map[x][y] = true ;
                            node.pos = getPos() ;
                            if( used.find(node.pos) == used.end() ){
                                used.insert(node.pos);
                                if (node.pos == end) return true;
                                if (node.cnt < 8)
                                q.push(node);
                            }
                            Map[i][j] = true ;
                            Map[x][y] = false ;
                        }
                        x = i+dirx2[d] ;
                        y = j+diry2[d] ;
                        // Map[i+dirx1[d]][j+diry1[d]]就是夹在Map[i][j]和Map[x][y]的位置 
                        if( OK(x,y) && !Map[x][y] && Map[i+dirx1[d]][j+diry1[d]] ){
                            Map[i][j] = false ;
                            Map[x][y] = true ;
                            node.pos = getPos() ;
                            if( used.find(node.pos) == used.end() ){
                                used.insert(node.pos);
                                if (node.pos == end) return true;
                                if (node.cnt < 8)
            					q.push(node) ;
                            }
                            Map[i][j] = true ;
                            Map[x][y] = false ;
                        }
                    }
                }
            }
        }
    }
    return false ;
}

int main()
{
	freopen("f:\\in.txt", "r", stdin);
    int i, x, y, start, end, temp ;
    while(1){
        bool flag = true ;
        memset(Map,0,sizeof(Map));
        for( i=0; i<4; ++i ){
            if( EOF == scanf("%d%d",&x,&y) ){
                flag = false ;
                break ;
            }
            Map[x][y] = true ;
        }
        if( !flag )
            break ;
        start = getPos() ; //printf("%d ", start);
        memset(Map,0,sizeof(Map));
        for( i=0; i<4; ++i ){
            scanf("%d%d", &x, &y );
            Map[x][y] = true ;
        }
        end = getPos(); //printf("%d\n", end);
        if( start == end ){
            puts("YES");
            continue ;
        }
        if( bfs(start, end) )
            puts("YES");
        else
            puts("NO");
    }
    return 0 ;
}
