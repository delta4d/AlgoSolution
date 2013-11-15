#include<iostream>
#include<cstdio>
#include<memory>

struct Q
{
    int a[4];
    int d;
}f[10000];

bool h[10][10][10][10];
int dx[2] = {1, -1};
int res;
Q src;
Q dst;

void bfs()
{
    int i;
    int j;
    int temp;
    int front = 0;
    int rear = 0;
    bool find;
    struct Q c;
    struct Q t;

    memset(h, false, sizeof(h));

    c = src;

    for (i=0; i<4; ++i)
    {
        find = true;
        if (c.a[i] != dst.a[i])
        {
            find = false;
            break;
        }
    }

    while (!find)
    {
        for (i=0; i<4; ++i)
        {
            for (j=0; j<2; ++j)
            {
                t = c;

                t.a[i] = (t.a[i] + 8 + dx[j]) % 9 + 1;
                t.d = c.d + 1;

                if (!h[t.a[0]][t.a[1]][t.a[2]][t.a[3]])
                {
                    f[rear] = t;
                    ++rear;
                    h[t.a[0]][t.a[1]][t.a[2]][t.a[3]] = true;
                }
            }
        }

        for (i=0; i<3; ++i)
        {
            t = c;

            temp = t.a[i];
            t.a[i] = t.a[i+1];
            t.a[i+1] = temp;
            t.d = c.d + 1;

            if (!h[t.a[0]][t.a[1]][t.a[2]][t.a[3]])
            {
                f[rear] = t;
                ++rear;
                h[t.a[0]][t.a[1]][t.a[2]][t.a[3]] = true;
            }
        }

        c = f[front];
        ++front;

        for (i=0; i<4; ++i)
        {
            find = true;
            if (c.a[i] != dst.a[i])
            {
                find = false;
                break;
            }
        }
    }

    res = c.d;
}

int main(void)
{
    int i;
    int k;
    int n;
    char ch;
    char s1[5];
    char s2[5];

    scanf("%d", &n);
    ch = getchar();

    for (k=0; k<n; ++k)
    {
        scanf("%s %s", s1, s2);

        for (i=0; i<4; ++i)
        {
            src.a[i] = s1[i] - '0';
            dst.a[i] = s2[i] - '0';
        }

        src.d = dst.d = 0;

        bfs();

        printf("%d\n", res);
    }

    return 0;
}
