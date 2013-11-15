#include<stdio.h>

#define MaxN 20

int x;
int y;
int dx[4] = {-1, 0, 1, 1};
int dy[4] = {1, 1, 1, 0};
int game[MaxN][MaxN];

int border(int x, int y)
{
    if ((x >= 1) && (x < 20) && (y >= 1) && (y < 20))
    {
        return 1;
    }

    return 0;
}

int judge()
{
    int i;
    int j;
    int k;
    int c;
    int tx;
    int ty;
    int cnt;

    for (j=1; j<20; ++j)
    {
        for (i=1; i<20; ++i)
        {
            if (game[i][j] != 0)
            {
                c = game[i][j];
                x = i;
                y = j;

                for (k=0; k<4; ++k)
                {
                    if (!border(x-dx[k], y-dy[k]) || 
					     (border(x-dx[k], y-dy[k]) && game[x-dx[k]][y-dy[k]] != c))
                    {
                        cnt = 1;
                        tx = x;
                        ty = y;

                        while (cnt <= 6)
                        {
                            tx += dx[k];
                            ty += dy[k];
                            if (border(tx, ty) && (game[tx][ty] == c))
                            {
                                ++cnt;
                            }
                            else
                            {
                                break;
                            }
                        }

                        if (cnt == 5)
                        {
                            return c;
                        }
                    }
                }
            }
        }
    }

    return 0;
}

int main(void)
{
    int i;
    int j;
    int k;
    int win;
    int test_case;

    scanf("%d", &test_case);

    for (k=0; k<test_case; ++k)
    {
        for (i=1; i<20; ++i)
        {
            for (j=1; j<20; ++j)
            {
                scanf("%d", &game[i][j]);
            }
        }

        win = judge();

        printf("%d\n", win);

        if (win)
        {
            printf("%d %d\n", x, y);
        }
    }

    return 0;
}
