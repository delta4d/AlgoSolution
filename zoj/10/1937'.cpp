/*迭代搜索，用深度优先的话需要找出所有加法链，然后再取最小的，至少是n！的复杂度，用广度的话
找到的第一个加法链就是最短的，但是对空间占用太大
逐步深化的迭代搜索可以保证第一个找到的加法链就是最短的，又不需要太大的空间开销。
基本思想是控制回溯的搜索深度deep， 每次使deep加1，直到找到一条加法链

（更多优化）
1.deep有一个下界，从此下界开始搜索，可以最大加快搜索进程
2.更多剪枝
3.最短加法链的上界，是一个幂树。

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
