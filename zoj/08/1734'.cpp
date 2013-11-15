#include<iostream>
#include<queue>
using namespace std;
bool useif[105];	//�Ƿ�����ʹ��
int father[105];	//��Ӣ�İ�
int edge[105][105]; //�ߣ�ֵ��Ȩ
int n,m;
int ford()
{
    int max=0;
    while (1)		//һֱ�ң�ֱ���Ҳ���
    {
        int now,i,min=0xffff;
        memset(useif,0,sizeof(useif));
        queue<int> q;
        q.push(0);
        while (!q.empty())//BFS��һ������·
        {
            now=q.front();
            q.pop();
            if (now==n)break;
            for (i=0;i<=n;i++)
            {
                if (!useif[i]&&edge[now][i])
                {
                    useif[i]=true;
                    q.push(i);//�������
                    father[i]=now;
                }
            }
        }
        if (!useif[n])break;
        for (i=n;i;i=father[i])
        {
            if (edge[father[i]][i]<min)
                min=edge[father[i]][i];
        }
        for (i=n;i;i=father[i])
        {
            edge[father[i]][i]-=min;//������������
            edge[i][father[i]]+=min;//������������
        }
        max+=min;
    }
    return max;
}
int main()
{
    int i,j,np,nc,a,b,c;
    char ss[50];
    while (scanf("%d%d%d%d",&n,&np,&nc,&m)!=EOF)
    {
        getchar();
        memset(edge,0,sizeof(edge));
        memset(father,-1,sizeof(father));
        for (i=1;i<=m;i++)
        {
            scanf("%s",ss);
            sscanf(ss,"(%d,%d)%d",&a,&b,&c);//��һ�������������ͦ���õ�
            edge[a+1][b+1]+=c;
        }
        for (i=1;i<=np;i++)
        {
            scanf("%s",ss);
            sscanf(ss,"(%d)%d",&a,&b);
            edge[0][a+1]+=b;//0��Դ��
        }
        n++;//���
        for (i=1;i<=nc;i++)
        {
            scanf("%s",ss);
            sscanf(ss,"(%d)%d",&a,&b);
            edge[a+1][n]+=b;
        }
        printf("%d\n",ford());
    }
}
