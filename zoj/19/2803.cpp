#include<stdio.h>
#include<memory.h>

#define MaxN 101

struct robot
{
    int x;
    int y;
    char dir;
}f[MaxN];

char d[4] = {'N', 'W', 'S', 'E'};
int graph[MaxN][MaxN];

int main(void)
{
    int i;
    int j;
    int k;
    int m;
    int n;
    int OK;
    int Wall;
    int Rob;
    int A;
    int B;
    int repeat;
    int test_case;
    int num;
    int src;
    int dst;
    char order;

    scanf("%d", &test_case);

    for (k=0; k<test_case; ++k)
    {
        scanf("%d %d", &A, &B);
        scanf("%d %d", &n, &m);
        memset(graph, 0, sizeof(graph));

        for (i=1; i<=n; ++i)
        {
            scanf("%d %d %c", &f[i].y, &f[i].x, &f[i].dir);
            graph[f[i].x][f[i].y] = i;
        }

        OK = 1;
        Wall = 0;
        Rob = 0;

        for (i=0; i<m; ++i)
        {
            scanf("%d %c %d", &num, &order, &repeat);

            if (OK == 1)
            {
                if (order == 'F')
                {
                    if (f[num].dir == 'N')
                    {
                        for (j=f[num].x+1; (j<=f[num].x+repeat)&&(j<=B); ++j)
                        {
                            if ((graph[j][f[num].y] != 0) && (OK == 1))
                            {
                                OK = 0;
                                Rob = 1;
                                src = num;
                                dst = graph[j][f[num].y];
                            }
                        }

                        if (OK == 1)
                        {
                            if (f[num].x + repeat > B)
                            {
                                OK = 0;
                                Wall = 1;
                                src = num;
                            }

                            if (OK == 1)
                            {
                                graph[f[num].x+repeat][f[num].y] = num;
                                graph[f[num].x][f[num].y] = 0;
                                f[num].x += repeat;
                            }
                        }

                    }
                    else if (f[num].dir == 'W')
                    {
                        for (j=f[num].y-1; (j>=f[num].y-repeat)&&(j>=1); --j)
                        {
                            if ((graph[f[num].x][j] != 0) && (OK == 1))
                            {
                                OK = 0;
                                Rob = 1;
                                src = num;
                                dst = graph[f[num].x][j];
                            }
                        }

                        if (OK == 1)
                        {
                            if (f[num].y - repeat <= 0)
                            {
                                OK = 0;
                                Wall = 1;
                                src = num;
                            }
                            if (OK == 1)
                            {
                                graph[f[num].x][f[num].y-repeat] = num;
                                graph[f[num].x][f[num].y] = 0;
                                f[num].y -= repeat;
                            }
                        }
                    }
                    else if (f[num].dir == 'S')
                    {
                        for (j=f[num].x-1; (j>=f[num].x-repeat)&&(j>=1); --j)
                        {
                            if ((graph[j][f[num].y] != 0) && (OK == 1))
                            {
                                OK = 0;
                                Rob = 1;
                                src = num;
                                dst = graph[j][f[num].y];
                            }
                        }

                        if (OK == 1)
                        {
                            if (f[num].x - repeat <= 0)
                            {
                                OK = 0;
                                Wall = 1;
                                src = num;
                            }
                            if (OK == 1)
                            {
                                graph[f[num].x-repeat][f[num].y] = num;
                                graph[f[num].x][f[num].y] = 0;
                                f[num].x -= repeat;
                            }
                        }
                    }
                    else
                    {
                        for (j=f[num].y+1; (j<=f[num].y+repeat)&&(j<=A); ++j)
                        {
                            if ((graph[f[num].x][j] != 0) && (OK == 1))
                            {
                                OK = 0;
                                Rob = 1;
                                src = num;
                                dst = graph[f[num].x][j];
                            }
                        }

                        if (OK == 1)
                        {
                            if (f[num].y + repeat > A)
                            {
                                OK = 0;
                                Wall = 1;
                                src = num;
                            }
                            if (OK == 1)
                            {
                                graph[f[num].x][f[num].y+repeat] = num;
                                graph[f[num].x][f[num].y] = 0;
                                f[num].y += repeat;
                            }
                        }
                    }
                }
                else if (order == 'L')
                {
                    for (j=0; j<4; ++j)
                    {
                        if (f[num].dir == d[j])
                        {
                            break;
                        }
                    }

                    f[num].dir = d[(j+repeat)%4];
                }
                else
                {
                    for (j=0; j<4; ++j)
                    {
                        if (f[num].dir == d[j])
                        {
                            break;
                        }
                    }

                    f[num].dir = d[((j-repeat)%4+4)%4];
                }
            }
        }

        if (OK == 1)
        {
            printf("OK\n");
        }
        else if (Wall == 1)
        {
            printf("Robot %d crashes into the wall\n", src);
        }
        else if (Rob == 1)
        {
            printf("Robot %d crashes into robot %d\n", src, dst);
        }
    }

    return 0;
}
