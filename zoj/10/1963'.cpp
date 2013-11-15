#include<stdio.h>

char f[10];

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

    while (scanf("%d", &team_number) != EOF)
    {
        h = 0;
        m = 0;
        s = 0;

        for (i=0; i<n; ++i)
        {
            scanf("%s", f);
            len = strlen(f);
            temp = 0;

            for (j=0; j<len; ++j)
            {
                if (f[i] == '-')
                {
                    valid = 0;
                    break;
                }

                if (valid == 1)
                {
                    if (f[i] == ':')
                    {
                        if (k == 0)
                        {
                            h += temp;
                            ++k;
                        }
                        else
                        {
                            m += temp;
                        }

                        temp = 0;
                    }
                }
            }

            s += temp;
        }
        
        if (valid == 1)
        {
        	total = h * 360 + m * 60 + s;
			
			avg = total / d;
			
			rs = (avg - (int)avg) * 100;
			rm = (int)(avg - (double)rs / 100.0) % 60;
			
			printf("%3d: %d:%d min/km\n", rm, rs); 
		}
		else
		{
			printf("%3d: -\n");
		}
    }

    return 0;
}
