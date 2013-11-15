/*������������������ȵĻ���Ҫ�ҳ����мӷ�����Ȼ����ȡ��С�ģ�������n���ĸ��Ӷȣ��ù�ȵĻ�
�ҵ��ĵ�һ���ӷ���������̵ģ����ǶԿռ�ռ��̫��
����ĵ����������Ա�֤��һ���ҵ��ļӷ���������̵ģ��ֲ���Ҫ̫��Ŀռ俪����
����˼���ǿ��ƻ��ݵ��������deep�� ÿ��ʹdeep��1��ֱ���ҵ�һ���ӷ���

�������Ż���
1.deep��һ���½磬�Ӵ��½翪ʼ�������������ӿ���������
2.�����֦
3.��̼ӷ������Ͻ磬��һ��������

*/

#include <iostream>
using namespace std;

int n;
int deep;
int best;
int v[50];
int re[50];
bool found;

void dfs(int i)
{
    if (!found)
    {
        if (v[i] == n)
        {
            best = i;
            
            for (int j=0; j<=i; ++j)
            {
                re[j] = v[j];
            }
            
            found = true;
            
            return;
        }
        else if (i < deep)
        {
            for (int j=i; j>=0; --j)
            {
                if (v[j] * 2 > v[i])
                {
                    for (int k=j; k>=0; --k)
                    {
                        if (v[j]+v[k] > v[i] && v[j] + v[k] <= n)
                        {
                            v[i+1] = v[j]+v[k];
                            
                            dfs(i + 1);
                        }
                    }
                }
            }
        }
    }
}

int main()
{
    while (cin>>n && n>0)
    {
        found = false;
        deep = 2;
        best = n;
        
        while (!found)
        {
            v[0] = 1;
            dfs(0);
            deep++;
        }
        
        for (int i=0; i<=best; ++i)
        {
            cout << re[i] << " ";
        }
        
        cout << endl;

    }
    
    return 0;
}
