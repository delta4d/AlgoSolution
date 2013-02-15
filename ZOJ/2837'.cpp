#include<stdio.h>
#include<string.h>
const int M = 64;
double dp[2][64];
bool f=0;
double re;
int m,n;
void DP()
{
    memset(dp,0,sizeof(dp));
    dp[f][0]=1;
    int i,j,k;
    for(i=0; i<1005; i++)
    {
        memset(&dp[!f],0,sizeof(dp[0]));
        for(j=0; j<m; j++)
        {
            if(j==n||j==m-n)
            {
                re+=i*dp[f][j];
                continue;
            }
            for(k=1; k<=6; k++)
                dp[!f][(j+k)%m]+=dp[f][j]/6;
        }
        f=!f;
    }
}

int main()
{
    //while(scanf("%d%d",&m,&n)!=EOF)
    for (m=1; m<=32; ++m) for (n=1; n<=m; ++n)
    {
        m--;
        m<<=1;
        n--;
        re=0;
        DP();
        printf("%.2lf\n",re);
    }
    return 0;
}