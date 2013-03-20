#include<cstdio>

int main(void)
{
    int s;
    int p;
    int y;
    int d;
    int a;
    int b;
    int c;

    while (scanf("%d %d %d %d", &s, &p, &y, &d) != EOF)
    {
        if ((p + d - s + 12) % 3 == 0)
        {
            if (s + p == y)
            {
                b = (p + d - s + 12) / 3;
                a = s + b;
                c = b - p;
            }
            else
            {
                b = (p + d - s + 12) / 3;
                a = s + b + 1;
                c = b - p - 1;
            }
        }
        else if ((p + d - s + 12) % 3 == 1)
        {
            b = (p + d - s + 11) / 3;
            a = s + b + 1;
            c = b - p;
        }
        else
        {
            b = (p + d - s + 13) / 3;
            a = s + b;
            c = b - p - 1;
        }

        printf("%d %d %d\n", a, b, c);
    }

    return 0;
}
