#include<iostream>
using namespace std;

int n;

int max(int a, int b)
{
    return a > b ? a : b;
}

int GHP()//get highest point
{
    int g1,g2,q1,q2,pg1,pg2,pq1,pq2;

//g->get, q->quit, pg->preget,pq->prequit
    int t;
    g1=g2=q1=q2=pg1=pg2=pq1=pq2 = 0;//��ʼ��

    cin>>t;//����Ԫ
//ȡ��Ԫ
    g1 = t;
    q1 = t;
    if(n<=1) return g1;//ֻ��һ����λ

//��ȡ��Ԫ
    cin>>t;//����Ԫ
    g2 = t;
    q2 = 0;

//�ӵ���������n-1��
    for(int i=2; i<n-1; ++i)
    {
        pg1 = g1;
        pq1 = q1;
        pg2 = g2;
        pq2 = q2;
        cin>>t;
        g1 = pq1 + t;
        q1 = max(pg1,pq1);
        g2 = pq2 + t;
        q2 = max(pg2,pq2);
    }

//�Բ�ȡ��Ԫ�Ĵ������һ��Ԫ��
    cin >> t;
    pg2 = g2;
    pq2 = q2;
    g2 = pq2+t;
    q2 = max(pg2,pq2);

    return max(max(g1,q1),max(g2,q2));
}

int main()
{
    while(cin >> n)
    {
        cout << GHP() << endl;
    }
    return 0;
}
