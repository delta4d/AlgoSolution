#include<stdio.h>
#include<string.h>
//�������㷨��
#define NOUSE -1//memset ���Գ�ʼ��int�ĸ���
class Hungary
{
    //�ı�����
    //include<string.h>

#define MAXU     1251
#define MAXV     1251
public:
    void SetGraph(int u,int v,bool value)
    {
        g[u][v] = value;
    }
    void SetUV(int u,int v)
    {
        uN = u;    //���ö���ͼ��Χ
        vN = v;
    }
    void Initialize()
    {
        memset(g,false,sizeof(g));    //��ʼ��
    }
    bool SearchPath(const int &u);//����u��ĳ��ƥ��
    int MaxMatch();//�������ƥ��
    int* GetUM()
    {
        return uM;
    }
    int* GetVN()
    {
        return vM;
    }
//    void print(){for(int i=1;i<=uN;i++){for(int j=1;j<=vN;j++)if(g[i][j])printf("X");else printf("O");printf("\n");}}
protected:
    int uN,vN;//uΪ����ͼ����ߣ�vΪ�ұ�
    bool g[MAXU][MAXV];
    bool chk[MAXV];// ������ ���ĳ�� uM[v]�Ƿ�check
    int uM[MAXV],vM[MAXU];//uM������v��ƥ���u��vM������u��ƥ���v
};

bool Hungary::SearchPath(const int &u)
{
    int v;
    for ( v = 1; v <= vN; v++ )
    {
        if (g[u][v] && !chk[v])
        {
            chk[v] = true;
            if (uM[v] == NOUSE || SearchPath(uM[v]))//���v�Ѿ���ux��=uM[v]��ƥ�䣬��uxƥ����v��������У�������һ��ƥ��
            {
                uM[v] = u;
                vM[u] = v;
                return true;
            }
        }
    }
    return false;
}

int Hungary::MaxMatch()
{
    int u;
    int ret = 0;
    memset(uM,NOUSE,sizeof(uM));
    memset(vM,NOUSE,sizeof(vM));
    for ( u = 1; u <= uN; u++ )//һ������u����ƥ��
    {
        if (vM[u] == NOUSE)
        {
            memset(chk,0,sizeof(chk));
            if (SearchPath(u))
                ret++;
        }
    }
    return ret;
}

const int LEN = 51;

char c[LEN][LEN];

struct point
{
    int i;
    int j;
};

point p[LEN][LEN];

#define EMPTY 'o'
#define GRASS '*'
#define WALL '#'

int main()
{
// freopen("in.txt","r",stdin);
    int t;
    scanf("%d",&t);
    for (int Case = 1; Case <= t; Case++)
    {
        Hungary h;
        int m,n;
        int idi = 1, idj = 1, i, j, k;
        scanf("%d %d",&n,&m);
        gets(c[0]);
        for ( i = 0; i < n; i++ )
            gets(c[i]);
        memset(p,NOUSE,sizeof(p));
        h.Initialize();
        for ( i = 0; i < n; i++ )
            for (    j = 0; j < m; j++ )
                if (c[i][j] == EMPTY)
                {
                    if (p[i][j].j == NOUSE)
                    {
                        p[i][j].j = idj;
                        k = j + 1;
                        while (k < m && c[i][k] != WALL)
                        {
                            if (c[i][k] == EMPTY)
                                p[i][k].j = idj;
                            k++;
                        }
                        idj++;
                    }
                    if (p[i][j].i == NOUSE)
                    {
                        p[i][j].i = idi;
                        k = i + 1;
                        while ( k < n && c[k][j] != WALL)
                        {
                            if (c[k][j] == EMPTY)
                                p[k][j].i = idi;
                            k++;
                        }
                        idi++;
                    }
                    h.SetGraph(p[i][j].i,p[i][j].j,true);
                }
        idi--;
        idj--;
        h.SetUV(idi,idj);
        printf("Case :%d\n",Case);
        printf("%d\n",h.MaxMatch());

    }
    return 0;
}
