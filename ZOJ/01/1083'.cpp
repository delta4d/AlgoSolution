#include<cstdio>
#include<string>

using namespace std;

int topo[26][26];
char map[31][31];
int xmax[26],xmin[26],ymax[26],ymin[26];
char result[28];
int h,w;
int exist[26];
int used[26];
int sum;

void solve(int step)
{
    int s[26];
    int i,j;

    if(step==sum)
    {
        for(i=0; i<sum; i++)
            printf("%c",result[i]);
        printf("\n");
    }

    else
    {
        memset(s,0,sizeof(s));
        for(i=0; i<26; i++)
            if(exist[i]&&!used[i])
            {
                for(j=0; j<26; j++)
                    if(topo[j][i]==1&&!used[j])
                        s[i]++;
            }
        for(i=0; i<26; i++)
            if(exist[i]&& !used[i]&& s[i]==0)
            {
                result[step]=i+'A';
                used[i]=1;
                solve(step+1);
                used[i]=0;
            }
    }
    return;
}

int main()
{
    int i,j;

    while(scanf("%d",&h)!=EOF)
    {
        scanf("%d",&w);
        getchar();
        for(i=0; i<h; i++)
            gets(map[i]);

        memset(xmin,26,sizeof(xmin));
        memset(xmax,0,sizeof(xmax));
        memset(ymin,26,sizeof(ymin));
        memset(ymax,0,sizeof(xmax));
        memset(exist,0,sizeof(exist));
        sum=0;
        for(i=0; i<h; i++)
            for(j=0; j<w; j++)
                if(map[i][j]!='.')
                {
                    if(!exist[map[i][j]-'A'])
                    {
                        exist[map[i][j]-'A']=1;
                        sum++;
                    }
                    if(j>xmax[map[i][j]-'A'])
                        xmax[map[i][j]-'A'] = j;
                    if(j<xmin[map[i][j]-'A'])
                        xmin[map[i][j]-'A'] = j;
                    if(i>ymax[map[i][j]-'A'])
                        ymax[map[i][j]-'A'] = i;
                    if(i<ymin[map[i][j]-'A'])
                        ymin[map[i][j]-'A'] = i;
                }

        memset(topo,0,sizeof(topo));
        for(i=0; i<26; i++)
            if(exist[i])
            {
                for(j=xmin[i]; j<=xmax[i]; j++)
                    if(map[ymin[i]][j] != i+'A')
                        topo[i][map[ymin[i]][j]-'A'] = 1;
                for(j=xmin[i]; j<=xmax[i]; j++)
                    if(map[ymax[i]][j] != i+'A')
                        topo[i][map[ymax[i]][j]-'A'] = 1;
                for(j=ymin[i]; j<=ymax[i]; j++)
                    if(map[j][xmin[i]] != i+'A')
                        topo[i][map[j][xmin[i]]-'A'] = 1;
                for(j=ymin[i]; j<=ymax[i]; j++)
                    if(map[j][xmax[i]] != i+'A')
                        topo[i][map[j][xmax[i]]-'A'] = 1;
            }

        memset(used,0,sizeof(used));
        solve(0);
    }
    return 0;
}