#include <stdio.h>
#include <string.h>
int mem[201]; //������
int a[6]; //���������
int search()
{
    int i,k;
    bool change=true; //���true�ý���ѭ��
    while (change) //�иı�����Ż�
    {
        change=false; //�ٶ�û�п������Ż���
        for (i=1; i<200; i++)
        {
            for (k=0; k<6; k++)
            {
                if (mem[i]>0) //�����ǰ�Ѿ��й���¼
                {
                    if (i+a[k]<201&&mem[i]+1<mem[i+a[k]])//����µķ������Ը��پ��滻
                    {
                        change=true; //������Ż�
                        mem[i+a[k]]=mem[i]+1;
                    }
                    if (i-a[k]>=0&&mem[i]+1<mem[i-a[k]])
                    {
                        change=true;
                        mem[i-a[k]]=mem[i]+1;
                    }
                }
            }
        }//���ϴ����
        /*for (i=1; i<200; i++)
        {
            for (k=0; k<6; k++)
            {
                if (mem[i]>0)//�����ǰ�Ѿ��й���¼
                {
                    if (i-a[k]>=0&&mem[i]+1<mem[i-a[k]])
                    {
                        change=true;
                        mem[i-a[k]]=mem[i]+1;
                    }
                }
            }
        }//���ϴ����*/
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
        memset(mem,10,sizeof(mem)); //���Ϊ�ϴ�ֵ���ȴ��Ż�
        for (i=0; i<6; i++)
        {
            scanf("%d",a+i);
            mem[a[i]]=1; //�Ѿ��еľ͵�ȻֻҪ1�Ϳ���ʵ����
        }
        sum=0;
        search(); //�Ż����
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