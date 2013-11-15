// ***************************************************************
//  zoj1003   version:  1.0   ��  date: 04/02/2007
//  -------------------------------------------------------------
//  DFS!
// �ȸ������ֽ⣬Ȼ����С������������ɹ��ֽ���СҲҲ�ɹ��ֽ⣬��ô�������
// ����ֽⲻ�ɹ�����ô���Ǽٵ�
//  -------------------------------------------------------------
//  Copyright (C) 2007 - All Rights Reserved
// ***************************************************************
//
// ***************************************************************

#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int flag_a;
int flag_b;

void DFS(int a, int b, int temp)
{
    if (flag_a==1)
    {
        return;
    }
    if (a==1 && b==1)
    {
        flag_a=1;
    }
    else if (b==1)
    {
        flag_b=1;
    }

    while ((temp<=100) && (temp<=a || temp<=b))
    {
        if (a%temp==0)
        {
            DFS(a/temp,b,temp+1);
        }
        if (b%temp==0)
        {
            DFS(a,b/temp,temp+1);
        }
        temp++;
    }
}

void run(int a,int b)
{
    flag_a=flag_b=0;

    if (a<b)
    {
        int temp=a;
        a=b;
        b=temp;
    }

    DFS(a,b,2);

    if (flag_a==0 && flag_b==1)
    {
        cout<<b<<endl;
    }
    else
    {
        cout<<a<<endl;//�Σ������Ȼд��b�ˡ���������
    }

    return;
}

int main()
{
    int a,b;
	freopen("f:\\in.txt", "r", stdin);
    while (cin>>a>>b)
    {
        run(a,b);
    }
    return 0;
}
