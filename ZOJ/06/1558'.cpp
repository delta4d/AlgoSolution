#include <stdio.h>
#include <string.h>
int mem[201]; //记忆表格
int a[6]; //输入的数字
int search()
{
    int i,k;
    bool change=true; //标记true好进入循环
    while (change) //有改变就再优化
    {
        change=false; //假定没有可以再优化了
        for (i=1; i<200; i++)
        {
            for (k=0; k<6; k++)
            {
                if (mem[i]>0) //如果以前已经有过记录
                {
                    if (i+a[k]<201&&mem[i]+1<mem[i+a[k]])//如果新的方案可以更少就替换
                    {
                        change=true; //标记有优化
                        mem[i+a[k]]=mem[i]+1;
                    }
                    if (i-a[k]>=0&&mem[i]+1<mem[i-a[k]])
                    {
                        change=true;
                        mem[i-a[k]]=mem[i]+1;
                    }
                }
            }
        }//以上处理加
        /*for (i=1; i<200; i++)
        {
            for (k=0; k<6; k++)
            {
                if (mem[i]>0)//如果以前已经有过记录
                {
                    if (i-a[k]>=0&&mem[i]+1<mem[i-a[k]])
                    {
                        change=true;
                        mem[i-a[k]]=mem[i]+1;
                    }
                }
            }
        }//以上处理减*/
    }
    return 1;
}
int main ()
{
    int i,max;
    int sum;
    int t,st;
	freopen("f:\\in.txt", "r", stdin);
    scanf("%d",&st);
    for (t=0; t<st; t++)
    {
        memset(mem,10,sizeof(mem)); //标记为较大值，等待优化
        for (i=0; i<6; i++)
        {
            scanf("%d",a+i);
            mem[a[i]]=1; //已经有的就当然只要1就可以实现了
        }
        sum=0;
        search(); //优化入口
        max=0;
        for (i=1; i<101; i++)
        {
            if (max<mem[i]) max=mem[i];
            sum+=mem[i];
        }
        printf("%.2lf %d\n",((double)sum)/((double)100),max);
    }
    return 0;
}