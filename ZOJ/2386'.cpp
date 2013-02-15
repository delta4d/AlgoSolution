#include <iostream>
#include <algorithm>
using namespace std;
#define inf 500000
int a[inf+5],b[inf+5],c[inf+5],n;
__int64 ans;
int find(int x)
{
    int l=1,h=n,m;
    while (h>=l)
    {
        m=(l+h)/2;
        if (x<b[m]) h=m-1;
        else if (x>b[m]) l=m+1;
        else return m;
    }
    return -1;
}
void discretization()//��ɢ�������ÿ�������������b[]���������ڵ�mС��Ԫ�ر��m��
{
    int i,t;
    for (i=1;i<=n;i++)
    {
        t=find(a[i]);
        a[i]=t;
    }
}
inline int lowbit(int x)
{
    return x&(-x);
}
int sum(int k)//��sum(b[1]~b[k])
{
    int i,res=0;
    for (i=k;i>0;i-=lowbit(i))
        res+=c[i];
    return res;
}
void improve(int k)//����a[i]��b[a[i]]��ֵ���޸�
{
    int i;
    for (i=k;i<=n;i+=lowbit(i))
        c[i]++;
}
void built()//������״����c[]
{
    int i,k;
    memset(b,0,sizeof(b));
    memset(c,0,sizeof(c));
    for (i=1;i<=n;i++)
    {
        k=a[i];
        ans+=i-sum(k)-1;
        b[k]=1;
        improve(k);
    }
}
int main()
{
    int i;
    while (scanf("%d",&n)!=EOF && n)
    {
        for (i=1;i<=n;i++)
        {
            scanf("%d",a+i);
            b[i]=a[i];
        }
        sort(b+1,b+n+1);
        discretization();
        ans=0;
        built();
        printf("%I64d\n",ans);
    }
    return 0;
}
