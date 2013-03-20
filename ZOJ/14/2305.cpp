#include <cstdio>
typedef long long LL;
using namespace std;

LL gao(LL a, LL b, LL &x, LL &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    LL res = gao(b, a%b, x, y);
    LL t = x;
    x = y;
    y = t - (a / b) * y;
    return res;
}

int main()
{
    LL A;
    LL B;
    LL C;
    LL k;
    LL a;
    LL b;
    LL c;
    LL t;
    LL x;
    LL y;
    LL gcd;

	//freopen("f:\\in.txt", "r", stdin);
	//freopen("f:\\ans2.txt", "w", stdout);

    scanf("%lld %lld %lld %lld", &A, &B, &C, &k);

    while (A != 0 || B != 0 || C != 0 || k != 0)
    {
        if (A == B)
        {
            puts("0");
        }
        else if (C == 0)
        {
            puts("FOREVER");
        }
        else
        {
            a = C;
            b = 1ll << k;
            gcd = gao(a, b, x, y);
            if ((B - A) % gcd != 0)
            {
                puts("FOREVER");
            }
            else
            {
                LL cc = b / gcd;
                LL dd = (A - B) / gcd * x;
                t = dd / cc;
                LL res = -dd + cc * t;
                if (res < 0) res += cc;
                printf("%lld\n", res);
            }
        }

        scanf("%lld %lld %lld %lld", &A, &B, &C, &k);
    }

    return 0;
}
