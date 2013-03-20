#include <cstdio>
using namespace std;

bool gaoding(int a, const int &lim, int &d)
{
    int x(a);
    int i;
    for (i=1; i<=lim; ++i)
    {
        if (x % lim == 0)
        {
            d = i;
            return true;
        }
        x *= 10;
        x += a;
        x %= lim;
    }
    return false;
}

void gao(const int &n)
{
    int i;
    int d;
    for (i=1; i<=9; ++i)
        if (gaoding(i, n, d))
        {
            printf("%d %d\n", i, d);
            return;
        }
    printf("-1\n");
    return;
}

int main()
{
    int n;
    while (scanf("%d", &n) != EOF) gao(n);
    return 0;
}
