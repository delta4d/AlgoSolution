#include <iostream>
#include <deque>
#include <cstdio>
using namespace std;
struct node
{
    int x;
	int y;
	int sta;
	int step;
};
deque <node> que;
int map[20][20][1025];
int mat[30][30];
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int num,n,m;
int dfs(int cx,int cy)
{
    node t1;
    int i,p,q;
    memset(map,0,sizeof(map));
    que.clear();
    t1.x=cx;
    t1.y=cy;
    t1.sta=0;
    t1.step=0;
    que.push_back(t1);
    map[t1.x][t1.y][t1.sta]=1;
    while (!que.empty())
    {
        t1 = que.front();
        que.pop_front();
        if (t1.sta==(1<<num)-1) return t1.step;
        for (i=0;i<4;i++)
        {
            p=t1.x+dir[i][0];
            q=t1.y+dir[i][1];
            if (p<0 || p>=n || q<0 || q>=m) continue;
            if (mat[p][q]==-3) continue;
            node t2;
            t2.x=p;
            t2.y=q;
            t2.sta=t1.sta;
            t2.step=t1.step+1;
            if (mat[p][q]==-1)
            {
                if (map[p][q][t2.sta]) continue;
                que.push_back(t2);
                map[p][q][t2.sta]=1;
            }
            if (mat[p][q]>=0)
            {
                t2.sta |= (1<<mat[p][q]);
                if (map[p][q][t2.sta]) continue;
                map[p][q][t2.sta] = 1;
                que.push_back(t2);
            }
        }
    }
    return -1;
}
char s[30][30];
int main()
{
    int i,j,cx,cy;
    while (scanf("%d%d",&m,&n)!=EOF && m+n)
    {
        num=0;
        for (i=0;i<n;i++)
        {
            scanf("%s",s[i]);
            for (j=0;j<m;j++)
            {
                if (s[i][j]=='.') mat[i][j] = -1;
                else if (s[i][j]=='o')
                {
                    mat[i][j]=-1;
                    cx=i;
                    cy=j;
                }
                else if (s[i][j]=='x') mat[i][j]=-3;
                else mat[i][j]=num++;
            }
        }
        int ans=dfs(cx,cy);
        printf("%d\n",ans);
    }
    return 0;
}
