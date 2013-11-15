#include <cstdio>
#include <cmath>
using namespace std;
__int64 gcd(__int64 a, __int64 b)
{
    __int64 m = 1;
    while (m != 0)
    {
        m = a % b;
        a = b;
        b = m;
    }
    return a;
}

__int64 exp_gcd(__int64 a, __int64 b, __int64 &x, __int64 &y)
{
    __int64 q;
	__int64 temp;
    if (b == 0)
    {
        q = a;
        x = 1;
        y = 0;
        return q;
    }
    else
    {
        q = exp_gcd(b, a % b, x, y);
        temp = x;
        x = y;
        y = temp - (a / b) * y;
        return q;
    }
}

__int64 a, b, c, d, k, w, x, y, A, B, C, X, Y;
__int64 f[100];
int main()
{
	//freopen("f:\\in.txt", "r", stdin);
	//freopen("f:\\ans1.txt", "w", stdout);
    while (scanf("%I64d %I64d %I64d %I64d", &a, &b, &c, &k)!=EOF)
    {
        if (!a && !b && !c && !k)
            break;
        if (a == b)
        {
            printf("0\n");
            continue;
        }
        if (c == 0)
        {
            printf("FOREVER\n");
            continue;
        }

        A = (__int64)1 << k;
        B = c;
        C = b - a;

        d = gcd(A, B);

        if (C % d)
        {
            printf("FOREVER\n");
            continue;
        }
        A /= d;
        B /= d;
        C /= d;

        exp_gcd(A, B, x, y);

        Y =  C * y;
        if (Y <= 0)
        {
            Y += (1 + (-Y)/A) * A;
        }
        
        Y %= A;
        if (Y == 0)
            Y = A;
            
        printf("%I64d\n",Y);
    }
    return 0;
}
