#include<cstdlib>
#include<string>
#include<queue>
#include<iostream>
#include<memory>
using namespace std;

const int MaxN = 5000;

struct f
{
    int mod;
    string a;

    void print()
    {
        cout << a << endl;
    }
};

bool flag[MaxN];
int X[10];
int m;
int n;

int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

void bfs()
{
    int i;
    int j;
    int k;
    queue<f>Q;
    f temp;
    f temp1;
    bool find = false;
    memset(flag, false, sizeof(flag));

    if (n == 0)
    {
        cout << '0' << endl;
        return;
    }

    for (i=0; i<m; ++i)
    {
        if (X[i] != 0)
        {
            flag[X[i] % n] = true;
            temp.mod = X[i] % n;
            temp.a = '0' + X[i];
            Q.push(temp);
        }
    }

    while (!Q.empty())
    {
        temp = Q.front();
        Q.pop();

        if (temp.mod == 0)
        {
            temp.print();
            return;
        }

        for (i=0; i<m; ++i)
        {
        	k = (temp.mod * 10 + X[i]) % n;
        	
            if (!flag[k])
            {
                temp1.mod = k;
                temp1.a = temp.a + (char)('0' + X[i]);

                Q.push(temp1);
                flag[k] = true;
            }
        }
    }

    if (!find)
    {
        cout << '0' << endl;
    }

    return;
}

int main(void)
{
    int i;

    while (cin >> n)
    {
        cin >> m;

        for (i=0; i<m; ++i)
        {
            cin >> X[i];
        }

        qsort(X, m, sizeof(X[0]), cmp);

        bfs();
    }

    return 0;
}
