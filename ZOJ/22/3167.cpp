#include<iostream>
#include<memory>

using namespace std;

struct BigNum
{
    int num[300];
    long len;
};

BigNum Mul(BigNum &a, int &b)
{
    long i;
    long j;
    long len;
    BigNum c;
    memset(c.num, 0, sizeof(c.num));

	len = a.len;

    for (i=0; i<len; ++i)
    {
        c.num[i] += (a.num[i] * b);

        if (c.num[i] >= 10)
        {
            c.num[i+1] += (c.num[i] / 10);
            c.num[i] %= 10;
        }
    }

    while (c.num[len] > 0)
    {
        c.num[len+1] = c.num[len]/10;      
        c.num[len++] %= 10;  
    }

    c.len = len;

    return c;
}

int main(void)
{
    int k;
    int m;
    int i;
    int t;
    BigNum f;
    BigNum temp;

    while (cin >> k >> m)
    {
        memset(f.num, 0, sizeof(f.num));

        i = 0;
        t = m;

        while (m != 0)
        {
            f.num[i] = m % 10;
            m /= 10;
            ++i;
        }

        f.len = i;
        temp = f;

        for (i=1; ; ++i)
        {
            if (f.num[k-1] == 7)
            {
                break;
            }
            else
            {
                temp = f;
                f = Mul(temp, t);
            }
        }

        cout << i << endl;
    }

    return 0;
}
