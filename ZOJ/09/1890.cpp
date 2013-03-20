#include<stdio.h>

#define MaxL 20

char msg[MaxL];

int main(void)
{
    int i;
    int j;
    int len;
    double h[2];
    double m[2];
    double s[2];
    double speed;
    double cur_dis;
    double dis;
    double time;

	h[0] = h[1] = m[0] = m[1] = s[0] = s[1] = 0.0;
    speed = 0.0;
    dis = 0.0;

    while (gets(msg) != 0)
    {
        len = strlen(msg);

        h[1] = (msg[0] - '0') * 10.0 + msg[1] - '0';
		m[1] = (msg[3] - '0') * 10.0 + msg[4] - '0';
    	s[1] = (msg[6] - '0') * 10.0 + msg[7] - '0';
        time = h[1] - h[0] + (m[1] - m[0]) / 60.0 + (s[1] - s[0]) / 3600.0;

        if (len > 8)
        {
            dis += time * speed;
            h[0] = h[1];
            m[0] = m[1];
            s[0] = s[1];
            speed = 0.0;
            
            for (i=9; i<len; ++i)
            {
                speed = speed * 10.0 + msg[i] - '0';
            }
        }
        else
        {
            cur_dis = dis + time * speed;
            printf("%s %.2lf km\n", msg, cur_dis);
        }
    }

    return 0;
}
