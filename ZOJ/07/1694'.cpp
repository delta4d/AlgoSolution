#include<stdio.h>
#include<string.h>

int num[100],f[100],out[100];
int max,L,target,count,l,len;

void dfs(int p,int sum,int cur)
{
    int i;
    if (sum>target) return;
    if (p>=L)
    {
        if (sum==max) count++;
        if (sum>max)
        {
            max=sum;
            for (i=0;i<len;i++)
                out[i]=f[i];
            l=len;
            count=1;
        }
    }
    else
    {
        f[len++]=cur*10+num[p];
        dfs(p+1,sum+cur*10+num[p],0);
        f[len--]=0;
        if (p<L-1)
            dfs(p+1,sum,cur*10+num[p]);
    }
}

int main()
{
    int i;
    char n[8];
    while (scanf("%d %s",&target,&n)!=EOF)
    {
        if (target==0&&n[0]=='0') break;
        L=strlen(n);
        for (i=0;i<L;i++)
            num[i]=n[i]-'0';
        count=0;
        max=-1;
        l=len=0;
        memset(out,0,sizeof(out));
        dfs(0,0,0);
        if (count>1) printf("rejected\n");
        else if (count==0) printf("error\n");
        else
        {
            printf("%d",max);
            for (i=0;i<l;i++)
                printf(" %d",out[i]);
            printf("\n");
        }
    }
    return 0;
}
