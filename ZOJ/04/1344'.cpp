#include<iostream>
#include<queue>
#include<string>
using namespace std;

//north :0 east :1 south : 2 west :3, stop :4

struct point {
    int x,y,step;//人的状态
    int flag;//狗的动作
};

int n,m,D;
int x1,y1,x2,y2,x3,y3;
int mark[51][51][51];
int loop[5][2] = {-1, 0, 0, 1, 1, 0, 0, -1, 0, 0};
char map[51][51];
point dog[51];

//预处理狗的动作
void init() {
    int i,j;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> D;
    x1--;
    x2--;
    x3--;
    y1--;
    y2--;
    y3--;
    dog[0].x = x3, dog[0].y = y3, dog[0].flag = 0;
    for (i=1; i<=D; ++i) {
        char k;
        cin >> k;
        if ( k == 'G' ) {
            dog[i].x = dog[i-1].x + loop[dog[i-1].flag][0];
            dog[i].y = dog[i-1].y + loop[dog[i-1].flag][1];
            dog[i].flag = dog[i-1].flag;
        } else if (k == 'L') {
            dog[i].x = dog[i-1].x, dog[i].y=dog[i-1].y;
            dog[i].flag = (dog[i-1].flag - 1 + 4) % 4;
        } else if (k == 'R') {
            dog[i].x = dog[i-1].x, dog[i].y = dog[i-1].y;
            dog[i].flag = (dog[i-1].flag + 1)%4;
        }
    }
    for (i=0; i<n; ++i)
        for (j=0; j<m; ++j)
            cin >> map[i][j];
    return;
}

//检查狗的视线
bool legal(int x,int y,int flag) {
    int tx = dog[flag].x,ty = dog[flag].y;
    bool ok = false;
    while (true) {
        if (tx < 0 || tx >= n || ty < 0 || ty >= m) {
            ok = true;
            break;
        }
        if (tx == x && ty == y) {
            ok = false;
            break;
        }
        if (map[tx][ty] == '*') {
            ok = true;
            break;
        }
        tx += loop[dog[flag].flag][0];
        ty += loop[dog[flag].flag][1];
    }
    return ok;
}

int bfs()
{
    queue<point> q;
    point p, t;
    memset(mark, 0, sizeof(mark));
    p.x = x1, p.y = y1;
    p.step = 0, p.flag = 0;
    mark[p.x][p.y][p.flag] = 1;
    q.push(p);
    while (!q.empty()) {
        p = q.front();
        q.pop();
        if (p.x==x2 && p.y==y2)
            return p.step;
        int i;
        for (i=0; i<5; ++i) {
            int tx = p.x + loop[i][0];
            int ty = p.y + loop[i][1];
            int step = p.step + 1;
            int flag = p.flag + 1;
            if (legal(tx,ty,flag) && map[tx][ty]!='*' && tx>=0 && tx<n && ty>=0 && ty<m ) {
                if (!mark[tx][ty][flag] && !( tx==dog[flag].x && ty==dog[flag].y )) {
                    mark[tx][ty][flag] = 1;
                    t.x = tx, t.y = ty;
                    if (flag == D) flag = 0;
                    t.flag = flag;
                    t.step = step;
                    q.push(t);
                }
            }
        }
    }
    return -1;
}

int main()
{
    int test = 1;
    //freopen("f:\\in.txt", "r", stdin);
    while (cin >> n >> m ) {
        if (!n && !m) break;
        if (test != 1) cout << endl;
        init();
        int min = bfs();
        cout << "Case " << test++ << ":" << endl;
        if (min < 0) cout << "No way out" << endl;
        else cout << "Minimal time is: " << min << endl;
    }
    return 0;
}
