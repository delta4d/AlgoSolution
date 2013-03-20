#include<stdio.h>

char f[200];

int main(void)
{
    int i;
    int j;
    int k;
    int n;
    int team_number;
    int valid;
    int len;
    int rm;
    int rs;
    double temp;
    double d;
    double h;
    double m;
    double s;
    double total;
    double avg;

    scanf("%d %lf", &n, &d);
    getchar();

    while (scanf("%d", &team_number) && gets(f))
    {
        len = strlen(f);

        valid = 1;
        h = m = s = 0;
        k = 0;
        temp = 0;

        for (i=0; i<len; ++i)
        {
            if (f[i] == '-')
            {
                valid = 0;
                break;
            }

            if (f[i] == ':' || f[i] == ' ')
            {
                if (k == 0)
                {
                    h += temp;
                }
                else if (k == 1)
                {
                    m += temp;
                }
                else
                {
                    s += temp;
                }

                if (f[i] == ' ')
                {
                    k = 0;
                    temp = 0;
                    continue;
                }

                temp = 0;
                ++k;
                continue;
            }

            temp = temp * 10 + f[i] - '0';
        }

		s += temp;

        if (valid == 1)
        {
            total = h * 60.0 + m + s / 60.0;

            avg = total / d;

            rm = avg;
            rs = (avg - (double)rm) * 60.0 + 0.5;

            printf("%3d: %d:%d min/km\n", team_number, rm, rs);
        }
        else
        {
            printf("%3d: -\n", team_number);
        }
    }

    return 0;
}
